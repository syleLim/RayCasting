#include "ray.h"

void	set_ray(double ray[2], double dir[2],
				double i, double width)
{
	double plane[2];
	double ratio;

	//밖으로 빼는 것이 이득(연산량 과부하임)
	plane[X] = -dir[Y] * tan(get_rad(FOV / 2));
	plane[Y] = dir[X] * tan(get_rad(FOV / 2));
	ratio = 2 * i / width -1;
	ray[X] = dir[X] + plane[X] * ratio;
	ray[Y] = dir[Y] + plane[Y] * ratio;
}

