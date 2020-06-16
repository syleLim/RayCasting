const Game = require("./SRC/game")
const Ray = require("./SRC/RAY/ray")
const Player = require("./SRC/PLAYER/player")
const Map = require("./SRC/MAP/map")
const Screen = require("./SRC/SCREEN/screen");
const DB = require("./DATA/DB");

const { createCanvas, createImageData, Image } = require("canvas");
const fs = require("fs");
const canvas = createCanvas(DB.SCREEN.width, DB.SCREEN.height);
const ctx = canvas.getContext("2d");
const image = createImageData(DB.SCREEN.width, DB.SCREEN.height);


const game = new Game(new Player(DB.PLAYER), new Ray(),
							new Map(DB.MAP), new Screen(DB.SCREEN));
game.casting()

game.screen.wall.forEach(e => {
	//console.log(e.index, e.start, e.end);
	
	let x = e.index;
	let index;
	for (let y = Math.floor(e.start); y < Math.floor(e.end); y++) {
		index = (x + y * game.screen.width) * 4;
		image.data[index + 0] = e.r;
		image.data[index + 1] = e.g;
		image.data[index + 2] = e.b;
		image.data[index + 3] = e.a;
	}
});

ctx.putImageData(image, 0, 0);

const out = fs.createWriteStream("./test.png");
const stream = canvas.createPNGStream();

stream.on("data", chunk => {
	out.write(chunk);
})

stream.on("end", chunk => {
	console.log("end")
})

