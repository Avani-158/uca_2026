self.onmessage = function (event) {

    const users = event.data;

    const result = users.map(user =>
        `${user.name} - ${user.active ? "Active" : "Inactive"}`
    );

    self.postMessage(result);

};