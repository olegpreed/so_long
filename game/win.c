/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:24:40 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 19:26:12 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_img(t_root *game, void *img, int x, int y)
{
	void	*mlx;
	void	*mlxw;

	mlx = game->mlx;
	mlxw = game->mlxw;
	mlx_put_image_to_window(mlx, mlxw, img, x, y);
}

void	new_score_display(t_root *game, int x, int y)
{
	int	c;

	y += 50;
	x += 80;
	c = game->score;
	mlx_img(game, game->m.num[c / 1000].ref, x, y);
	mlx_img(game, game->m.num[c % 1000 / 100].ref, x + 35, y);
	mlx_img(game, game->m.num[c % 100 / 10].ref, x + 70, y);
	mlx_img(game, game->m.num[c % 10].ref, x + 105, y);
}

void	display_score(t_root *game)
{
	int	x;
	int	y;
	int	h;
	int	w;

	x = game->pixelsize.x / 2;
	y = game->pixelsize.y / 2;
	w = game->i.gameover.size.x;
	h = game->i.gameover.size.y;
	if (!game->k)
		mlx_img(game, game->i.newhigh.ref, x - w / 2 + 10, y - h / 2);
	else
		mlx_img(game, game->i.newhigh2.ref, x - w / 2 + 10, y - h / 2);
	new_score_display(game, x - w / 2 + 10, y - h / 2);
}

void	new_scoreboard(t_root *game)
{
	int		i;
	char	s[105];
	char	*l;
	char	*n;
	char	*p;

	i = (game->m.lvl - 1) * 5;
	ft_strlcpy(s, &(game->scoreboard[0]), i + 1);
	s[i] = '\0';
	n = ft_itoa(game->score);
	i = ft_strlen(n);
	p = ft_calloc(4 - i + 1, sizeof(char));
	ft_memset(p, '0', 4 - i);
	l = ft_strjoin(s, p);
	free(p);
	p = ft_strjoin(l, n);
	free(l);
	free(n);
	i = (game->m.lvl - 1) * 5 + 4;
	n = ft_strjoin(p, &(game->scoreboard[i]));
	free(p);
	game->scoreboard = n;
}

int	win(t_root *game)
{
	int	i;

	i = game->i.max.symbol_index;
	game->map[i] = 'L';
	game->i.lady_w.ref = image_ref(game, &(game->i.pair));
	game->fd = open("scores/scoreboard", O_RDWR);
	if (game->fd == -1)
		return (1);
	game->status = WIN;
	game->i.floor.ref = image_ref(game, &(game->i.floor_w));
	if (game->score < game->record || !game->record)
	{
		game->status = RECORD;
		new_scoreboard(game);
		write(game->fd, game->scoreboard, ft_strlen(game->scoreboard));
	}
	return (0);
}
