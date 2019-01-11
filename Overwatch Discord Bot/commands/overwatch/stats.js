const Commando = require('discord.js-commando');
const { RichEmbed } = require('discord.js');
const db = require('../../database');
const owprofile = require("../../models/owprofile");
const axios = require('axios');
const TimeFormat = require('hh-mm-ss');

class stats extends Commando.Command {
    constructor(client) {
        super(client, {
            name: 'stats',
            group: 'overwatch',
            memberName: 'stats',
            description: 'Displays Overwatch stats',
            args: [{ key: 'mode', label: 'mode', type: 'string', prompt: 'Quickplay (__-q__) or Competitive (__-c__)?', oneOf: ['-q', '-c'] }]
        });
    }
    calculateHighestPlayedCharacter(mode, stats) {
        // Determine Quickplay or Competitive
        let heroes = Object.entries((mode == '-q') ? stats.data.quickPlayStats.topHeroes : stats.data.competitiveStats.topHeroes);
        let tophero = heroes[0];
        // Find the hero with the greatest time played
        for (let i = 0; i < heroes.length; i++) {
            if (TimeFormat.toS(heroes[i][1].timePlayed) > TimeFormat.toS(tophero[1].timePlayed))
                tophero = heroes[i];
        }
        // Split HH:MM:SS string into an array
        tophero[1].timePlayed = tophero[1].timePlayed.split(':');
        // If timeplayed string is only MM:SS, add 0 to HH value
        if (tophero[1].timePlayed.length < 3)
            tophero[1].timePlayed.unshift('00');
        // Return name [0] | timeplayed array [1]
        return tophero;
    }

    async run(msg, args) {
        let stats_object = this;
        db.sync().then(function () { // Ensure DB is up to date
            owprofile.findOne({ where: { ownerid: msg.author.id } })
                .then(data => {
                    axios.get(`https://ovrstat.com/stats/${data.platform}/${data.region}/${data.battletag.replace('#', '-')}`).then(stats => {
                        // Determine Quickplay or Competitive
                        let prefix = (args.mode === '-q') ? stats.data.quickPlayStats : stats.data.competitiveStats;
                        // Calculate most played hero
                        let tophero = stats_object.calculateHighestPlayedCharacter(args.mode, stats);
                        // Create the RichEmbed object
                        const embed = new RichEmbed()
                            .setTitle(`${msg.author.username} (${stats.data.name})'s Overwatch Stats [${(args.mode === '-q') ? 'Quickplay' : 'Competitive'}]`)
                            .setThumbnail(stats.data.icon)
                            .setColor(msg.member.highestRole.hexColor)
                            .addField('General Information',
                                `**Battletag**: ${stats.data.name}
                                **Prestige**: ${stats.data.prestige} **Level**: ${stats.data.level}
                                **Endorsement**: ${stats.data.endorsement}
                                **Rank**: ${msg.member.highestRole.name} **Skill Rating**: ${stats.data.rating}
                                **Is Profile Private?**: ${stats.data.private.toString().charAt(0).toUpperCase() + stats.data.private.toString().slice(1).toLowerCase()}`)
                            .addField('Most Played Hero',
                                `**${msg.author.username}** mains **${tophero[0].charAt(0).toUpperCase() + tophero[0].slice(1).toLowerCase()}** in ${(args.mode === '-q') ? 'Quickplay' : 'Competitive'}
                                with **${tophero[1].timePlayed[0]}** hours, **${tophero[1].timePlayed[1]}** minutes, and **${tophero[1].timePlayed[2]}** seconds on record.`, true)
                            .addField('Combat',
                                `**Most Solo Kills in a Game**: ${prefix.careerStats.allHeroes.best.soloKillsMostInGame}
                                **Total Solo Kills**: ${prefix.careerStats.allHeroes.combat.soloKills} **__K__ill/__D__eath Ratio**: ${(prefix.careerStats.allHeroes.combat.soloKills / prefix.careerStats.allHeroes.combat.deaths).toFixed(2)}
                                **Most Eliminations in a Game**: ${prefix.careerStats.allHeroes.best.eliminationsMostInGame}
                                **Total Eliminations**: ${prefix.careerStats.allHeroes.combat.eliminations} **__E__limination/__D__eath Ratio**: ${(prefix.careerStats.allHeroes.combat.eliminations / prefix.careerStats.allHeroes.combat.deaths).toFixed(2)}
                                **Total Deaths**: ${prefix.careerStats.allHeroes.combat.deaths} 
                                **Most Healing in a Game**: ${prefix.careerStats.allHeroes.best.healingDoneMostInGame}
                                **Total Healing**: ${prefix.careerStats.allHeroes.assists.healingDone}
                                **Most Hero Damage in a Game**: ${prefix.careerStats.allHeroes.best.heroDamageDoneMostInGame}
                                **Total Hero Damage**: ${prefix.careerStats.allHeroes.combat.heroDamageDone}
                                **Most Time Spent on Fire in a Game**: ${prefix.careerStats.allHeroes.best.timeSpentOnFireMostInGame} __(HH:MM:SS)__
                                **Total Time Spent on Fire**: ${prefix.careerStats.allHeroes.combat.timeSpentOnFire} __(HH:MM:SS)__
                                **Greatest Killstreak**: ${prefix.careerStats.allHeroes.best.killsStreakBest}
                                **Greatest Multikill**: ${prefix.careerStats.allHeroes.best.multikillsBest}
                                **Total Multikills**: ${prefix.careerStats.allHeroes.combat.multikills}`, true)
                            .addField('Games',
                                `**Total Games Won**: ${prefix.careerStats.allHeroes.game.gamesWon}
                                **Total Time Played**: ${prefix.careerStats.allHeroes.game.timePlayed} __(HH:MM:SS)__`, true)
                            .addField('Match Awards',
                                `**Total Cards**: ${prefix.careerStats.allHeroes.matchAwards.cards}
                                **Total Medals**: ${prefix.careerStats.allHeroes.matchAwards.medals}
                                **Bronze Medals**: ${prefix.careerStats.allHeroes.matchAwards.medalsBronze}
                                **Silver Medals**: ${prefix.careerStats.allHeroes.matchAwards.medalsSilver}
                                **Gold Medals**: ${prefix.careerStats.allHeroes.matchAwards.medalsGold}`, true)
                        // Send the RichEmbed object
                        msg.channel.send(embed);
                })
                .catch(err => { console.error(err) });
        }).catch(err => { console.error(err) });
    });
}
};

module.exports = stats;
