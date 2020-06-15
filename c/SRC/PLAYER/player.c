#include "player.h"

t_player	*init_player(double pos_x, double pos_y,
							double dir_x, double dir_y)
{
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		return (NULL);
	player->pos[X] = pos_x;
	player->pos[Y] = pos_y;
	player->dir[X] = dir_x;
	player->dir[Y] = dir_y;
	return (player);
}

void		behavior(t_player *player, int key)
{
	if (key == FORWARD)
		move(player->dir, player->pos, MOVE_SPEED);
	if (key == BACK)
		move(player->dir, player->pos, -MOVE_SPEED);
	if (key == LEFT)
		rotate(player->dir, ROT_SPEED);
	if (key == RIGHT)
		rotate(player->dir, -ROT_SPEED);
}