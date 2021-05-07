let snake = [
  { x: 200, y: 200 },
  { x: 190, y: 200 },
  { x: 180, y: 200 },
  { x: 170, y: 200 },
];

let score = 0;
// True if changing direction
let changingDirection = false;
// food coords
let food_x;
let food_y;
// Horizontal velocity
let dx = 10;
// Vertical velocity
let dy = 0;

let isCross = false;

// Get the canvas element
const snakeboard = $("#snakeboard")[0];
// Return a two dimensional drawing context
const snakeboard_ctx = snakeboard.getContext("2d");

$("#left").click(() => changeDirectionButton("LEFT"));
$("#right").click(() => changeDirectionButton("RIGHT"));
$("#up").click(() => changeDirectionButton("UP"));
$("#down").click(() => changeDirectionButton("DOWN"));
$(document).keydown(changeDirection);
// Start game
main();

genFood();
