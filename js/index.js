import { Game, Ray, Player, Map } from "./SRC"
import { PLAYER, MAP, SCREEN } from "./DATA/DB"

const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");

const game = new Game(new Player(PLAYER), new Ray(),
							new Map(MAP), SCREEN);
game.casting()

