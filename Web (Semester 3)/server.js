/*********************************************************************************
WEB322 – Assignment 06
I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part
of this assignment has been copied manually or electronically from any other source 
(including 3rd party web sites) or distributed to other students.

Name: Chaz-lee Pierre Student ID: 123206179 Date: December 7 2018

Online (Heroku) Link: https://web322a6-chazleepierre.herokuapp.com/

********************************************************************************/

var data_service = require("./data-service.js");
var express = require("express");
var app = express();
var path = require("path");
var PORT_listen = process.env.PORT || 8080;
var multer = require("multer");
var bodyParser = require("body-parser");
var fs = require("fs");
var exphbs = require('express-handlebars');
var dataServiceAuth = require("./data-service-auth.js");
var clientSessions = require("client-sessions");
var ensureLogin = (req, res, next) => {
    if (!req.session.user)
        res.redirect("/login");
    else
        next();
};
app.use(express.static("public"));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(clientSessions({
    cookieName: "session", 
    secret: "ChazLeePierre",
    duration: 5 * 60 * 1000, // 5 mins
    activeDuration: 1* 60 * 1000 // 1 min
}));
app.use(function(req, res, next) {
    res.locals.session = req.session;
    next();
});
app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: 'main',
    helpers: {
        navLink: function (url, options) {
            return '<li' +
                ((url == app.locals.activeRoute) ? ' class="active" ' : '') +
                '><a href="' + url + '">' + options.fn(this) + '</a></li>';
        },
        equal: function (lvalue, rvalue, options) {
            if (arguments.length < 3)
                throw new Error("Handlerbars Helper equal needs 2 parameters");
            if (lvalue != rvalue) {
                return options.inverse(this);
            } else {
                return options.fn(this);
            }
        }
    }
}));
app.set('view engine', '.hbs');
app.use(function (req, res, next) {
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
});
const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filename: function (req, file, cb) {
        cb(null, Date.now() + path.extname(file.originalname));
    }
});
var upload = multer({ storage: storage });

/* ROUTES */

// MAIN

app.get('/', (req, res) => { // Home
    res.render(path.join(__dirname + "/views/home.hbs"));
});

app.get('/about', (req, res) => { // About
    res.render(path.join(__dirname + "/views/about.hbs"));
});

// SESSION

app.get('/login', (req, res) => { // LOGIN (GET)
    res.render("login");
});

app.post('/login', (req, res) => { // LOGIN (POST)
    req.body.userAgent = req.get('User-Agent');
    dataServiceAuth.checkUser(req.body)
    .then(user => {
        req.session.user = {
            userName: user.userName,
            email: user.email,
            loginHistory: user.loginHistory
        }
        res.redirect('/employees');
    }).catch(err => {
        res.render('login', {errorMessage: err, userName: req.body.userName});
    });
});

app.get('/register', (req, res) => { // REGISTER (GET)
    res.render("register");
});

app.post('/register', (req, res) => { // REGISTER (POST)
    console.log(req.body);
    dataServiceAuth.registerUser(req.body)
    .then((data) => {
        res.render("register", {successMessage: "User created"});
    }).catch((err) => {
        res.render("register", {errorMessage: err, userName: req.body.userName});
    });
});

app.get('/logout', (req, res) => { // LOGOUT (GET)
    req.session.reset();
    res.redirect("/");
});

app.get('/userHistory', ensureLogin, (req, res) => { // USERHISTORY (GET)
    res.render("userHistory");
});

// EMPLOYEES

app.get("/employees/add", ensureLogin, (req, res) => { // CREATE Employee (GET)
    data_service.getDepartments()
        .then((data) => res.render("addEmployee", { departments: data }) )
        .catch(() => res.render("addEmployee", { departments: [] }) ) 
});

app.post('/employees/add', ensureLogin, function (req, res) { // CREATE Employee (POST)
    data_service.addEmployee(req.body)
        .then(data => { res.redirect("/employees") })
        .catch((err) => res.json({ "message": err }))
});

