#ifndef RAY_H
# define RAY_H
# include "DB.h"
# include "vector.h"
# include <math.h>

void	set_ray(double ray[2], double dir[2],
				double i, double width);
void	zero_delta_dist(double delta[2], double dist[2], int index);
void	nonzero_delta_dist_x(double dist[2], double delta[2],
							double ray[2], double pos[2]);
void	nonzero_delta_dist_y(double dist[2], double delta[2],
							double ray[2], double pos[2]);
void	set_delta_dist(double dist[2], double delta[2],
						double ray[2], double pos[2]);
int		hit_check(int map[MAP_Y][MAP_X], double x, double y, int flag);
int		hit_check_x(int map[MAP_Y][MAP_X], double pos[2],
					double ray[2], double dist[2]);
int		hit_check_y(int map[MAP_Y][MAP_X], double pos[2],
					double ray[2], double dist[2]);
#endif