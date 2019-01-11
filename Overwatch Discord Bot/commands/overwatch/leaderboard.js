const Commando = require('discord.js-commando');
const axios = require('axios');
const db = require('../../database');
const owprofile = require("../../models/owprofile");
const OverwatchRanks = require("../../assets/overwatchranks");


class leaderboard extends Commando.Command {
    constructor(client) {
        super(client, {
            name: 'leaderboard',
            group: 'overwatch',
            memberName: 'leaderboard',
            description: 'Links Overwatch stats to Discord',
            throttling: { usages: 2, duration: 10 },
            args: [{ key: 'flag', label: 'flag', type: 'string', prompt: 'Current guild only (__-g__) or everyone (__-e__)?', oneOf: ['-g', '-e'] }]
        });
    }

    async run(msg, args) {
        db.sync().then(function () { // Ensure DB is up to date
            owprofile.findAndCoundAll({ where: { guildid: msg.guild.id } })
        })

    }
};

// TODO: Leaderboard
// TODO: Insult users with common phrases.

module.exports = leaderboard;