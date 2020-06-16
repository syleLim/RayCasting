# include "vector.h"

double	get_rad(double angle)
{
	return (angle * (PI / 180));
}

double	vec_len(double vec[2])
{
	return (sqrt(vec[X] * vec[X] + vec[Y] * vec[Y]));
}

double	vec_cos(double v1[2], double v2[2])
{
	return ((v1[X] * v2[X] + v1[Y] * v2[Y]) / (vec_len(v1) * vec_len(v2)));
}

void	vec_rot(double vec[2], double angle)
{
	double temp[2];
	
	temp[X] = vec[X] * cos(get_rad(angle))
				- vec[Y] * sin(get_rad(angle));
	temp[Y] = vec[X] * sin(get_rad(angle))
				+ vec[Y] * cos(get_rad(angle));
	vec[X] = temp[X];
	vec[Y] = temp[Y];
}