#include "raycaster.h"
#include "ray.h"

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

void	zero_delta_dist(double delta[2], double dist[2], int index)
{
	delta[index] = 0.;
	dist[index] = INF;
}

void	nonzero_delta_dist_x(double dist[2], double delta[2],
							double ray[2], double pos[2])
{
	dist[X] = ray[X] > 0 ? (fabs(pos[X]) - pos[X]) / ray[X] :
		(pos[X] - fabs(pos[X] + 1.)) / ray[X];
	delta[X] = ray[X] > 0 ? -1. / ray[X] : -1. / ray[X];	
}

void	nonzero_delta_dist_y(double dist[2], double delta[2],
							double ray[2], double pos[2])
{
	dist[Y] = ray[Y] > 0 ? (fabs(pos[Y]) - pos[Y]) / ray[Y] :
		(pos[Y] - fabs(pos[Y] + 1.) ) / ray[Y];
	delta[Y] = ray[Y] > 0 ? -1. / ray[Y] : -1. / ray[Y];
}

void	set_delta_dist(double dist[2], double delta[2], double ray[2],
						double pos[2])
{
	if (ray[X] == 0.)
		zero_delta_dist(dist, delta, X);
	else
		nonzero_delta_dist_x(dist, delta, ray, pos);
	if (ray[Y] == 0.)
		zero_delta_dist(dist, delta, Y);
	else
		nonzero_delta_dist_y(dist, delta, ray, pos);
}

double vec_len(double vec[2])
{
	return (sqrt(vec[X] * vec[X] + vec[Y] * vec[Y]));
}

double vec_cos(double v1[2], double v2[2])
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y]) / (vec_len(v1) * vec_len(v2));
}

double	get_distance(double dir[2], double ray[2], double dist[2], int flag)
{
	double xy[2];

	xy[X] = flag == X ? ray[X] * dist[X] : ray[X] * dist[Y];
	xy[Y] = flag == X ? ray[Y] * dist[X] : ray[Y] * dist[Y];
	xy[X] = fabs(xy[X]) > INF - 1 ?  0 : xy[X];
	xy[Y] = fabs(xy[Y]) > INF - 1 ?  0 : xy[Y];
	printf("ray %.3f %.3f\n", ray[X], ray[Y]);
	printf("dist %.3f %.3f\n", dist[X], dist[Y]);
	printf("xy %.3f %.3f\n", xy[X], xy[Y]);
	printf("cos %.3f\n", vec_cos(dir, xy));
	return (vec_len(xy) * fabs(vec_cos(dir, xy)));
}

int		hit_check(int map[MAP_X][MAP_Y], double x, double y, int flag)
{
	//printf("%d %d\n", (int)floor(x), (int)floor(y));
	if ((int)floor(y) < 0 || (int)floor(x) < 0)
		return (NON_HIT);
	if (map[(int)floor(y)][(int)floor(x)] == 1)
	  	printf("      %d %d\n", (int)floor(y), (int)floor(x));
	return (map[(int)floor(y)][(int)floor(x)] != 0 ? flag : CHECK);
}

	// posX + rayX * distX < posY + rayY * distX ? cal x : cal y;
		// x case :
		// 	  dirX < 0 map[반올림(posX + rayX * distX - 1)][floor(posY + rayY * distX)]
		// 	  dirX > 0 map[반올림(posX + rayX * distX)][floor(posY + rayY * distX)]
		// y case :
		//	  dirY < 0 map[floor(posX + rayX * distY)][반올림(posY + rayY * distY - 1)]
		//	  dirY > 0 map[floor(posX + rayX * distY)][반올림(posY + rayY * distY)]
	
double	caster(double ray[2], double pos[2], double dir[2], int map[MAP_X][MAP_Y])
{
	double	dist[2];
	double	delta[2];
	int		hit;
	
	set_delta_dist(dist, delta, ray, pos);
	//printf("dist : %.3f %.3f\ndelta : %.3f %.3f\n", dist[X], dist[Y], delta[X], delta[Y]);
	hit = CHECK;
	while (hit == CHECK)
	{
		if (fabs(ray[X] * dist[X]) < fabs(ray[X] * dist[Y]))
		{
			if (dir[X] < 0)
				hit = hit_check(map, pos[X] + ray[X] * dist[X] - 0.5, 
								pos[Y] + ray[Y] * dist[X], X);
			if (dir[X] > 0)
				hit = hit_check(map, pos[X] + ray[X] * dist[X] + 0.5,
								pos[Y] + ray[Y] * dist[X], X);
			dist[X] += delta[X];
		}
		else
		{
			if (dir[Y] < 0)
				hit = hit_check(map, pos[X] + ray[X] * dist[Y],
								pos[Y] + ray[Y] * dist[Y]- 0.5, Y);
			if (dir[Y] > 0)
				hit = hit_check(map, pos[X] + ray[X] * dist[Y],
								pos[Y] + ray[Y] * dist[Y] + 0.5, Y);
			dist[Y] += delta[Y];
		}
	}
	//printf("dist : %.3f %.3f\n", dist[X], dist[Y]);
	return (hit != NON_HIT ? get_distance(dir, ray, dist, hit) : 0);
	
	//TODO : dir이 음수, 양수일때의 올림 반올림 연산이 다르다. 해당 부분을 분리할 것인지 아니면
	//			한번에 묶을 수 있는 모듈을 찾을 것 인지 정리해두어야 한다.
	//int xy[2] = {ray[X] * b, ray[Y] * a}; 
	//TODO : distance = len(xy) * cos(angle(dir, xy))
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
		
		//printf("ray : %.3f %.3f\n", ray[X], ray[Y]);
		distance = caster(ray, player->pos, player->dir, MAP);
		
		printf("%d : distance %.4f\n", i, distance);
	}
}
