#include "raycaster.h"

int MAP[MAP_X][MAP_Y] = { \
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,3,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  \
};

double	get_distance(double dir[2], double ray[2], double dist[2], int flag)
{
	double xy[2];

	xy[X] = flag == X ? ray[X] * dist[X] : ray[X] * dist[Y];
	xy[Y] = flag == X ? ray[Y] * dist[X] : ray[Y] * dist[Y];
	xy[X] = fabs(xy[X]) > INF - 1 ?  0 : xy[X];
	xy[Y] = fabs(xy[Y]) > INF - 1 ?  0 : xy[Y];
	return (vec_len(xy) * fabs(vec_cos(dir, xy)));
}
	
double	caster(double ray[2], double pos[2], double dir[2], int map[MAP_X][MAP_Y])
{
	double	dist[2];
	double	delta[2];
	int		hit;
	
	set_delta_dist(dist, delta, ray, pos);
	hit = CHECK;
	while (hit == CHECK)
	{
		if (dist[X] < dist[Y])
		{
			hit = hit_check_x(map, pos, ray, dist);
			dist[X] += hit == CHECK ? delta[X] : 0;
		}
		else
		{
			hit = hit_check_y(map, pos, ray, dist);
			dist[Y] += hit == CHECK ? delta[Y] : 0;
		}
	}
	return (hit != NON_HIT ? get_distance(dir, ray, dist, hit) : 0);
}

int		raycasting (t_player *player)
{
	double	ray[2];
	int		i;
	double	distance;

	i = -1;
	while (++i < SCREEN_W)
	{
		set_ray(ray, player->dir, i, SCREEN_W);
		distance = caster(ray, player->pos, player->dir, MAP);

		//TODO : draw wall
	}
	
}
