#include "ray.h"

int		hit_check(int map[MAP_Y][MAP_X], double x, double y, int flag)
{
	if ((int)floor(y) < 0 || (int)floor(x) < 0 ||
		y >  MAP_Y - 1 || x > MAP_X - 1)
		return (NON_HIT);
	return (map[(int)floor(y)][(int)floor(x)] != 0 ? flag : CHECK);
}

int		hit_check_x(int map[MAP_Y][MAP_X], double pos[2],
					double ray[2], double dist[2])
{
	int hit;

	hit = CHECK;
	if (ray[X] < 0)
		hit = hit_check(map, pos[X] + ray[X] * dist[X] - 0.5, 
						pos[Y] + ray[Y] * dist[X], X);
	if (ray[X] > 0)
		hit = hit_check(map, pos[X] + ray[X] * dist[X] + 0.5,
						pos[Y] + ray[Y] * dist[X], X);
	return (hit);
}

int		hit_check_y(int map[MAP_Y][MAP_X], double pos[2],
					double ray[2], double dist[2])
{
	int hit;

	hit = CHECK;
	if (ray[Y] < 0)
		hit = hit_check(map, pos[X] + ray[X] * dist[Y],
						pos[Y] + ray[Y] * dist[Y] - 0.5, Y);
	if (ray[Y] > 0)
		hit = hit_check(map, pos[X] + ray[X] * dist[Y],
						pos[Y] + ray[Y] * dist[Y] + 0.5, Y);
	return (hit);
}