app.get('/employees', ensureLogin, (req, res) => { // READ Employees (GET)
    switch (Object.keys(req.query)[0]) {
        case 'status':
            data_service.getEmployeesByStatus(req.query.status)
                .then((data) => { res.render("employees", (data.length > 0) ? { employees: data } : { message: "Request returned no results." }) })
                .catch((err) => { res.render({ "message": err }) });
            break;
        case 'manager':
            data_service.getEmployeesByManager(req.query.manager)
                .then((data) => { res.render("employees", (data.length > 0) ? { employees: data } : { message: "Request returned no results." }) })
                .catch((err) => { res.render({ "message": err }) });
            break;
        case 'department':
            data_service.getEmployeesByDepartment(req.query.department)
                .then((data) => { res.render("employees", (data.length > 0) ? { employees: data } : { message: "Request returned no results." }) })
                .catch((err) => { res.render({ "message": err }) });
            break;
        default:
            data_service.getAllEmployees()
                .then((data) => { res.render("employees", (data.length > 0) ? { employees: data } : { message: "Request returned no results." }) })
                .catch((err) => { res.render({ "message": err }) });
    }
});

app.get('/employee/:value', ensureLogin, (req, res) => { // READ Employee (GET)
    let viewData = {};
    data_service.getEmployeesByNum(req.params.value)
        .then((data) => { viewData.employee = (data) ? data : null })
        .catch((err) => { viewData.employee = null })
            .then(data_service.getDepartments).then((data) => {
                viewData.departments = data; 
                for (let i = 0; i < viewData.departments.length; i++) {
                    if (viewData.departments[i].departmentId == viewData.employee[0].department)
                        viewData.departments[i].selected = true;
                }
            }).catch(() => {
                viewData.departments = [];
            }).then(() => {
                if (!viewData.employee) 
                    res.status(404).send("Employee Not Found");
                else 
                    res.render("employee", { viewData: viewData });
        }).catch((err) => { res.status(500).send("Unable to Update Employee"); });
});

app.post("/employee/update", ensureLogin, function (req, res) { // UPDATE Employee (POST)
    data_service.updateEmployee(req.body)
        .then(data => { res.redirect("/employees") })
        .catch((err) => { res.render({ "message": err }) });
});

app.get('/employees/delete/:empNum', ensureLogin, (req, res) => { // DELETE Employee (GET)
    data_service.deleteEmployeeByNum(req.params.empNum)
    .then((data) => res.redirect("/employees"))
    .catch(() => res.status(500).send("Unable to Remove Employee / Employee not found"))
});

// DEPARTMENTS

app.get("/departments/add", ensureLogin, (req, res) => { // CREATE Department (GET)
    res.render("addDepartment");
});

app.post('/departments/add', ensureLogin, function(req, res) { // CREATE Department (POST)
    data_service.addDepartment(req.body)
        .then(data => { res.redirect("/departments") })
        .catch((err) => console.log(err))   
});

app.get('/department/:departmentId', ensureLogin, (req, res) => { // READ Department (GET)
    data_service.getDepartmentById(req.params.departmentId)
    .then((data) => {
        if (data.length > 0) res.render("department", { department: data });
        else res.status(404).send("Department Not Found"); 
    })
    .catch(() => { res.status(404).send("Department Not Found") })
});

app.get('/departments', ensureLogin, (req, res) => { // READ Departments (GET)
    data_service.getDepartments()
        .then((data) => { res.render("departments", (data.length > 0) ? { departments: data } : { message: "Request returned no results." }) })
        .catch((err) => { res.render({ "message": err }) });
});

app.post('/department/update', ensureLogin, function(req, res) { // UPDATE Department (POST)
    data_service.updateDepartment(req.body)
        .then(data => { res.redirect("/departments") })
        .catch((err) => res.json({ "message": err }))   
});

app.get('/departments/delete/:departmentId', ensureLogin, (req, res) => { // DELETE Department (GET)
    data_service.deleteDepartmentById(req.params.departmentId)
    .then((data) => res.redirect("/departments"))
    .catch(() => res.status(500).send("Unable to Remove Department / Department not found"))
});

// IMAGES

app.get("/images/add", ensureLogin, (req, res) => { // CREATE Image (GET)
    res.render(path.join(__dirname + "/views/addImage.hbs"));
});

app.post("/images/add", upload.single("imageFile"), ensureLogin, (req, res) => { // CREATE Image (POST)
    res.redirect("/images");
});

app.get("/images", ensureLogin, (req, res) => { // READ Images (GET)
    fs.readdir("./public/images/uploaded", function (err, file) {
        res.render("images", { data: file, title: "Images" });
    })
});

app.get('*', (req, res) => { // Page Not Found
    res.status(404);
    res.send("Error: Could not find page.");
});

data_service.initialize() // Initialize
    .then(dataServiceAuth.initialize)
    .then(() => {
        app.listen(PORT_listen, () => console.log("Express http server listening on " + PORT_listen));
    })
    .catch(err => {
        console.log(`Error: Initialization failed | ${err}`);
});