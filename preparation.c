/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:59:23 by preed             #+#    #+#             */
/*   Updated: 2022/01/21 19:11:58 by preed            ###   ########.fr       */
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
	char	*string1;
	char	*string2;

	k = 1;
	fd = 0;
	game->symbolsize.y = 0;
	fd = open(game->map_path, O_RDONLY);
	if (fd == -1)
		return (1);
	game->map = get_next_line(fd);
	while (k)
	{
		string1 = game->map;
		string2 = get_next_line(fd);
		if (string2)
		{
			game->map = ft_strjoin(game->map, string2);
			free(string1);
			free(string2);
		}
		else
			k = 0;
		game->symbolsize.y++;
	}
	game->symbolsize.x = ft_strlen_n(game->map);
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
	random_table(game);
	return (0);
}
