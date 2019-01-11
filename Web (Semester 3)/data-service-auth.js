var exports = module.exports = {};
var mongoose = require('mongoose');
var bcrypt = require('bcryptjs');
var Schema = mongoose.Schema;
let User; // to be defined on new connection (see initialize)
var userSchema = new Schema ({
    "userName": { "type": String, "unique": true },
    "password": String,
    "email": String,
    "loginHistory": [{ "dateTime": Date, "userAgent": String }]
});

exports.initialize = function() {
    return new Promise((resolve, reject) => {
        let db = mongoose.createConnection("mongodb://Administrator:Dialga404@ds249798.mlab.com:49798/web322_a6");
        db.on('error', (err)=>{
            reject(err);
        });
        db.once('open', ()=>{
           User = db.model("users", userSchema);
           resolve();
        });
    });
};

exports.registerUser = function (user) {
    return new Promise((resolve, reject) => {
        if (user.password != user.password2) 
            reject('Error: Passwords do not match.');
        else {
            bcrypt.genSalt(10, function (err, salt) {
                bcrypt.hash(user.password, salt, function (err, hash) {
                    if (err)
                        reject('Error: Could not encrypt the password');
                    else {
                        user.password = hash;
                        let newUser = new User(user);
                        newUser.save((err) => {
                            if (err) {
                                if (err.code == 11000)
                                    reject("User Name already taken");
                                reject("There was an error creating the user: " + err);
                            }
                            else
                                resolve();
                        });
                    }
                });
            })
        }
    });
};

exports.checkUser = function(user) {
    return new Promise((resolve, reject) => {
        User.find({ userName: user.userName })
            .exec().then((users) => {
                if (!users)
                    reject(`Unable to find user: ${user.userName}`);
                else {
                    bcrypt.compare(user.password, users[0].password).then((res) => {
                        if (res) {
                            users[0].loginHistory.push({dateTime: (new Date()).toString(), userAgent: user.userAgent});
                            User.update(
                                { userName: users[0].userName },
                                { $set: { loginHistory: users[0].loginHistory }},
                                { multi: false }
                            ).exec().then((() => {
                                resolve(users[0]);
                            })).catch((err) => {
                                reject(`There was an error verifying the user: ${err}`);
                            });
                        } else
                            reject(`Incorrect Password for user: ${user.userName}`);
                    })
                }
            }).catch(() => {
                reject(`Unable to find user: ${user.userName}`);
            })
    });
}