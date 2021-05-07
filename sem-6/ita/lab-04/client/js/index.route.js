$("#register-button").on("click", async () => {
  const username = $("#register-username").val();
  const email = $("#register-email").val();
  const password = $("#register-password").val();

  console.log(username, email, password);
  if (username === undefined || username.length <= 3) {
    $("#modal-body").html("Invalid Username");
    $("#exampleModal").modal("show");
    return;
  }
  if (!validateEmail(email)) {
    $("#modal-body").html("Invalid Email");
    $("#exampleModal").modal("show");
    return;
  }
  if (password === undefined || password.length < 8) {
    $("#modal-body").html("Password must be atleast 8 charecters long");
    $("#exampleModal").modal("show");
    return;
  }
  try {
    const res = await fetch(`${BASE_URL}/auth/register`, {
      method: "POST",
      headers,
      body: JSON.stringify({
        name: username,
        password: password,
        email: email,
      }),
    });

    if (!res.ok) {
      throw new Error("Email exists");
    }

    const json = await res.json();
    console.log(json);
    $("#modal-body").html("New user created! Login to continue");
    $("#exampleModal").modal("show");
    $("input").val("");
  } catch (err) {
    console.log(err.toString());
    $("#modal-body").html("Email already exists");
    $("#exampleModal").modal("show");
    return;
  }

  console.log("Reached!");
});

$("#login-button").on("click", async () => {
  const email = $("#login-email").val();
  const password = $("#login-password").val();

  console.log(email, password);
  if (!validateEmail(email)) {
    $("#modal-body").html("Invalid Email");
    $("#exampleModal").modal("show");
    return;
  }
  if (password === undefined || password.length < 8) {
    $("#modal-body").html("Password must be atleast 8 charecters long");
    $("#exampleModal").modal("show");
    return;
  }
  try {
    const res = await fetch(`${BASE_URL}/auth/login`, {
      method: "POST",
      headers,
      body: JSON.stringify({
        password,
        email,
      }),
    });

    if (!res.ok) {
      throw new Error("Invalid Login");
    }

    const json = await res.json();
    console.log(json);
    localStorage.setItem("token", json.tokens.access.token);
    localStorage.setItem("email", email);
    localStorage.setItem("id", json.user.id);
    localStorage.setItem("username", json.user.name);
    $("#modal-body").html("Login Successful!");
    $("#exampleModal").modal("show");
    $("input").val("");
    window.location = "/home";
  } catch (err) {
    console.log(err.toString());
    $("#modal-body").html("Invalid Credentials");
    $("#exampleModal").modal("show");
    return;
  }

  console.log("Reached!");
});

function validateEmail(email) {
  const re = /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  return re.test(String(email).toLowerCase());
}
