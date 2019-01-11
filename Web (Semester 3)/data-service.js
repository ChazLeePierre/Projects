var exports = module.exports = {};
const Sequelize = require('sequelize');

var sequelize = new Sequelize('d9pln8uhaj5vik', 'qvbzxqerobqepi', '995e0305eec03bda8b33de983aa37951e9867509f71883991ddbb3d6147edea4', {
    host: 'ec2-54-225-196-122.compute-1.amazonaws.com',
    dialect: 'postgres',
    port: 5432,
    dialectOptions: {
        ssl: true
    }
});

const Employee = sequelize.define('Employee', {
    employeeNum: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    firstName: Sequelize.STRING,
    lastName: Sequelize.STRING,
    email: Sequelize.STRING,
    SSN: Sequelize.STRING,
    addressStreet: Sequelize.STRING,
    addressCity: Sequelize.STRING,
    addressState: Sequelize.STRING,
    addressPostal: Sequelize.STRING,
    maritialStatus: Sequelize.STRING,
    isManager: Sequelize.BOOLEAN,
    employeeManagerNum: Sequelize.INTEGER,
    status: Sequelize.STRING,
    department: Sequelize.INTEGER,
    hireDate: Sequelize.STRING,
    //timestamps: false
});

const Department = sequelize.define('Department', {
    departmentId: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    departmentName: Sequelize.STRING,
    //timestamps: false
});

Department.hasMany(Employee, { foreignKey: 'department' });

 // Initialize //

exports.initialize = function () {
    return new Promise((resolve, reject) => {
        sequelize.sync()
            .then(() => resolve())
            .catch(() => reject("Error: Database could not be synced."));
    });
};

// Employees //

exports.addEmployee = function(employeeData) { // Add Employee
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (data in employeeData) {
        if (!data) data = null;
    }
    return new Promise((resolve, reject) => {
        sequelize.sync().then(() => {
        Employee.create(employeeData)
        .then(() => resolve())
        .catch(() => reject(`Error: Employee ${employeeData.firstName} could not be added.`))
        });
    });
};

exports.updateEmployee = function (employeeData) { // Update Employee
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (data in employeeData) {
        if (!data) data = null;
    }
    return new Promise((resolve, reject) => {
        Employee.update(employeeData, { where: { employeeNum: employeeData.employeeNum } })
        .then(() => resolve(Employee.update(employeeData, { where: { employeeNum: employeeData.employeeNum } }) ))
        .catch(() => reject(`Error: Employee ${employeeData.firstName} could not be updated.`))
    });
};

exports.deleteEmployeeByNum = function(empNum){ // Delete Employee
    return new Promise((resolve, reject) => {
        Employee.destroy({ where: { employeeNum: empNum } }) 
        .then(() => resolve(Employee.destroy({ where: { employeeNum: empNum } }) )) 
        .catch(() => reject(`Error: Employee ${empNum} could not be deleted.`))
    });
};

exports.getEmployeesByStatus = function (status) { // Read Employees by Status
    return new Promise((resolve, reject) => {
        Employee.findAll({ where: { status: status } })
        .then(() => resolve(Employee.findAll({ where: { status: status } }) ))
        .catch(() => reject(`Error: Employee results filtered by ${status} could not be returned.`))
    });
}

exports.getEmployeesByDepartment = function (department) { // Read Employees by Department
    return new Promise((resolve, reject) => {
    Employee.findAll({ where: { department: department } })
        .then(() => resolve(Employee.findAll({ where: { department: department } }) ))
        .catch(() => reject(`Error: Employee results filtered by ${department} could not be returned.`))
});
}

exports.getEmployeesByManager = function (manager) { // Read Employees by Manager
    return new Promise((resolve, reject) => {
    Employee.findAll({ where: { employeeManagerNum: manager }})
        .then(() => resolve(Employee.findAll({ where: { employeeManagerNum: manager } }) ))
        .catch(() => reject(`Error: Employee results filtered by ${manager} could not be returned.`))
});
}

exports.getEmployeesByNum = function (num) { // Read Employees by ID
    return new Promise((resolve, reject) => {
    Employee.findAll({ where: { employeeNum: num } })
        .then(() => resolve(Employee.findAll({ where: { employeeNum: num } }) ))
        .catch(() => reject(`Error: Employee results filtered by ${num} could not be returned.`))
});
}

exports.getAllEmployees = function () { // Read All Employees
    return new Promise((resolve, reject) => {
    Employee.findAll()
        .then(() => resolve(Employee.findAll({ order: [['employeeNum', 'ASC'], ['lastName', 'ASC'] ]})))
        .catch(() => reject("Error: Employee results could not be returned."))
});
};

// Departments //

exports.addDepartment = function(departmentData) { // Create Department
    for (data in departmentData) {
        if (!data) data = null;
    }
    return new Promise((resolve, reject) => {
        sequelize.sync().then(() => {
        Department.create(departmentData)
        .then(() => resolve())
        .catch(() => reject(`Error: Department ${departmentData.departmentName} could not be added.`))
    });
    });
};

exports.updateDepartment = function(departmentData) { // Update Department
    for (data in departmentData) {
        if (!data) data = null;
    }
    return new Promise((resolve, reject) => {
        Department.update({ departmentName: departmentData.departmentName }, { where: { departmentId: departmentData.departmentId } })
        .then(() => resolve(Department))
        .catch(() => reject(`Error: Department ${departmentData.departmentName} could not be updated.`))
    });
};

exports.deleteDepartmentById = function(id) { // Delete Department by ID
    return new Promise((resolve, reject) => {
        Department.destroy({ where: { departmentId: id } }) 
        .then(() => resolve(Department.destroy({ where: { departmentId: id } }) )) 
        .catch(() => reject(`Error: Department ${id} could not be deleted.`))
    });
};

exports.getDepartments = function () { // Read Departments
    return new Promise((resolve, reject) => {
        Department.findAll()
            .then(() => resolve(Department.findAll({ order: [['departmentId', 'ASC'], ['departmentName', 'ASC'] ] }) ))
            .catch(() => reject("Error: Department results could not be returned."))
    });
};

exports.getDepartmentById = function(id) { // Read Departments by ID
    return new Promise((resolve, reject) => {
       Department.findAll({ where: { departmentId: id } })
        .then(() => resolve(Department.findAll({ where: { departmentId: id } }) ))
        .catch(() => reject(`Error: Department results filtered by ${id} could not be returned.`)) 
    });
};




