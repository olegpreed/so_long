/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:59:23 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 17:17:40 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_to_string(t_root *game)
{
	int		k;
	int		fd;
	char	*string1;
	char	*string2;

	k = 1;
	fd = 0;
	game->symbolsize.y = 0;
	fd = open(game->map_path, O_RDONLY);
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
}

int	preparation(t_root *game, int argc, char **argv)
{
	if (argc != 2)
		return (1);
	game->map_path = argv[1];
	map_to_string(game);
	if (check_valid_map(game))
	{
		printf("Error\nInvalid map\n");
		return (1);
	}
	return (0);
}
