const storage = firebase.storage();
const db = firebase.firestore();
console.log(storage);

async function deleteImage(fileName) {
  const res = await db
    .collection("images")
    .where("fileName", "==", fileName)
    .get();
  const id = res.docs[0].id;

  await db.collection("images").doc(id).delete();
  const imgRef = storage.ref().child(fileName);
  await imgRef.delete();

  $("#modal-body").html("Deleted");
  $("#exampleModal").modal("show");
}

async function updateCaption(fileName) {
  const res = await db
    .collection("images")
    .where("fileName", "==", fileName)
    .get();
  const id = res.docs[0].id;
  const caption = $("#editcaption").val();
  const tags = caption.match(/#[a-z]+/gi);
  const prev = db.collection("images").doc(id).caption;
  db.collection("images").doc(id).update({ caption, tags });
  $("#modal-body").html("Caption Updated...");
  $("#exampleModal").modal("show");
}

function openInNewTab(href) {
  Object.assign(document.createElement("a"), {
    target: "_blank",
    href: href,
  }).click();
}

async function incrementDownloadCount(fileName) {
  const res = await db
    .collection("images")
    .where("fileName", "==", fileName)
    .get();
  const id = res.docs[0].id;
  const count = res.docs[0].data().count + 1;
  const url = res.docs[0].data().url;
  console.log(res.docs[0].data().count);
  console.log(count);

  await db.collection("images").doc(id).set({ count }, { merge: true });

  openInNewTab(url);
}

(async () => {
  $("#logout-button").on("click", () => {
    localStorage.removeItem("token");
    window.location = "/";
  });

  const makeCard = (url, username, id, caption, filename, count) => {
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
      <div class="card-footer text-muted">
      ${count} downloads
    </div>
      <button class="btn btn-primary" onclick="incrementDownloadCount('${filename}')">Download</button>
      <button class="btn btn-danger user-only" onclick="deleteImage('${filename}')">Delete</button>
      <input type="text" class="my-2 form-control user-only" id="editcaption"/>
      <button class="btn btn-success user-only" onclick="updateCaption('${filename}')">Update Caption</button>
    </div>
  </div>`);
  };

  const username = localStorage.getItem("username");
  const email = localStorage.getItem("email");
  const id = localStorage.getItem("id");
  const token = localStorage.getItem("token");

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

  const params = getUrlParams(window.location.href);
  console.log(params);
  if (params.id === undefined || params.id === id) {
    // self
    console.log("SELF");
    $("#username-text").html(username);
    $("#email-text").html(email);
    $(".user-only").show();
  } else {
    console.log(token);
    // other user
    console.log("OTHER");
    const res = await fetch(`${BASE_URL}/users/${params.id}`, {
      method: "GET",
      headers: {
        ...headers,
        Authorization: `Bearer ${token}`,
      },
    });

    if (!res.ok) {
      window.location = "/user";
    }

    const json = await res.json();
    const username = json.name;
    const email = json.email;
    $("#username-text").html(username);
    $("#email-text").html(email);
    $(".user-only").hide();
    console.log(json);
  }

  $("#add-button").on("click", async () => {
    const file = document.getElementById("upload").files[0];
    const caption = $("textarea").val();
    let tags = caption.match(/#[a-z]+/gi);
    if (tags === null) tags = [];
    const id = localStorage.getItem("id");
    const time = Number(new Date()) + "";
    const fileName = `images/${id + time}`;

    if (file === undefined) {
      $("#modal-body").html("Select an image first");
      $("#exampleModal").modal("show");
      return;
    }

    if (caption.length === 0) {
      $("#modal-body").html("Caption cannot be empty");
      $("#exampleModal").modal("show");
      return;
    }

    const imgRef = storage.ref().child(fileName);

    await imgRef.put(file);
    const url = await imgRef.getDownloadURL();
    console.log(url);

    await db.collection("images").add({
      user: id,
      url,
      count: 0,
      caption,
      tags,
      time: Number(Date.now()),
      username,
      fileName,
    });

    $("#modal-body").html("Image uploaded!");
    $("#exampleModal").modal("show");
    $("input").val("");
  });

  let userId = params.id || localStorage.getItem("id");
  console.log(userId);
  db.collection("images")
    .where("user", "==", userId)
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
              data.fileName,
              data.count
            )
          );
        });
      if (params.id !== undefined && params.id !== id) {
        $(".user-only").hide();
      }
    });
})().catch((err) => {
  console.error(err);
});
