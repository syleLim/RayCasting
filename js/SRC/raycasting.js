import { SCREEN, MAP, PLAYER } from "../DATA/DB"
import Player from "./PLAYER/player"
import Map from "./MAP/map"
import Ray from "./RAY/ray"

const main = () => {
	const player = new Player(PLAYER);
	const map = new Map(MAP);
	const ray = new Ray();

	
}
