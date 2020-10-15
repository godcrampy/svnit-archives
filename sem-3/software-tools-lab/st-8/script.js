let validation = {
	username: false,
	password: false,
	"confirm-password": false,
	age: false,
	email: false,
	dob: false,
	phone: false,
	website: false,
	country: true,
	tnc: false
};

/**
 *
 * @param {string} email
 * @returns {boolean}
 */
function validateEmail(email) {
	var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
	return re.test(String(email).toLowerCase());
}

function checkValidation() {
	function allTrue(obj) {
		for (var o in obj) if (!obj[o]) return false;

		return true;
	}
	if (allTrue(validation)) {
		document.getElementById("submit").disabled = false;
	}
}

/**
 *
 * @param {string} website
 * @returns {boolean}
 */
function validateWebsite(website) {
	var re = /[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)/;
	return re.test(String(website).toLowerCase());
}

/**
 *
 * @param {HTMLElement} element
 * @returns {void}
 */
function setBorder(element) {
	element.addEventListener("blur", () => {
		if (isSuccess(element)) {
			element.classList.add("success");
			element.classList.remove("danger");
			element.nextElementSibling.innerHTML = "";
			validation[element.id] = true;
			checkValidation();
		} else {
			element.classList.add("danger");
			element.classList.remove("success");
			element.nextElementSibling.innerHTML = element.errorMessage;
		}
	});
}

/**
 *
 * @param {HTMLElement} element
 * @returns {Boolean}
 */
function isSuccess(element) {
	switch (element.id) {
		case "username":
			if (element.value.length < 7 || element.value.length > 10) return false;
			return true;
		case "password":
			if (element.value.length < 5 || element.value.length > 10) return false;
			return true;
		case "confirm-password":
			if (element.value === document.getElementById("password").value)
				return true;
			return false;
		case "age":
			if (element.value < 22) return false;
			return true;
		case "email":
			if (validateEmail(element.value)) return true;
			return false;
		case "phone":
			if (element.value.length === 10) return true;
			return false;
		case "dob":
			if (element.value === "") return false;
			return true;
		case "website":
			if (validateWebsite(element.value)) return true;
			return false;
		case "country":
			if (element.value === "") return false;
			return true;
		case "tnc":
			console.log(element.value);
			if (element.value === "on") return true;
			return false;
		default:
			return true;
	}
}

/**
 *
 * @param {String} id
 * @param {String} errorMessage
 * @returns {void}
 */
function addValidation(id, errorMessage) {
	let element = document.getElementById(id);
	element.errorMessage = errorMessage;
	setBorder(element);
}

function showData() {
	let string = "";
	[...document.forms[0].children].forEach(elem => {
		if (elem.children[0].value  && !elem.firstChild.textContent.includes("Password"))
			string += `${elem.firstChild.textContent}\b ${elem.children[0].value}\n`;
	});
	alert(string);
}

addValidation("username", "Username must have length of 7 to 12 charecters");
addValidation("password", "Password must have length of 5 to 10 charecters");
addValidation("confirm-password", "Passwords don't match");
addValidation("age", "Age must be atleast 22");
addValidation("email", "Email is not valid");
addValidation("phone", "Phone is not valid");
addValidation("dob", "Enter Date");
addValidation("website", "Invalid Website");
addValidation("country", "Select a country");
addValidation("tnc", "Accept the Terms and Conditions");
