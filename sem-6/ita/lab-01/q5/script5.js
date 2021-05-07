let subscribe = document.querySelector("#event");
let list = document.querySelector("div.container");
let btn = document.querySelector("#submit");

let drishti = document.querySelector("#drishti");
let chapters = document.querySelector("#chapters");
let sttp = document.querySelector("#sttp");
let summer = document.querySelector("#summer");
let talks = document.querySelector("#talks");
let conference = document.querySelector("#conference");
let workshop = document.querySelector("#workshop");
let nptel = document.querySelector("#nptel");

let selectedEvents = [];

subscribe.addEventListener("click", () => {
  if (subscribe.checked) {
    list.style.display = "block";
  } else {
    list.style.display = "none";
  }
});

drishti.addEventListener("click", () => {
  if (drishti.checked) {
    selectedEvents.push("Drishti");
  } else {
    if (selectedEvents.indexOf("Drishti") != -1) {
      let idx = selectedEvents.indexOf("Drishti");
      selectedEvents.splice(idx, 1);
    }
  }
});

chapters.addEventListener("click", () => {
  if (chapters.checked) {
    selectedEvents.push("SVNIT Chapters");
  } else {
    if (selectedEvents.indexOf("SVNIT Chapters") != -1) {
      let idx = selectedEvents.indexOf("SVNIT Chapters");
      selectedEvents.splice(idx, 1);
    }
  }
});

sttp.addEventListener("click", () => {
  if (sttp.checked) {
    selectedEvents.push("STTP");
  } else {
    if (selectedEvents.indexOf("STTP") != -1) {
      let idx = selectedEvents.indexOf("STTP");
      selectedEvents.splice(idx, 1);
    }
  }
});

summer.addEventListener("click", () => {
  if (summer.checked) {
    selectedEvents.push("Summer School");
  } else {
    if (selectedEvents.indexOf("Summer School") != -1) {
      let idx = selectedEvents.indexOf("Summer School");
      selectedEvents.splice(idx, 1);
    }
  }
});

talks.addEventListener("click", () => {
  if (talks.checked) {
    selectedEvents.push("Talks");
  } else {
    if (selectedEvents.indexOf("Talks") != -1) {
      let idx = selectedEvents.indexOf("Talks");
      selectedEvents.splice(idx, 1);
    }
  }
});

workshop.addEventListener("click", () => {
  if (workshop.checked) {
    selectedEvents.push("Workshops");
  } else {
    if (selectedEvents.indexOf("Workshops") != -1) {
      let idx = selectedEvents.indexOf("Workshops");
      selectedEvents.splice(idx, 1);
    }
  }
});

conference.addEventListener("click", () => {
  if (conference.checked) {
    selectedEvents.push("Conferences");
  } else {
    if (selectedEvents.indexOf("Conferences") != -1) {
      let idx = selectedEvents.indexOf("Conferences");
      selectedEvents.splice(idx, 1);
    }
  }
});

nptel.addEventListener("click", () => {
  if (nptel.checked) {
    selectedEvents.push("NPTEL Courses");
  } else {
    if (selectedEvents.indexOf("NPTEL Courses") != -1) {
      let idx = selectedEvents.indexOf("NPTEL Courses");
      selectedEvents.splice(idx, 1);
    }
  }
});

btn.addEventListener("click", () => {
  localStorage.setItem("events", selectedEvents);
  open("./q5_final.html");
});
