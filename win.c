/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:24:40 by oleg              #+#    #+#             */
/*   Updated: 2022/02/03 19:48:59 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void win(t_root *game)
{
	game->over = 21;
	game->i.floor.reference = image_ref(game, &(game->i.floor_w));
}