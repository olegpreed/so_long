/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:18:22 by preed             #+#    #+#             */
/*   Updated: 2022/01/17 21:20:01 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_item_count(char *map)
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	other_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	other_count = 0;
	while (*map != '\0')
	{
		if (*map == 'P')
			p_count++;
		else if (*map == 'E')
			e_count++;
		else if (*map == 'C')
			c_count++;
		else if (*map != '1' && *map != '\n' && *map != '0')
			other_count++;
		map++;
	}
	if (p_count != 1 || e_count == 0 || c_count == 0 || other_count != 0)
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
	if (check_item_count(game->map) || check_map_square(game))
		return (1);
	if (check_walls(game->map))
		return (1);
	return (0);
}
