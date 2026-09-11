function NewPromise(executorFunction) {
    let state = "pending";
    let value;
    let handlers = [];

    function resolve(result) {
        if (state !== "pending") return;

        state = "fulfilled";
        value = result;

        handlers.forEach(handler => {
            handler();
        });
    }

    function reject(error) {
        if (state !== "pending") return;

        state = "rejected";
        value = error;

        handlers.forEach(handler => {
            handler();
        });
    }

    this.then = function (onFulfilled) {
        return new NewPromise((resolveNext, rejectNext) => {

            function handle() {
                if (state === "fulfilled") {
                    try {
                        let result = onFulfilled(value);
                       if (result instanceof NewPromise) {
                            result.then(resolveNext).catch(rejectNext);
                        } else {
                            resolveNext(result);
                        }

                    } catch (error) {
                        rejectNext(error);
                    }
                } 
                else if (state === "rejected") {
                    rejectNext(value);
                }
            }

            if (state === "pending") {
                handlers.push(handle);
            } else {
                handle();
            }
        });
    };

    this.catch = function (onRejected) {
        return new NewPromise((resolveNext, rejectNext) => {

            function handle() {
                if (state === "rejected") {
                    try {
                        let result = onRejected(value);
                        resolveNext(result);
                    } catch (error) {
                        rejectNext(error);
                    }
                } 
                else if (state === "fulfilled") {
                    resolveNext(value);
                }
            }

            if (state === "pending") {
                handlers.push(handle);
            } else {
                handle();
            }
        });
    };

    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }
}


new NewPromise(resolve => {
    resolve(5);
})
.then(value => {
    return value * 2;
})
.then(value => {
    return value * 5;
})
.then(value => {
    console.log(value);
});