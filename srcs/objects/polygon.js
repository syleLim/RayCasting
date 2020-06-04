import Plane from "./plane"

class Polygon extends Plane {
	constructor(orientation, color, points) {
		super(points[0], orientation, color);
		this.points = points;
	}
}

export default Polygon;