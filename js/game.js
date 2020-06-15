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
	}

	casting() {
		let isHit = CHECK;

		for (let i = 0; i < SCREEN.width; i++) {
			this.ray.set_ray(this.player.dir, this.player.pos,
							this.map.plane, i, this.screen.width);
			while (isHit == CHECK) {
				isHit = this.ray.hit_check(this.map.map, this.player.pos);
			}
		}
		isHit != NON_HIT ? 
	}

	keyEvent(key) {
		this.player.behavior(key);
		this.casting();
	}
}