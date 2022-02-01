/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:25:38 by preed             #+#    #+#             */
/*   Updated: 2022/01/21 19:19:39 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define CLOSE 17

typedef struct s_vector
{
	int		x;
	int		y;
}				t_vector;


typedef struct s_image {
	void		*reference;
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
	//t_image		thug[2];
}				t_crowd;

typedef struct s_images {
	t_image		floor;
	t_image		floor_c;
	t_image		wall;
	t_image		lady;
	t_image		max;
	t_image		max_b;
	t_image		max_r;
	t_image		max_l;
	t_image		speak;
	t_image		speak2;
	t_crowd		c;
	t_image		redbull;
	t_image		dj;
	t_image		dj2;
	t_image		dj3;
	t_image		door;
	t_image		shadow_b;
	t_image		beer;
}				t_images;

typedef struct s_root {
	void		*mlx;
	void		*mlxw;
	char		*map_path;
	t_image		*thug;
	int			t_count;
	t_vector	symbolsize;
	t_vector	pixelsize;
	t_images	i;
	char		*map;
	int			*random;
	int			k;

}				t_root;

int		map(t_root *game);
char	*get_next_line(int fd);
void	count_map(t_root *game);
size_t	ft_strlen(const char *s);
void	sprites_init(t_root *game);
void	start(t_root *game);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen_n(const char *s);
int		map_to_string(t_root *game);
int		action(int keypress, t_root *game);
void	playerlocation(t_root *game);
char	*ft_strchr(const char *s, int c);
int		check_valid_map(t_root *game);
int	check_item_count(char *map, t_root *game);
int		check_walls(char *map);
int		preparation(t_root *game, int argc, char **argv);
void	symbol_to_image(t_root *game, t_vector xy, int i, int k);
void	print_image(t_root *game, t_image *image, t_vector xy, int i);
int		symbol_loc(t_root *game, int line);
int		exit_game(void);
void	my_mlx_pixel_put(t_image *bg, int x, int y, int color);
void	*image_ref(t_root *game, t_image *image);
int		create_trgb(int t, int r, int g, int b);
int		patrol_init(t_root *game);
int		patrol_move(t_root *game);
void	animation_cykle(t_root *game);
void	background(t_root *game);

#endif