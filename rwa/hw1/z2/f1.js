function f1(f2, p) {
    let counter = 0;
    return function() {
        counter++;
        setTimeout(f2, p * counter);
    };
}

// var f1 = (function() {
//     let counter = 0;
//     return function(f2, p) {
//         return function() {
//             counter++;
//             setTimeout(f2, counter * p);
//         }
//     }
// }());

function foo() {
    console.log('Hello world!');
    // console.log(performance.now() / 1000);
}

const f3 = f1(foo, 1000);

f3();
f3();
f3();
f3();
f3();