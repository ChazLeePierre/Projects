const Commando = require('discord.js-commando');
const axios = require('axios');
const db = require('../../database');
const owprofile = require("../../models/owprofile");
const OverwatchRanks = require("../../assets/overwatchranks");
const verifyAvatar = require('../../assets/verifyAvatar');

class link extends Commando.Command {
    constructor(client) {
        super(client, {
            name: 'link',
            group: 'overwatch',
            memberName: 'link',
            description: 'Links Overwatch stats to Discord',
            throttling: { usages: 2, duration: 10 },
            args: [
                {
                    key: 'platform',
                    label: 'platform',
                    type: 'string',
                    prompt: 'What platform do you play on?',
                    default: 'pc',
                    oneOf: ['pc', 'xbl', 'psn']
                },
                {
                    key: 'region',
                    label: 'region',
                    type: 'string',
                    prompt: 'What region do you play in?',
                    default: 'us',
                    oneOf: ['us', 'eu', 'asia']
                },
                {
                    key: 'battletag',
                    label: 'battletag',
                    type: 'string',
                    prompt: 'What is your Blizzard battletag?'
                }
            ]
        });

    }

    /* setRank: Finds/creates roles and checks what role the user belongs to based on their rating, and returns that role. */
    async setRank(msg, rating) {
        let roles = {};
        let rank;

        // Find role, or create new if role does not exist
        let findOrCreate = async function (msg, rankname, rankcolor, rankposition) {
            let rank = msg.guild.roles.find(element => { return element.name === rankname; })
            if (!rank) { // If role is undefined, role does not exist
                rank = await msg.guild.createRole({
                    name: rankname,
                    hoist: true,
                    color: rankcolor,
                    position: rankposition,
                    permissions: 104193345,
                    mentionable: false
                }).catch(err => { console.error(err) });
            } return rank;
        };

        // Populate the roles object
        for (let i = 0; i < OverwatchRanks.length; i++)
            roles[OverwatchRanks[i][0]] = {
                role: findOrCreate(msg, OverwatchRanks[i][0], OverwatchRanks[i][1], i + 1),
                color: OverwatchRanks[i][1],
                emoji: OverwatchRanks[i][2]
            };

        // Determine what role user belongs in based off their Skill Rating
        switch (true) {
            case (rating >= 1 && rating <= 1499): rank = { rankdata: OverwatchRanks[0], promise: roles.Bronze }; break;
            case (rating >= 1500 && rating <= 1999): rank = { rankdata: OverwatchRanks[1], promise: roles.Silver }; break;
            case (rating >= 2000 && rating <= 2499): rank = { rankdata: OverwatchRanks[2], promise: roles.Gold }; break;
            case (rating >= 2500 && rating <= 2999): rank = { rankdata: OverwatchRanks[3], promise: roles.Platinum }; break;
            case (rating >= 3000 && rating <= 3499): rank = { rankdata: OverwatchRanks[4], promise: roles.Diamond }; break;
            case (rating >= 3500 && rating <= 3999): rank = { rankdata: OverwatchRanks[5], promise: roles.Master }; break;
            case (rating >= 4000): rank = { rankdata: OverwatchRanks[6], promise: roles.Grandmaster }; break;
        }

        // Return a Promise<rank> (contains {rankdata array, and a Promise<Role> object) to be dealt with in checkForExistingBattletag()
        return rank;
    }

    /* checkForExistingBattletag: Checks the database to see if the user already has a Battletag linked to their account.
    If the Battletag the user specified is not already linked to someone else's ID, their information will be updated/created
    in the database. The function will then execute the Promise from setRank(), and add the role to the user while removing any 
    other conflicting role.*/
    checkForExistingBattletag(identifier, args, msg, res) {
        owprofile.findOne({ where: { battletag: args.battletag } }).then(existingbattletag => {
            this.setRank(msg, res.data.rating).then(data => { // Execute the Promise<rank>

                // Check the database if the Battletag already belongs to another user
                if (existingbattletag && existingbattletag.ownerid !== msg.author.id) {
                    msg.channel.send(`**${args.battletag}** is already linked to **<@${existingbattletag.ownerid}>**.`);
                } else { // Otherwise, create/update (identifier recieved from run() function) the Battletag and link it to the user ID of the Discord user
                    if (identifier == 'UPDATE')
                        owprofile.update({ platform: args.platform, region: args.region, battletag: args.battletag, guildid: msg.guild.id }, { where: { ownerid: msg.author.id } })
                            .then(() => { msg.channel.send(`**${msg.author.username}** already has a Battletag linked. Your Battletag has been updated to **${res.data.name}**. Rank **${data.rankdata[0]}** [${data.rankdata[2]}] has been applied.`); })
                            .catch((err) => { console.error(err); msg.channel.send(`**${msg.author.username}** already has a Battletag linked. I attempted to update your profile, but something went wrong.`) });
                    else if (identifier == 'CREATE')
                        owprofile.create({ ownerid: msg.author.id, platform: args.platform, region: args.region, battletag: args.battletag, guildid: msg.guild.id })
                            .then(() => { msg.channel.send(`Congrats! **${res.data.name}** has been successfully linked to ${msg.author.username}. Rank **${data.rankdata[0]}** [${data.rankdata[2]}] has been applied.`); })
                            .catch((err) => { console.log(err); msg.channel.send(`**${res.data.name}** failed to be linked to ${msg.author.username}.`) });
                }

                // Add the new role and remove any previous rank roles
                data.promise.role.then(newrole => { // Execute the Promise<Role> object
                    msg.member.addRole(newrole.id).catch(console.error);
                    if (msg.member.roles) {
                        OverwatchRanks.forEach(r => {
                            let role = msg.guild.roles.find(element => { return element.name === r[0]; });
                            if (msg.member.roles.has(role.id) && (role.id != newrole.id))
                                msg.member.removeRole(role.id).catch(console.error);
                        });
                    }
                });
            });
        }).catch(err => { console.error(err); });
    }

