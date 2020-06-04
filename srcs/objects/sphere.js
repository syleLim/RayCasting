import Object from "./object"

class Sphere extends Object {
	constructor(position, orientation, color, radius) {
		super(position, orientation, color);
		this.radius = radius;
	}
}

export default Shpere;