/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:23 by preed             #+#    #+#             */
/*   Updated: 2022/02/09 18:13:47 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_root	game;

	game.mlx_m = mlx_init();
	game.mlx = mlx_init();
	main_menu(&game);
	mlx_hook(game.mlxw_m, 2, 0, &menu_select, &game);
	mlx_loop_hook(game.mlx_m, &menu_render, &game);
	mlx_loop(game.mlx_m);
	mlx_loop(game.mlx);
	return (0);
}
