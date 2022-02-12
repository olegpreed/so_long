/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:55:32 by oleg              #+#    #+#             */
/*   Updated: 2022/02/10 18:32:07 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*level_name(t_root *game, int x, int y)
{
	if (game->m.lvl == 1)
		return (mlx_new_window(game->mlx, x, y, "01 - First time in the club"));
	else
		return (mlx_new_window(game->mlx, x, y, "02 - Approach"));
}
