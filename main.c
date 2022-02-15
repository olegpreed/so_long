/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:23 by preed             #+#    #+#             */
/*   Updated: 2022/02/15 17:15:40 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_root	game;

	game.mlx = mlx_init();
	main_menu(&game);
	mlx_hook(game.mlxw_m, 2, 0, &menu_select, &game);
	mlx_loop_hook(game.mlx, &menu_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
