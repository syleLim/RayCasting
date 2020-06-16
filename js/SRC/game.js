const X = 0;
const Y = 1;
const CHECK = -2;
const NON_HIT = -1;

class Game {
	constructor (player, ray, map, screen) {
		this.player = player;
		this.ray = ray;
		this.map = map;
		this.screen = screen;
		this.map.setPlane(player.dir, 60);
	}

	casting() {
		let isHit = CHECK;

		this.screen.flushWall();
		
		for (let i = 0; i < this.screen.width; i++) {
			this.ray.set_ray(this.player.dir, this.player.pos,
							this.map.plane, i, this.screen.width);
			while (isHit === CHECK) {
				isHit = this.ray.hit_check(this.map, this.player.pos);
			}
			isHit != NON_HIT ? 
				this.screen.setWall(i, this.ray.getWallDistance(this.player.dir, isHit), isHit) : 0;
			isHit = CHECK;
		}
	}

	keyEvent(key) {
		this.player.behavior(key);
		this.casting();
	}
}

module.exports = Game;