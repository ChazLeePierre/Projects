var Sequelize = require('sequelize');

module.exports = new Sequelize('darv212ivgl12e', 'vfpsgpgxzwzjdm', '61ebc26090fba7f7c33e4d95a5f57759d40aa436f3b2cc598ab2a56c01891f2f', {
    host: 'ec2-23-21-122-141.compute-1.amazonaws.com',
    dialect: 'postgres',
    port: 5432,
    dialectOptions: {
        ssl: true
    }
});
