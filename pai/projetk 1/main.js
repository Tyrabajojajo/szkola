let form = document.querySelector("#taskForm");
let taskInput = document.querySelector("#task");
let priority = document.querySelector("#prio");
let list = document.querySelector("#list");
const tasks = [];

form.addEventListener("submit", function(event) {
    event.preventDefault();
    let task = taskInput.value;
    let li = document.createElement("li");
    li.textContent = `${task} - ${priority.value}`;
    list.appendChild(li);
    taskInput.value = "";
});
    