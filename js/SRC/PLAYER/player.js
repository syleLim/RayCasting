const X = 0;
const Y = 1;

class Player {
	constructor (info) {
		this.pos = info.initPos;
		this.dir = info.initDir;
		this.moveSpeed = info.moveSpeed;
		this.rotSpeed = info.rotSpeed;
	}

	move(speed) {
		this.pos = this.pos.map((e, i) =>
			e += this.dir[i] * speed);
	}

	rotate(speed) {
		const angle = speed * Math.PI / 180;
		
		//TODO : have to chcek!
		this.dir = [this.dir[X] * Math.cos(angle)
						- this.dir[Y] * Math.sin(angle),
					this.dir[X] * Math.sin(angle)
						+ this.dir[Y] * Math.sin(angle)];
	}

	behavior(key) {
		if (key === "FORWARD")
			this.move(this.moveSpeed);
		if (key === "BACK")
			this.move(-this.moveSpeed);
		if (key === "LEFT")
			this.rotate(this.rotSpeed);
		if (key === "RIGHT")
			this.rotate(-this.rotSpeed);
	}
}

module.exports = Player;