    async verifyProfile(msg, res, args, profile) {
        if (res.data.icon === verifyAvatar[0].url && profile.battletag === args.battletag) {
            return 'VERIFY';
        } else {
            let verify_duration = 15;
            let response_duration = 30;
            msg.channel.send(`Hey **${msg.author.username}**, I need to verify you own the Battletag, **${args.battletag}**. Please login to your Overwatch account and set your Overwatch avatar to **${verifyAvatar[0].key}** [ <:${verifyAvatar[0].key}:${verifyAvatar[0].emoji}> ].`);
            msg.channel.send(`Within ${response_duration} seconds, reply with '*start*' once you have updated your Overwatch avatar to initiate the verification. If you do not have access to your account right now, reply with '*exit*' to terminate the link command and try again when you are ready. *This process will take about ${verify_duration} minutes*.`);
            const response = await msg.channel.awaitMessages(response => response.content.toLowerCase() === 'start' || response.content.toLowerCase() === 'exit', { max: 1, time: response_duration * 1000 });
            console.log(response.first().content.toLowerCase());
            if (response && response.first().content.toLowerCase() === 'start') {
                return await msg.channel.send(`Initiating verification... ${verify_duration} minutes remaining...`).then(async sentMessage => {
                    return await new Promise(resolve => {
                        verify_duration--;
                        var minutes;
                        var interval = setInterval(function () {
                            minutes = parseInt(verify_duration, 10);
                            sentMessage.edit(`${minutes} minutes remaining...`);
                            if (--verify_duration < 0) {
                                clearInterval(interval);
                                resolve(axios.get(`https://ovrstat.com/stats/${args.platform}/${args.region}/${args.battletag.replace('#', '-')}`));
                            }
                            console.log(verify_duration);
                        }, 60 * 100) // FIXME: set to 1000 on release
                    });
                })
            } else if (response && response.first().content.toLowerCase() === 'exit') {
                return 'EXIT';
            }
        }
    }

    async run(msg, args) {
        let this_object = this; // Must specify the value of this outside the .then() call because the value of this changes inside .then()
        return axios.get(`https://ovrstat.com/stats/${args.platform}/${args.region}/${args.battletag.replace('#', '-')}`).then(res => {
            db.sync().then(function () { // Ensure DB is up to date
                owprofile.findOne({ where: { ownerid: msg.author.id } })
                    .then(async profile => {
                        if (profile)
                            await this_object.verifyProfile(msg, res, args, profile).then(updatedres => {
                                console.log(updatedres);
                                if (updatedres === 'EXIT') {
                                    msg.channel.send(`Unfortunately **${msg.author.username}**, I wasn't able to link your account. Please try again another time.`);
                                } else {
                                    if (updatedres === 'VERIFY' || updatedres.data.icon === verifyAvatar[0].url) {
                                        msg.channel.send(`Success! Your Overwatch account, **${args.battletag}**, has been verified. *You may now change your Overwatch avatar back to whatever you\'d like*.`);
                                        this_object.checkForExistingBattletag('UPDATE', args, msg, res);
                                    } else {
                                        msg.channel.send(`My data shows me **${args.battletag}**'s Overwatch avatar has not been set to **${verifyAvatar[0].key}** [ <:${verifyAvatar[0].key}:${verifyAvatar[0].emoji}> ]. I'm unable to verify your Overwatch account at this time.`);
                                    }
                                }
                            }).catch((err) => { console.error(err); });
                        else {
                            await this_object.verifyProfile(msg, res, args, profile).then(updatedres => {
                                if (updatedres === 'EXIT') {
                                    msg.channel.send(`Unfortunately **${msg.author.username}**, I wasn't able to link your account. Please try again another time.`);
                                } else {
                                    if (updatedres === 'VERIFY' || updatedres.data.icon === verifyAvatar[0].url) {
                                        msg.channel.send(`Success! Your Overwatch account, **${args.battletag}**, has been verified. *You may now change your Overwatch avatar back to whatever you\'d like*.`);
                                        this_object.checkForExistingBattletag('CREATE', args, msg, res);
                                    } else {
                                        msg.channel.send(`My data shows me **${args.battletag}**'s Overwatch avatar has not been set to **${verifyAvatar[0].key}** [ <:${verifyAvatar[0].key}:${verifyAvatar[0].emoji}> ]. I'm unable to verify your Overwatch account at this time.`);
                                    }
                                }
                            }).catch((err) => { console.error(err); });
                        }
                    });
            });
        }).catch((err) => { console.error(err); msg.channel.send(`Uh-oh! It seems like **${args.battletag}** doesn't have any Overwatch data! Double check the Battletag you entered.`); })
    }
};

// TODO: Leaderboard
// TODO: Insult users with common phrases.

module.exports = link;