#include "so_long.h"

void	index_to_loc(int i, int j, t_root *game)
{
	game->thug[j].symbol_loc.x = i % (game->symbolsize.x + 1);
	game->thug[j].symbol_loc.y = i / (game->symbolsize.x + 1);
	game->thug[j].pixel_loc.x = game->thug[j].symbol_loc.x * game->i.floor.size.x;
	game->thug[j].pixel_loc.y = game->thug[j].symbol_loc.y * game->i.floor.size.y;
	game->thug[j].symbol_index = i;
}

int patrol_init(t_root *game)
{
	int i = 0;
	int j = 0;
	while(game->map[i] != '\0')
	{
		if (game->map[i] == 'T')
		{
			index_to_loc(i, j, game);
			j++;
			game->map[i] = '0';
		}
		i++;
	}
	return 0;
}