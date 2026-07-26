const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");

worker.onmessage = function (event) {

    usersDiv.innerHTML = "";

    const users = event.data;

    if (users.length === 0) {
        usersDiv.textContent = "No users found";
        return;
    }

    users.forEach(user => {
        const p = document.createElement("p");
        p.textContent = user;
        usersDiv.appendChild(p);
    });

};

worker.onerror = function (error) {
    usersDiv.textContent = "Error: " + error.message;
};

async function fetchUsers() {

    try {

        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok)
            throw new Error("Failed to fetch users");

        const users = await response.json();

        if (!users || users.length === 0)
            throw new Error("No users found");

        worker.postMessage(users);

    }
    catch (err) {

        usersDiv.textContent = err.message;

    }

}

fetchUsers();