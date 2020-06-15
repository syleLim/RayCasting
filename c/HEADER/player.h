#ifndef PLAYER_H
# define PLATER_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"


typedef struct	s_player
{
	double		pos[2];
	double		dir[2];
}				t_player;

t_player	*init_player(double pos_x, double pos_y,
							double dir_x, double dir_y);
void		move(double dir[2], double pos[2], double speed);
void		rotate(double dir[2], int flag);
#endif