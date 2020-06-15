const X = 0;
const Y = 1;

class Map  {
	constructor (MAP) {
		this.y = MAP.y;
		this.x = MAP.x;
		this.map = MAP.map;
		this.plane = [0, 0];
	}

	set_plane(dir, fov) {
		const angle = (fov / 2) * (Math.PI / 180);

		this.plane = [ -dir[Y] * Math.tan(angle),
						dir[X] * Math.tan(angle)];
	}
}