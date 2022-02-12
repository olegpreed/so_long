/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:27:15 by oleg              #+#    #+#             */
/*   Updated: 2022/02/12 15:11:25 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	s_num_init(t_root *game)
{
	game->i.s_num[0].path = "./images/0s.xpm";
	game->i.s_num[0].ref = image_ref(game, &(game->i.s_num[0]));
	game->i.s_num[1].path = "./images/1s.xpm";
	game->i.s_num[1].ref = image_ref(game, &(game->i.s_num[1]));
	game->i.s_num[2].path = "./images/2s.xpm";
	game->i.s_num[2].ref = image_ref(game, &(game->i.s_num[2]));
	game->i.s_num[3].path = "./images/3s.xpm";
	game->i.s_num[3].ref = image_ref(game, &(game->i.s_num[3]));
	game->i.s_num[4].path = "./images/4s.xpm";
	game->i.s_num[4].ref = image_ref(game, &(game->i.s_num[4]));
	game->i.s_num[5].path = "./images/5s.xpm";
	game->i.s_num[5].ref = image_ref(game, &(game->i.s_num[5]));
	game->i.s_num[6].path = "./images/6s.xpm";
	game->i.s_num[6].ref = image_ref(game, &(game->i.s_num[6]));
	game->i.s_num[7].path = "./images/7s.xpm";
	game->i.s_num[7].ref = image_ref(game, &(game->i.s_num[7]));
	game->i.s_num[8].path = "./images/8s.xpm";
	game->i.s_num[8].ref = image_ref(game, &(game->i.s_num[8]));
	game->i.s_num[9].path = "./images/9s.xpm";
	game->i.s_num[9].ref = image_ref(game, &(game->i.s_num[9]));
}

void	sprites_init4(t_root *game)
{
	game->i.max.path = "./images/max.xpm";
	game->i.max.ref = image_ref(game, &(game->i.max));
	game->i.max_o.path = "./images/max_over.xpm";
	game->i.max_o.ref = image_ref(game, &(game->i.max_o));
	game->i.max_o.pixel_loc.x = 0;
	game->i.max_o.pixel_loc.y = 0;
	game->i.max_l.path = "./images/max_l.xpm";
	game->i.max_l.ref = image_ref(game, &(game->i.max_l));
	game->i.max_r.path = "./images/max_r.xpm";
	game->i.max_r.ref = image_ref(game, &(game->i.max_r));
	game->i.max_b.path = "./images/max_b.xpm";
	game->i.max_b.ref = image_ref(game, &(game->i.max_b));
	game->i.max_d.path = "./images/max_d.xpm";
	game->i.max_d.ref = image_ref(game, &(game->i.max_d));
	game->i.speak.path = "./images/speaker.xpm";
	game->i.speak.ref = image_ref(game, &(game->i.speak));
	game->i.speak2.path = "./images/speaker2.xpm";
	game->i.speak2.ref = image_ref(game, &(game->i.speak2));
	game->i.lady.path = "./images/lady.xpm";
	game->i.lady.ref = image_ref(game, &(game->i.lady));
	game->i.lady_w.path = "./images/lady_w.xpm";
	game->i.lady_w.ref = image_ref(game, &(game->i.lady_w));
	game->i.lady.pixels = ft_strchr(game->map, 'E');
	s_num_init(game);
	playerlocation(game);
}

void	sprites_init3(t_root *game)
{
	game->i.c.coke[0].path = "./images/coke.xpm";
	game->i.c.coke[0].ref = image_ref(game, &(game->i.c.coke[0]));
	game->i.c.goth[0].path = "./images/goth.xpm";
	game->i.c.goth[0].ref = image_ref(game, &(game->i.c.goth[0]));
	game->i.c.goth[1].path = "./images/goth2.xpm";
	game->i.c.goth[1].ref = image_ref(game, &(game->i.c.goth[1]));
	game->i.c.hair[0].path = "./images/hair.xpm";
	game->i.c.hair[0].ref = image_ref(game, &(game->i.c.hair[0]));
	game->i.c.hair[1].path = "./images/hair2.xpm";
	game->i.c.hair[1].ref = image_ref(game, &(game->i.c.hair[1]));
	game->i.c.naked[0].path = "./images/naked.xpm";
	game->i.c.naked[0].ref = image_ref(game, &(game->i.c.naked[0]));
	game->i.c.naked[1].path = "./images/naked2.xpm";
	game->i.c.naked[1].ref = image_ref(game, &(game->i.c.naked[1]));
	game->i.c.tired[0].path = "./images/tired.xpm";
	game->i.c.tired[0].ref = image_ref(game, &(game->i.c.tired[0]));
	game->i.c.tired[1].path = "./images/tired2.xpm";
	game->i.c.tired[1].ref = image_ref(game, &(game->i.c.tired[1]));
	game->i.c.rapper[0].path = "./images/rapper.xpm";
	game->i.c.rapper[0].ref = image_ref(game, &(game->i.c.rapper[0]));
	game->i.c.rapper[1].path = "./images/rapper2.xpm";
	game->i.c.rapper[1].ref = image_ref(game, &(game->i.c.rapper[1]));
	sprites_init4(game);
}

void	sprites_init2(t_root *game)
{
	game->i.wall.path = "./images/wall.xpm";
	game->i.wall.ref = image_ref(game, &(game->i.wall));
	game->i.door.path = "./images/door.xpm";
	game->i.door.ref = image_ref(game, &(game->i.door));
	game->i.door_o.path = "./images/door_o.xpm";
	game->i.door_o.ref = image_ref(game, &(game->i.door_o));
	game->i.beer.path = "./images/beer.xpm";
	game->i.beer.ref = image_ref(game, &(game->i.beer));
	game->i.fence.path = "./images/fence.xpm";
	game->i.fence.ref = image_ref(game, &(game->i.fence));
	game->i.shadow_b.path = "./images/shadow_b.xpm";
	game->i.shadow_b.ref = image_ref(game, &(game->i.shadow_b));
	game->i.gameover.path = "./images/gameover.xpm";
	game->i.gameover.ref = image_ref(game, &(game->i.gameover));
	game->i.continue_s.path = "./images/continue.xpm";
	game->i.continue_s.ref = image_ref(game, &(game->i.continue_s));
	game->i.newhigh.path = "./images/newhigh.xpm";
	game->i.newhigh.ref = image_ref(game, &(game->i.newhigh));
	game->i.newhigh2.path = "./images/newhigh2.xpm";
	game->i.newhigh2.ref = image_ref(game, &(game->i.newhigh2));
	game->i.pair.path = "./images/pair.xpm";
	game->i.pair.ref = image_ref(game, &(game->i.pair));
	game->i.heart.path = "./images/heart.xpm";
	game->i.heart.ref = image_ref(game, &(game->i.heart));
	sprites_init3(game);
}

void	sprites_init(t_root *game)
{
	int	i;

	i = 0;
	while (i < game->t_count)
	{
		game->thug[i].path = "./images/thug.xpm";
		game->thug[i].ref = image_ref(game, &(game->thug[i]));
		i++;
	}
	game->i.floor.path = "./images/floor.xpm";
	game->i.floor.ref = image_ref(game, &(game->i.floor));
	game->i.floor_w.path = "./images/tile_w.xpm";
	game->i.floor_w.ref = image_ref(game, &(game->i.floor_w));
	game->i.floor_c.path = "./images/tile2.xpm";
	game->i.floor_c.ref = image_ref(game, &(game->i.floor_c));
	game->i.dj.path = "./images/dj.xpm";
	game->i.dj.ref = image_ref(game, &(game->i.dj));
	game->i.dj2.path = "./images/dj2.xpm";
	game->i.dj2.ref = image_ref(game, &(game->i.dj2));
	game->i.dj3.path = "./images/dj3.xpm";
	game->i.dj3.ref = image_ref(game, &(game->i.dj3));
	game->i.redbull.path = "./images/redbull.xpm";
	game->i.redbull.ref = image_ref(game, &(game->i.redbull));
	sprites_init2(game);
}
