#include "raycaster.h"

int main()
{
	t_player	*player;

	if (!(player = init_player(INIT_POS_X, INIT_POS_Y,
								INIT_DIR_X, INIT_DIR_Y)))
		return (0);
	printf("dir : %.2f %.2f\npos : %.2f, %.2f\n", player->dir[X], player->dir[Y], player->pos[X], player->pos[Y]);
	raycasting(player);
	free(player);
}