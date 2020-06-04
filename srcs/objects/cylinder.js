import Object from "./object"

class Cylinder extends Object {
	constructor (position, orientation, color, height, radius) {
		super(position, orientation, color);
		this.height = height;
		this.radius = radius;
	}
}

export default Cylinder;