if (window.location.pathname !== "/" && localStorage.getItem("token") === null) {
  window.location = "/";
}

if(window.location.pathname === "/" && localStorage.getItem("token") != null) {
  window.location = "/home"
}
