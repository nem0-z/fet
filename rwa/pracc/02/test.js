var bar;
var bar = 1;

console.log(bar);

d = 5;
console.log(5);

console.log(global.d);
console.log(global.bar);

let a = 2, b = 4;

console.log(a = b);

console.log(a);
console.log(b);

console.log(5 + '6');

var x = "konj", y = "brato";

console.log(x && y);

var obj = Object();
obj.p = 1;

console.log(obj);

const t = {
    a: 1,
    b: 2,
    fun: function() {
        console.log(this);
        console.log('brato');
    },
};

console.log(t);

t.a = 5;
t.c = 5;

console.log(delete t.x);

var c = [1,2,3,5];
aaa = c.slice(1,2);
console.log(aaa);

t.fun();

const r = new Function('a', 'b', 'return a+b');
console.log(r(5, 10));

function ajla() {
    var a = 1;
    console.log(a);
    {
        var a = 'abc';
        console.log(a);
        {
            var a = 100;
        }
    }

    for (var i = 0; i < 1; i++) {
        var i = 400;
    }
    console.log(i);
}

global.bratulah = 't';
new konjko();
function konjko() {
    console.log(this);
    console.log(1);
}

t.fun();

function kremko() {
    this.a = 200;
    return {b: 400};
}

kremko.call(t);
console.log(t);

console.log(new kremko());

function slinko(a, b) {
    a.a = 400;
    b = 200;
}

var e1 = [1];
var e2 = 2;

slinko(e1, e2);
console.log(e1, e2);

// ajla();

// let x;
// let x = 1;

// console.log(x);

// foo();
// bar();

// var bar = function() {
//     console.log('hi');
// }

// function foo() {
//     console.log('hello');
// }