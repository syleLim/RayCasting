#include "raycaster.h"
#include "player.h"

int main()
{
	t_player	*player;

	if (!(player = init_player(INIT_POS_X, INIT_POS_Y,
								INIT_DIR_X, INIT_DIR_Y)))
		return (NULL);
}