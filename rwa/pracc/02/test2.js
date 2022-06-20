function Pravougaonik(a, b) {
    this.a = a;
    this.b = b;
    this.vrsta = "pravougaonik";
}

Pravougaonik.prototype.P = function() {
    return this.a * this.b;
}

Pravougaonik.prototype.O = function() {
    return 2 * (this.a + this.b);
}

Pravougaonik.prototype.jePravougaonik = function() {
    return true;
}

Pravougaonik.prototype.koSi = function() {
    return `Ja sam ${this.vrsta}`;
}

function Kvadrat(a) {
    Pravougaonik.call(this, a, a);
    this.vrsta = "kvadrat";
}

Kvadrat.prototype = Object.create(Pravougaonik.prototype);
Kvadrat.prototype.constructor = Kvadrat;
Kvadrat.prototype.jeKvadrat = function() {
    return this.a === this.b;
}

function kopiraj(obj) {
    if (!(obj instanceof Pravougaonik)) {
        throw TypeError('Not instance of Pravougaonik'); 
    }

    var clone = Object.create(obj);
    for (var key in obj) {
        clone[key] = obj[key];
    }

    return clone;
}

// console.log(p);
// console.log(p.__proto__);
// console.log(k);
// console.log(k.__proto__);

var p = new Pravougaonik(3, 4);
console.log(p.P(), p.O(), p.jePravougaonik(), p.koSi());

var k = new Kvadrat(5);
console.log(k.P(), k.O(), k.jeKvadrat(), k.jePravougaonik(), k.koSi());

var nk = kopiraj(k);
console.log(nk.P(), nk.O(), nk.jeKvadrat(), nk.jePravougaonik(), nk.koSi());

var np = kopiraj(p);
console.log(np.P(), np.O(), np.jePravougaonik(), np.koSi());