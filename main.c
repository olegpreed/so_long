/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:51:23 by preed             #+#    #+#             */
/*   Updated: 2022/02/02 21:14:30 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_root	game;

	if (preparation(&game, argc, argv))
		return (1);
	game.mlx = mlx_init();
	start(&game);
	patrol_init(&game);
	mlx_hook(game.mlxw, 2, 0, &action, &game);
	mlx_hook(game.mlxw, 17, 0, &exit_game, (void *)0);
	mlx_loop_hook(game.mlx, &map, &game);
	mlx_loop(game.mlx);
	return (0);
}

// preparation():
// *.ber to string + checks if map and argv are valid
//
// start():
// initializes images + calculates window size + opens window