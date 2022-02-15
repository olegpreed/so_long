/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:25:38 by preed             #+#    #+#             */
/*   Updated: 2022/02/15 18:25:13 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "minilibx/mlx.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define U 126
# define L 123
# define DN 125
# define R 124
# define ESC 53
# define CLOSE 17

# define MAIN_MENU 11
# define LEVEL_SELECT 22
# define GAME 33

# define OVER 99
# define WIN 88
# define RECORD 77
# define NORMAL 66
# define CONTINUE 55
# define MENU 44

# define DRUNK 1
# define SOBER 0

typedef struct s_vector
{
	int		x;
	int		y;
}				t_vector;

typedef struct s_image {
	void		*ref;
	char		*pixels;
	t_vector	size;
	t_vector	pixel_loc;
	t_vector	symbol_loc;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*path;
	int			symbol_index;
}				t_image;

typedef struct s_crowd {
	t_image		coke[2];
	t_image		goth[2];
	t_image		rapper[2];
	t_image		naked[2];
	t_image		tired[2];
	t_image		hair[2];
}				t_crowd;

typedef struct s_images {
	t_image		floor;
	t_image		floor_c;
	t_image		floor_w;
	t_image		wall;
	t_image		lady;
	t_image		lady_w;
	t_image		max;
	t_image		max2;
	t_image		max_b;
	t_image		max_o;
	t_image		max_r;
	t_image		max_l;
	t_image		max_d;
	t_image		speak;
	t_image		sec;
	t_image		sec2;
	t_image		speak2;
	t_crowd		c;
	t_image		redbull;
	t_image		dj;
	t_image		dj2;
	t_image		dj3;
	t_image		door;
	t_image		fence;
	t_image		door_o;
	t_image		shadow_b;
	t_image		beer;
	t_image		gameover;
	t_image		gameover_s;
	t_image		continue_s;
	t_image		newhigh;
	t_image		newhigh2;
	t_image		s_num[10];
	t_image		heart;
	t_image		pair;
}				t_images;

typedef struct t_menu {
	char		lvl;
	t_image		select;
	t_image		menu;
	t_image		num[10];
	t_image		level;
	t_image		score;
	t_image		bullz;
	t_image		roof;
	t_image		crazy[2];
	t_image		rap[2];
	int			scores[21];
}				t_menu;

typedef struct s_root {
	void		*mlx;
	void		*mlxw_m;
	void		*mlxw;
	char		*map_path;
	t_image		*thug;
	t_menu		m;
	int			t_count;
	t_vector	symbolsize;
	t_vector	pixelsize;
	t_images	i;
	char		*map;
	char		*copy_map;
	int			*random;
	int			k;
	int			status;
	int			restart;
	int			window;
	int			close_level;
	int			score;
	int			record;
	char		*scoreboard;
	int			fd;
	int			p_status;
	int			cheat;
}				t_root;

int		map(t_root *game);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_n(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	sprites_init(t_root *game);
void	start(t_root *game, int a);
int		action(int keypress, t_root *game);
void	playerlocation(t_root *game);
int		check_valid_map(t_root *game);
int		preparation(t_root *game);
void	print_image(t_root *game, t_image *image, t_vector xy, int i);
int		symbol_loc(t_root *game, int line);
int		exit_game(void);
void	my_mlx_pixel_put(t_image *bg, int x, int y, int color);
void	*image_ref(t_root *game, t_image *image);
int		create_trgb(int t, int r, int g, int b);
int		patrol_init(t_root *game);
int		patrol_move(t_root *game);
void	animation_cykle(t_root *game, int speed);
void	game_over(t_root *game);
void	fade_to_black(t_root *game);
int		win(t_root *game);
void	darken(t_root *game);
void	main_menu(t_root *game);
int		menu_select(int keypress, t_root *game);
int		menu_render(t_root *game);
void	display_score(t_root *game);
int		select_lvl(int keypress, t_root *game);
void	menu_display_level(t_root *game);
void	menu_display_score(t_root *game);
void	level_select_init(t_root *game);
char	*level_name(int lvl);
void	movement(t_root *game, int i, int e);
void	dj(t_root *game, t_vector xy);
void	walls(t_root *game, t_vector xy, int i, int k);
void	player(t_root *game, t_vector xy, int i);
void	collectible(t_root *game, t_vector xy, int i, int j);
int		lady(t_root *game, t_vector xy, int i);
void	hearts(t_root *game);
void	score(t_root *game);
int		patrol(t_root *game);
void	fence(t_root *game, t_image *f);
void	return_to_menu(t_root *game);
void	move_sd(t_root *game, char key, int j);
void	move_wa(t_root *game, char key, int j);
void	change_player_sprite(t_root *game, int keypress);
void	mlx_img(t_root *game, void *img, int x, int y);
void	cheat(int keypress, t_root *game);
int		scores(t_root *game);
void	menu_overlay(t_root *game, void *mlx, void *mlxw);
void	num_init(t_root *game);
void	player_entering(t_root *game);
void	fading(void *img);
void	menu_sprites_init(t_root *game);
void	next_level(t_root *game);
void	enemy_init(t_root *game);

#endif