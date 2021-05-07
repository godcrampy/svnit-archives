$("#logout-button").on("click", () => {
  localStorage.removeItem("token");
  window.location = "/";
});

const getUrlParams = (url) => {
  const params = {};
  (url + "?")
    .split("?")[1]
    .split("&")
    .forEach(function (pair) {
      pair = (pair + "=").split("=").map(decodeURIComponent);
      if (pair[0].length) {
        params[pair[0]] = pair[1];
      }
    });
  return params;
};

const storage = firebase.storage();
const db = firebase.firestore();

(async () => {
  const makeCard = (url, username, id, caption, filename) => {
    console.log(filename);
    return $(`<div class="card m-5" style="width: 18rem">
    <img
      class="card-img-top"
      src="${url}"
      alt="Card image cap"
    />
    <div class="card-body">
      <a class="card-title" href="/user?id=${id}">${username}</a>
      <p class="card-text">${caption}
      </p>
    </div>
  </div>`);
  };

  $("#tag-search").on("click", () => {
    const tag = $("#tag-input").val();
    db.collection("images")
      .where("tags", "array-contains", tag)
      .get()
      .then((snapshot) => {
        console.log(snapshot);
        snapshot.docs
          .map((e) => e.data())
          .sort((a, b) => b.time - a.time)
          .forEach((data) => {
            console.log(data);
            $("#image-grid").append(
              makeCard(
                data.url,
                data.username,
                data.user,
                data.caption,
                data.fileName
              )
            );
          });
      });

    db.collection("meta")
      .doc("tags")
      .get()
      .then((doc) => {
        const data = doc.data();
        console.log("data", data);
        document.getElementById("search-badge").hidden = false;
        if (data[tag] === undefined) {
          // first time search
          let obj = {};
          obj[tag] = 1;
          db.collection("meta").doc("tags").set(obj, { merge: true });
          document.getElementById("search-badge").innerHTML =
            "Search Count: " + 1;
        } else {
          const val = data[tag];
          let obj = {};
          obj[tag] = Number(val) + 1;
          db.collection("meta").doc("tags").set(obj, { merge: true });
          document.getElementById("search-badge").innerHTML =
            "Search Count: " + (Number(val) + 1);
        }
      });
  });

  $("#user-search").on("click", async () => {
    const name = $("#user-input").val();
    const token = localStorage.getItem("token");

    const res = await fetch(`${BASE_URL}/users?name=${name}`, {
      method: "GET",
      headers: {
        ...headers,
        Authorization: `Bearer ${token}`,
      },
    });
    const json = await res.json();
    const users = json.results;
    if (users === undefined || users.length === 0) {
      $("#modal-body").html("No user found");
      $("#exampleModal").modal("show");
      return;
    }
    const userId = users[0].id;
    console.log("userId", userId);
    db.collection("images")
      .where("user", "==", userId)
      .get()
      .then((snapshot) => {
        console.log(snapshot.docs);
        snapshot.docs
          .map((e) => e.data())
          .sort((a, b) => b.time - a.time)
          .forEach((data) => {
            console.log(data);
            $("#image-grid").append(
              makeCard(
                data.url,
                data.username,
                data.user,
                data.caption,
                data.fileName
              )
            );
          });
      });

    db.collection("meta")
      .doc("tags")
      .get()
      .then((doc) => {
        const data = doc.data();
        console.log("data", data);
        document.getElementById("search-badge").hidden = false;
        if (data[name] === undefined) {
          // first time search
          let obj = {};
          obj[name] = 1;
          db.collection("meta").doc("tags").set(obj, { merge: true });
          document.getElementById("search-badge").innerHTML =
            "Search Count: " + 1;
        } else {
          const val = data[name];
          let obj = {};
          obj[name] = Number(val) + 1;
          db.collection("meta").doc("tags").set(obj, { merge: true });
          document.getElementById("search-badge").innerHTML =
            "Search Count: " + (Number(val) + 1);
        }
      });
  });
})().catch((err) => {
  console.error(err);
});
