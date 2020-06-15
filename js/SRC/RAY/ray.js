const X = 0;
const Y = 0;
const NON_HIT = -1;
const CHECK = -2;

class Ray {
	constructor(dir) {
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

	hit_check(map, y, x, flag) {
		if (y < 0 || x < 0)
			return NON_HIT;
		return map[parseInt(y)][parseInt(x)] != 0 ? flag : CHECK;
	}
}