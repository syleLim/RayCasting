const X = 0;
const Y = 1;

exports.vecLen = (vec) => {
	return Math.sqrt(vec[X] * vec[X] + vec[Y] * vec[Y]);
}

exports.vecCos = (v1, v2) => {
	return (v1[X] * v2[X] + v1[Y] * v2[Y]) /
		(Math.sqrt(v1[X] * v1[X] + v1[Y] * v1[Y])
			* Math.sqrt(v2[X] * v2[X] + v2[Y] * v2[Y]));
}

exports.vecRotate = (vec, angle) => {
	const rad = angle * Math.PI / 180;
	const vecRot = [
		vec[X] * Math.cos(rad) - vec[Y] * Math.sin(rad),
		vec[X] * Math.sin(rad) + vec[Y] * Math.cos(rad)
	]
	return (vecRot);
}