#include "player.h"

void	move(double dir[2], double pos[2], double speed)
{
	pos[X] += dir[X] * speed;
	pos[Y] += dir[Y] * speed;
}

void	rotate(double dir[2], double angle)
{
	vec_rot(dir, angle);	
}