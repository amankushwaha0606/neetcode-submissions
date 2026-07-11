class LRUCache {
    /**
     * @param {number} capacity
     */
    constructor(capacity) {
        this.cache = new Map();
        this.capacity = capacity;
    }

    /**
     * @param {number} key
     * @return {number}
     */
    get(key) {
        if(this.cache.has(key)) {
            let val = this.cache.get(key);
            this.cache.delete(key);
            this.cache.set(key, val);
            return val
        }
        return -1;
    }

    /**
     * @param {number} key
     * @param {number} value
     * @return {void}
     */
    put(key, value) {
        if(this.cache.has(key)) {
            this.cache.delete(key);
        } else {
            if(this.cache.size === this.capacity) {
                let removeKey = this.cache.keys().next().value;
                this.cache.delete(removeKey);
            }
        }
        this.cache.set(key, value);
    }
}
