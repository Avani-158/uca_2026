const worker = new Worker("worker.js");

worker.onmessage = function (event) {
    event.data.forEach(user => console.log(user));
};

worker.onerror = function (error) {
    console.error(error);
};

async function fetchUsers() {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok)
            throw new Error("Failed to fetch users");

        const users = await response.json();

        if (!users || users.length === 0)
            throw new Error("No users returned");

        worker.postMessage(users);

    } catch (err) {
        console.error(err.message);
    }
}

fetchUsers();