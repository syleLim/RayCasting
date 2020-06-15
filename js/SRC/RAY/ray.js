const X = 0;
const Y = 0;
const NON_HIT = -1;
const CHECK = -2;

class Ray {
	constructor() {
		this.dir = [0, 0];
		this.dist = [0, 0];
		this.delta = [0, 0];
	}

	set_ray(dir, pos, plane, i, width) {
		const ratio = 2 * i / width - 1;

		this.dir = dir.map((e, i) => e + plane[i] * ratio);
		this.delta = this.dir.map((e, i) => {
			if (e === 0)
				return (0);
			else if (e > 0)
				return Math.abs((pos[i] - Math.floor(pos[i])) / e);
			else 
				return Math.abs((Math.floor(pos[i] + 1) - pos[i]) / e);
		});
		this.dist = this.dir.map(e => Math.abs(1 / e));
	}

	hit(map, y, x, flag) {
		if (y < 0 || x < 0 || y > map.height - 1 || x > map.width - 1)
			return NON_HIT;
		return map.map[parseInt(y)][parseInt(x)] != 0 ? flag : CHECK;
	}

	hit_check(map, pos) {
		let isHit = CHECK;

		if (this.dist[X] < this.dist[Y]) {
			if (this.dir[X] < 0)
				isHit = this.hit(map, pos[Y] + this.dir[Y] * this.dist[X],
								pos[X] + this.dir[X] * this.dist[X] - 0.5, X);
			if (this.dir[X] > 0)
				isHit = this.hit(map, pos[Y] + this.dir[Y] * this.dist[X],
					pos[X] + this.dir[X] * this.dist[X] + 0.5, X);
			this.dist[X] += isHit === CHECK ? this.delta[X] : 0;
		} else {
			if (this.dir[Y] < 0)
				isHit = this.hit(map, pos[Y] + this.dir[Y] * this.dist[Y] - 0.5,
								pos[X] + this.dir[X] * this.dist[Y], Y);
			if (this.dir[Y] > 0)
				isHit = this.hit(map, pos[Y] + this.dir[Y] * this.dist[Y] + 0.5,
					pos[X] + this.dir[X] * this.dist[Y], Y);
			this.dist[Y] += isHit === CHECK ? this.delta[Y] : 0;
		}
		return isHit;
	}
}

export default Ray;