const X = 0;
const Y = 1;

class Screen {
	constructor (info) {
		this.width = info.width;
		this.height = info.height;
		this.wall = [];
	}

	setWall(index, length, isHit) {
		this.wall.push({
			index	: index,
			start	: this.height / 2 - ((1 / length) / 2) * this.width,
			end		: this.height / 2 + ((1 / length) / 2) * this.width,
			r	: isHit === X ? 0x77 : 0x33,
			g	: isHit === X ? 0x77 : 0x33,
			b	: isHit === X ? 0x77 : 0x33,
			a	: 255,
		})
	}

	flushWall() {
		this.wall = [];
	}
}

module.exports = Screen;