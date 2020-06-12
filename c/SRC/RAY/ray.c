#include "ray.h"

void	set_ray(double ray[2], double dir[2],
				double i, double width)
{
	double plane[2];
	double ratio;

	//나중에 계산으로 바꿀 예정
	plane[X] = 0;plane[Y] = 0.66;
	ratio = 2 * i / width -1;
	ray[X] = dir[X] + plane[X] * ratio;
	ray[Y] = dir[Y] + plane[Y] * ratio;
}