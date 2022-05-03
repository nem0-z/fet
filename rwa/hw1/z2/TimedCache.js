function TimedCache(expiration) {
    var cache = {};

    this.put = function(cacheKey, data) {
        const key = String(cacheKey);
        cache[key] = data;
        setTimeout(() => {
            delete cache[key];
        }, expiration * 1000);
    }

    this.get = function(cacheKey) {
        const key = String(cacheKey);
        return cache[key] || null;
    }

    this.clear = function() {
        cache = {};
    }
}

const tc = new TimedCache(2);

tc.put("foo", "This is foo.");
setTimeout(() => {
    console.log('Foo value(after 2.02s): ' + tc.get("foo"));
}, 2002);

tc.put("bar", "This is bar.");
setTimeout(() => {
    console.log('Bar value(after 1.98s): ' + tc.get("bar"));
}, 1998);
