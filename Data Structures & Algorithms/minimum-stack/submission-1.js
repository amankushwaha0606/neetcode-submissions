class MinStack {
    constructor() {
        this.minStack = [];
        this.elements = [];
    }

    /**
     * @param {number} val
     * @return {void}
     */
    push(val) {
        this.elements.push(val);
        if (this.minStack.length === 0 || val <= this.minStack.at(-1)) {
            this.minStack.push(val);
        }        
    }

    /**
     * @return {void}
     */
    pop() {
        if(this.minStack.at(-1) === this.elements.at(-1)) {
            this.minStack.pop();
        }
        this.elements.pop();

    }

    /**
     * @return {number}
     */
    top() {
        return this.elements.at(-1)
    }

    /**
     * @return {number}
     */
    getMin() {
        return this.minStack.at(-1);
    }
}
