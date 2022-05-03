function f1(f2, p) {
    let counter = 0;
    let lastRun = new Date();

    return function() {
        if (new Date() - lastRun >= p) {
            f2();
            lastRun = new Date();
        } else {
            counter++;
            setTimeout(() => {
                f2();
                lastRun = new Date();
            }, p * counter);
        }
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
    console.log(performance.now() / 1000);
}

function sleep(ms) {
    return new Promise(_ => setTimeout(_, ms));
}

const f3 = f1(foo, 1000);

f3();
f3();
f3();
f3();
f3();
sleep(8000).then(() => {
    console.log('After sleep');
    f3();
});
f3();
