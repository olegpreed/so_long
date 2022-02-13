/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:18:22 by preed             #+#    #+#             */
/*   Updated: 2022/02/13 15:01:38 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_init(t_root *game)
{
	int	i;

	i = game->t_count;
	game->thug = (t_image *)malloc(i * sizeof(t_image));
	if (game->thug == 0)
		printf("t_count = %d\n ,malloc !\n", game->t_count);
}

int	check_item_count(char *map, t_root *game)
{
	int	count[4];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	game->t_count = 0;
	while (*map != '\0')
	{
		if (*map == 'P')
			count[0]++;
		else if (*map == 'E')
			count[1]++;
		else if (*map == 'C')
			count[2]++;
		else if (*map == 'T')
			game->t_count++;
		else if (*map != '1' && *map != '\n' && *map != '0')
			count[3]++;
		map++;
	}
	if (count[0] != 1 || !count[1] || !count[2] || count[3])
		return (1);
	return (0);
}

int	check_map_square(t_root *game)
{
	int		i;
	size_t	line_length;
	char	*mapcopy;

	i = 0;
	mapcopy = game->map;
	while (i < (game->symbolsize.y - 1))
	{
		line_length = ft_strlen_n(mapcopy);
		mapcopy += line_length + 1;
		if (line_length != ft_strlen_n(mapcopy))
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		if (map[i++] != '1')
			return (1);
	while (map[i] != '\0')
	{
		if (map[i] == '\n' && (map[i - 1] != '1' || map[i + 1] != '1'))
			return (1);
		i++;
	}
	while (map[--i] != '\n')
		if (map[i] != '1')
			return (1);
	return (0);
}

int	check_valid_map(t_root *game)
{
	if (game->symbolsize.y <= 2)
		return (1);
	if (check_item_count(game->map, game) || check_map_square(game))
		return (1);
	if (check_walls(game->map))
		return (1);
	enemy_init(game);
	return (0);
}
