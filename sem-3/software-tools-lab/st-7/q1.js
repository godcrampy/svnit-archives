let person = {
    firstName: "Sahil",
    lastName: "Bondre",
    dateOfBirth: "28/07/2000",
    rollNumber: "u18co021",
    city: "Pune"
}

function merge(obj) {
    let arr = "";
    for (const key in obj)
        arr += `${key}: ${obj[key]}\n`;
    return arr;
}

alert(merge(person))