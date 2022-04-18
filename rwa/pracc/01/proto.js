//Properties should be defined in constructor
function Student(name) {
    this.name = name;
}

//Methods should be defined through prototype
Student.prototype.toString = function() {
    return `Student name: ${this.name}`;
}

function Fet(name, programmingLanguage) {
    Student.call(this, name); //Call constructor of "parent"
    this.programmingLanguage = programmingLanguage;
}

Fet.prototype = Object.create(Student.prototype); //Object.create will not run constructor code like 'new' will, very useful in this case.
Fet.prototype.constructor = Student;
Fet.prototype.specialty = function() {
    return this.programmingLanguage;
}

const zlatan = new Student("zlatan");
console.log(zlatan.toString());

const amer = new Fet("amer", "c++");
console.log(amer.toString());
console.log(Object.getPrototypeOf(amer));
console.log(amer.specialty());
