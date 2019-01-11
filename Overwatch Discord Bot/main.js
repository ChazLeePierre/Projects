const Commando = require('discord.js-commando');
const path = require('path');
const bot_token = 'NDc3MjcyNzg0NjM3MjYzODk3.Dvl26g.La-oLrJD9hp0ORImQpk_14FllQg';
const db = require('./database');
const bot = new Commando.Client({
    owner: '286351654624821250',
    commandPrefix: 'r!',
    unknownCommandResponse: false
});

bot.registry
    .registerGroup('overwatch', 'Overwatch')
    .registerDefaults()
    .registerCommandsIn(path.join(__dirname, 'commands'));

bot.on('ready', () => {
    console.log(`${bot.user.tag} is now online.`);
});



bot.login(bot_token);

db.authenticate()
    .then(function () { console.log('Connection has been established successfully.'); })
    .catch(function (err) { console.log('Unable to connect to the database:', err); });
