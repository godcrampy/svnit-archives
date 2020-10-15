alert("Hello!");

document.querySelectorAll("label").forEach(label =>{
    label.onmouseover = () => label.style.border = "1px solid red";
    label.onmouseout = () => label.style.border = "0px solid red";
})

document.querySelectorAll("input").forEach(elem => {
    elem.onfocus = () => elem.style.backgroundColor = "#ccc";
    elem.onblur = () => elem.style.backgroundColor = "#ccc";
});

document.querySelectorAll("textarea").forEach(elem => {
    elem.onfocus = () => elem.style.backgroundColor = "#ccc";
    elem.onblur = () => elem.style.backgroundColor = "#ccc";
});

function onSubmit() {
    alert("Success!!");
}