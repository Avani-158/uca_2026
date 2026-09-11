function* calculator(initial) {
    let result = initial;

    while (true) {
        let input = yield result;

        if (typeof input.value !== "number") {
            yield "Invalid input";
            continue;
        }

        switch (input.operation) {
            case "add":
                result += input.value;
                break;

            case "subtract":
                result -= input.value;
                break;

            case "multiply":
                result *= input.value;
                break;

            case "divide":
                if (input.value === 0) {
                    yield "Cannot divide by zero";
                    continue;
                }
                result /= input.value;
                break;

            default:
                yield "Invalid operation";
        }
    }
}


const calc = calculator(50);

console.log(calc.next().value); // 50
console.log(calc.next({ operation: "add", value: 30 }).value); // 80
console.log(calc.next({ operation: "multiply", value: 2 }).value); // 160
console.log(calc.next({ operation: "add", value: "30" }).value); // Invalid input
console.log(calc.next().value); // 160
console.log(calc.next({ operation: "multiply", value: 0 }).value); // 0