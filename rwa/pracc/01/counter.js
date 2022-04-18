const counter = (function() {
    let value = 0;
    return function() {
        return value++;
    }
}());

console.log(counter());
console.log(counter());
console.log(counter());
console.log(counter());
console.log(counter());
console.log(counter());
