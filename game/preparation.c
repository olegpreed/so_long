/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:59:23 by preed             #+#    #+#             */
/*   Updated: 2022/02/15 19:10:09 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	next_level(t_root *game)
{
	int	i;

	i = 0;
	game->m.lvl++;
	mlx_destroy_window(game->mlx, game->mlxw);
	free(game->map);
	free(game->copy_map);
	if (preparation(game))
		exit_game();
	while (i < game->t_count)
	{
		game->thug[i].path = "./images/thug.xpm";
		game->thug[i].ref = image_ref(game, &(game->thug[i]));
		i++;
	}
	game->window = GAME;
	game->close_level = 0;
	game->i.floor.ref = image_ref(game, &(game->i.floor));
	game->i.lady_w.ref = image_ref(game, &(game->i.lady_w));
	start(game, 1);
	patrol_init(game);
	mlx_hook(game->mlxw, 2, 0, &action, game);
	mlx_hook(game->mlxw, 17, 0, &exit_game, (void *)0);
	mlx_loop_hook(game->mlx, &map, game);
}

void	random_table(t_root *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = game->symbolsize.x;
	y = game->symbolsize.y;
	game->random = ft_calloc((((x + 1) * y) + 1), sizeof(int));
	while (i < (x + 1) * y)
	{
		game->random[i] = rand() % 6;
		while (game->random[i] == game->random[i - 1])
			game->random[i] = rand() % 6;
		i++;
	}
}

int	map_to_string(t_root *game)
{
	int		k;
	char	*string[2];

	k = 1;
	game->symbolsize.y = 0;
	game->fd = open(game->map_path, O_RDONLY);
	if (game->fd == -1)
		return (1);
	game->map = get_next_line(game->fd);
	while (k)
	{
		string[0] = game->map;
		string[1] = get_next_line(game->fd);
		if (string[1])
		{
			game->map = ft_strjoin(game->map, string[1]);
			free(string[0]);
			free(string[1]);
		}
		else
			k = 0;
		game->symbolsize.y++;
	}
	close(game->fd);
	return (0);
}

char	*int_to_map(t_root *game)
{
	char	*s;
	char	*path;

	path = ft_strdup("maps/map_xx.ber");
	s = ft_itoa(game->m.lvl);
	if (ft_strlen(s) == 1)
	{
		path[9] = '0';
		path[10] = s[0];
	}
	else
	{
		path[9] = s[0];
		path[10] = s[1];
	}
	return (path);
}

int	preparation(t_root *game)
{
	game->map_path = int_to_map(game);
	printf("%s is loaded\n", game->map_path);
	if (map_to_string(game))
	{
		printf("Error\nCould not read the file\n");
		return (1);
	}
	if (check_valid_map(game))
	{
		printf("Error\nInvalid map\n");
		return (1);
	}
	game->symbolsize.x = ft_strlen_n(game->map);
	game->map[game->symbolsize.x / 2 - 1] = 'D';
	random_table(game);
	game->status = NORMAL;
	game->copy_map = ft_strdup(game->map);
	return (0);
}
