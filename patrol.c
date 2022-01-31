#include "so_long.h"

void move(char a, t_root *game, int i)
{
	static int j;
	int e = game->thug[i].symbol_index;

	if (j == 20)
	{
		if (a == 'r' && game->map[e + 1] != '1')
		{
			game->thug[i].symbol_index += 1;
			game->thug[i].symbol_loc.x += 1;
			game->thug[i].pixel_loc.x += 64; 
		}
		if (a == 'l' && game->map[e - 1] != '1')
		{
			game->thug[i].symbol_index -= 1;
			game->thug[i].symbol_loc.x -= 1;
			game->thug[i].pixel_loc.x -= 64;
		}
		if (a == 'w' && game->map[e - game->symbolsize.x - 1] != '1')
		{
			game->thug[i].symbol_index -= (game->symbolsize.x + 1);
			game->thug[i].symbol_loc.y -= 1;
			game->thug[i].pixel_loc.y -= 64;
		}
		if (a == 's' && game->map[e + game->symbolsize.x + 1] != '1')
		{
			game->thug[i].symbol_index += (game->symbolsize.x + 1);
			game->thug[i].symbol_loc.y += 1;
			game->thug[i].pixel_loc.y += 64;
		}
	j = 0;
	}
	j++;
}

int check_enemy_vision(int i, int j, t_root *game, char *map)
{
	int my = game->i.max.symbol_loc.y;
	int ty = game->thug[i].symbol_loc.y;
	int e = game->thug[i].symbol_index;
	if (j - e < game->symbolsize.x + 1 && j - e > 0)
	{
		while (e < j)
			if (map[e++] == '1')
				return 0;
		return 1;
	}
	else if (e - j < game->symbolsize.x + 1 && e - j > 0)
	{
		while (j < e)
			if (map[j++] == '1')
				return 0;
		return 2;
	}
	else if (game->i.max.symbol_loc.x == game->thug[i].symbol_loc.x && my > ty)
	{
		while (ty < my)
		{
			if (map[j] == '1')
				return 0;
			j -= (game->symbolsize.x + 1);
			ty += 1;
		}
		return 3;
	}
	else if (game->i.max.symbol_loc.x == game->thug[i].symbol_loc.x && ty > my)
	{
		while (my < ty)
		{
			if (map[j] == '1')
				return 0;
			j += (game->symbolsize.x + 1);
			my += 1;
		}
		return 4;
	}
	return 0;
}

int patrol_move(t_root *game)
{
	int j;
	int i = 0;
	static int e;

	j = game->i.max.symbol_index;
	while(i < game->t_count)
	{
		e = check_enemy_vision(i, j, game, game->map);
		if (e == 1)
			move('r', game, i);
		else if (e == 2)
			move('l', game, i);
		else if (e == 3)
			move('s', game, i);
		else if (e == 4)
			move('w', game, i);
		i++;
	}
	return (0);
}