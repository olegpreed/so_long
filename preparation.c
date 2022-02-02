/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:59:23 by preed             #+#    #+#             */
/*   Updated: 2022/02/02 17:33:14 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	random_table(t_root *game)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	x = game->symbolsize.x;
	y = game->symbolsize.y;
	game->random = ft_calloc((((x + 1) * y) + 1), sizeof(int));
	game->random[0] = rand() % 6;
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
	int		fd;
	char	*string[2];

	k = 1;
	game->symbolsize.y = 0;
	fd = open(game->map_path, O_RDONLY);
	if (fd == -1)
		return (1);
	game->map = get_next_line(fd);
	while (k)
	{
		string[0] = game->map;
		string[1] = get_next_line(fd);
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
	return (0);
}

int	preparation(t_root *game, int argc, char **argv)
{
	if (argc != 2)
		return (1);
	game->map_path = argv[1];
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
	game->over = 0;
	return (0);
}
