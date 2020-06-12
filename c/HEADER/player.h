#ifndef PLAYER_H
# define PLATER_H
# include <stdlib.h>
# include "DB.h"

typedef struct	s_player
{
	double		pos[2];
	double		dir[2];
}				t_player;

t_player	*init_player(double pos_x, double pos_y,
							double dir_x, double dir_y);

#endif