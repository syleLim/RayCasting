#include "raycaster.h"
#include "player.h"
#include "ray.h"

int raycasting (t_player *player)
{
	int		ray[2];
	int		i;

	i = -1;
	while (++i < SCREEN_W)
	{
		set_ray(ray, player->dir, i, SCREEN_W);
	}
}
