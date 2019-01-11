const Sequelize = require('sequelize');
const db = require('../database');

var owprofile = db.define('owprofile', {
    ownerid: { type: Sequelize.STRING, primaryKey: true },
    battletag: { type: Sequelize.STRING, primaryKey: true },
    platform: { type: Sequelize.STRING, allowNull: false },
    region: { type: Sequelize.STRING, allowNull: false },
    guildid: { type: Sequelize.STRING, allowNull: false }
});

module.exports = owprofile;