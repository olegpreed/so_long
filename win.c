/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:24:40 by oleg              #+#    #+#             */
/*   Updated: 2022/02/08 18:30:50 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_score_display(t_root *game, int x, int y)
{
	int	c;

	y += 50;
	x += 80;
	c = game->score;
	mlx_put_image_to_window(game->mlx, game->mlxw, game->m.numbers[c / 1000].reference, x, y);
	mlx_put_image_to_window(game->mlx, game->mlxw, game->m.numbers[c % 1000 / 100].reference, x + 35, y);
	mlx_put_image_to_window(game->mlx, game->mlxw, game->m.numbers[c % 100 / 10].reference, x + 70, y);
	mlx_put_image_to_window(game->mlx, game->mlxw, game->m.numbers[c % 10].reference, x + 105, y);
}


void	display_score(t_root *game)
{
	int	x;
	int	y;
	int h;
	int w;

	x = game->pixelsize.x / 2;
	y = game->pixelsize.y / 2;
	w = game->i.gameover.size.x;
	h = game->i.gameover.size.y;
	if (!game->k)
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.newhigh.reference, x - w / 2 + 10, y - h / 2);
	else
		mlx_put_image_to_window(game->mlx, game->mlxw, game->i.newhigh2.reference, x - w / 2 + 10, y - h / 2);
	new_score_display(game, x - w / 2 + 10, y - h / 2);
}

void	new_scoreboard(t_root *game)
{
	int i;
	int j;
	char s[105];
	char *l;
	char *n;
	char *p;
	
	i = 1;
	j = 0;
	while(i < game->m.lvl)
	{
		if (game->scoreboard[j++] == '\n')
			i++;
	}
	ft_strlcpy(s, &(game->scoreboard[0]), j + 1);
	s[j] = '\0';
	n = ft_itoa(game->score);
	i = ft_strlen(n);
	p = ft_calloc(4 - i + 1, sizeof(char));
	ft_memset(p, '0', 4 - i);
	l = ft_strjoin(s, p);
	l = ft_strjoin(l, n);
	free(n);
	j += ft_strlen_n(&(game->scoreboard[j]));
	n = ft_strjoin(l, &(game->scoreboard[j]));
	game->scoreboard = n;
}

int win(t_root *game)
{
	game->fd = open("scoreboard", O_RDWR);
	if (game->fd == -1)
		return (1);
	game->over = 21;
	game->i.floor.reference = image_ref(game, &(game->i.floor_w));
	if (game->score < game->record || !game->record)
	{
		game->over = 100;
		new_scoreboard(game);
		write(game->fd, game->scoreboard, ft_strlen(game->scoreboard));
	}
	return (0);
}
