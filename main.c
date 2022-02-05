/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:23 by preed             #+#    #+#             */
/*   Updated: 2022/02/05 20:08:52 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int printfka(t_root *game)
{
	game->random = 0;
	printf("im here!\n");
	return 0;
}

int	main(int argc, char **argv)
{
	t_root	game;

	if (preparation(&game, argc, argv))
		return (1);
	game.mlx_m = mlx_init();
	game.mlx = mlx_init();
	menu(&game);
	mlx_hook(game.mlxw_m, 2, 0, &select, &game);
	mlx_loop_hook(game.mlx_m, &menu_render, &game);
	// if (game.m.k)
	// {
	// 	mlx_destroy_window(game.mlx_m, game.mlxw_m);
	// 	start(&game);
	// 	patrol_init(&game);
	// 	mlx_hook(game.mlxw, 2, 0, &action, &game);
	// 	mlx_hook(game.mlxw, 17, 0, &exit_game, (void *)0);
	// 	mlx_loop_hook(game.mlx, &map, &game);
	// }
	mlx_loop(game.mlx_m);
	mlx_loop(game.mlx);
	return (0);
}

// preparation():
// *.ber to string + checks if map and argv are valid
//
// start():
// initializes images + calculates window size + opens window