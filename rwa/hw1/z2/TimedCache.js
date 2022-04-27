function TimedCache(expiration) {
    this.cache = [];

    this.put = function(cacheKey, data) {
        this.cache[cacheKey] = data;
        setTimeout(() => {
            delete this.cache[cacheKey];
        }, expiration * 1000);
    }

    this.get = function(cacheKey) {
        return this.cache[cacheKey] === undefined ? null : this.cache[cacheKey];
    }

    this.clear = function() {
        this.cache = [];
    }
}

const tc = new TimedCache(5);
tc.put("foo", 35);
console.log(tc.get("foo"));

setTimeout(() => {
    console.log(tc.get("foo"));
}, 4000); 

setTimeout(() => {
    console.log(tc.get("foo"));
}, 2000); 