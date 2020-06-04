import Plane from "./plane"

class Triangle extends Plane {
	constructor(orientation, color, points) {
		super(points[0], orientation, color);
		this.points = points;
	}
}

export default Triangle;