/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:58:29 by oleg              #+#    #+#             */
/*   Updated: 2022/02/15 19:16:39 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cheat(int keypress, t_root *game)
{
	static int	c;

	if (keypress == 11)
		c++;
	else if (keypress == 32 && c == 1)
		c++;
	else if (keypress == 37 && c == 2)
		c++;
	else if (keypress == 37 && c == 3)
		c++;
	else if (keypress == 6 && c == 4)
		c++;
	else
		c = 0;
	if (c == 5)
		game->cheat = 1;
}

int	scores(t_root *game)
{
	char	*s;
	int		i;

	i = 0;
	game->fd = open("scores/scoreboard", O_RDWR);
	if (game->fd == -1)
		return (1);
	while (i < 21)
	{
		s = get_next_line(game->fd);
		game->m.scores[i++] = ft_atoi(s);
		free(s);
	}
	close(game->fd);
	return (0);
}

void	num_init(t_root *game)
{
	game->m.num[0].path = "./images/0.xpm";
	game->m.num[0].ref = image_ref(game, &(game->m.num[0]));
	game->m.num[1].path = "./images/1.xpm";
	game->m.num[1].ref = image_ref(game, &(game->m.num[1]));
	game->m.num[2].path = "./images/2.xpm";
	game->m.num[2].ref = image_ref(game, &(game->m.num[2]));
	game->m.num[3].path = "./images/3.xpm";
	game->m.num[3].ref = image_ref(game, &(game->m.num[3]));
	game->m.num[4].path = "./images/4.xpm";
	game->m.num[4].ref = image_ref(game, &(game->m.num[4]));
	game->m.num[5].path = "./images/5.xpm";
	game->m.num[5].ref = image_ref(game, &(game->m.num[5]));
	game->m.num[6].path = "./images/6.xpm";
	game->m.num[6].ref = image_ref(game, &(game->m.num[6]));
	game->m.num[7].path = "./images/7.xpm";
	game->m.num[7].ref = image_ref(game, &(game->m.num[7]));
	game->m.num[8].path = "./images/8.xpm";
	game->m.num[8].ref = image_ref(game, &(game->m.num[8]));
	game->m.num[9].path = "./images/9.xpm";
	game->m.num[9].ref = image_ref(game, &(game->m.num[9]));
}

void	menu_sprites_init2(t_root *game)
{
	game->i.max_b.path = "./images/max_b.xpm";
	game->i.max_b.ref = image_ref(game, &(game->i.max_b));
	game->m.crazy[0].path = "./images/crazy1.xpm";
	game->m.crazy[0].ref = image_ref(game, &(game->m.crazy[0]));
	game->m.rap[0].path = "./images/rap1.xpm";
	game->m.rap[0].ref = image_ref(game, &(game->m.rap[0]));
	game->m.crazy[1].path = "./images/crazy2.xpm";
	game->m.crazy[1].ref = image_ref(game, &(game->m.crazy[1]));
	game->m.rap[1].path = "./images/rap2.xpm";
	game->m.rap[1].ref = image_ref(game, &(game->m.rap[1]));
}

void	menu_sprites_init(t_root *game)
{
	game->m.menu.path = "./images/menu.xpm";
	game->m.menu.ref = image_ref(game, &(game->m.menu));
	game->m.select.path = "./images/select.xpm";
	game->m.select.ref = image_ref(game, &(game->m.select));
	game->i.sec.path = "./images/sec.xpm";
	game->i.sec.ref = image_ref(game, &(game->i.sec));
	game->i.sec2.path = "./images/sec2.xpm";
	game->i.sec2.ref = image_ref(game, &(game->i.sec2));
	game->i.fence.path = "./images/fence.xpm";
	game->i.fence.ref = image_ref(game, &(game->i.fence));
	game->m.bullz.path = "./images/bullz.xpm";
	game->m.bullz.ref = image_ref(game, &(game->m.bullz));
	game->i.max.path = "./images/max.xpm";
	game->i.max.ref = image_ref(game, &(game->i.max));
	game->i.max2.path = "./images/max2.xpm";
	game->i.max2.ref = image_ref(game, &(game->i.max2));
	game->m.roof.path = "./images/roof.xpm";
	game->m.roof.ref = image_ref(game, &(game->m.roof));
	menu_sprites_init2(game);
}
