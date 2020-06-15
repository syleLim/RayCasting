#include "ray.h"

void	zero_delta_dist(double delta[2], double dist[2], int index)
{
	delta[index] = 0.;
	dist[index] = INF;
}

void	nonzero_delta_dist_x(double dist[2], double delta[2],
							double ray[2], double pos[2])
{
	dist[X] = ray[X] > 0 ? fabs((pos[X] - floor(pos[X])) / ray[X]) :
		fabs((floor(pos[X] + 1.) - pos[X]) / ray[X]);
	delta[X] = fabs(1. / ray[X]);
}

void	nonzero_delta_dist_y(double dist[2], double delta[2],
							double ray[2], double pos[2])
{
	dist[Y] = ray[Y] > 0 ? fabs((pos[Y] - floor(pos[Y])) / ray[Y]) :
		fabs((floor(pos[Y] + 1.) - pos[Y]) / ray[Y]);
	delta[Y] = fabs(1. / ray[Y]);
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