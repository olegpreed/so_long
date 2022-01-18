/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:25:38 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 14:30:29 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

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
}				t_image;

typedef struct s_root {
	void		*mlx;
	void		*mlxw;
	int			close;
	char		*map_path;
	t_vector	symbolsize;
	t_vector	pixelsize;
	t_image		grass;
	t_image		wall;
	t_image		pika;
	t_image		ball;
	t_image		ash;
	char		*map;

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
void	map_to_string(t_root *game);
int		action(int keypress, t_root *game);
void	playerlocation(t_root *game);
char	*ft_strchr(const char *s, int c);
int		check_valid_map(t_root *game);
int		check_item_count(char *map);
int		check_walls(char *map);
int		preparation(t_root *game, int argc, char **argv);
void	symbol_to_image(t_root *game, int x, int y, int i);
void	print_image(t_root *game, t_image *image, int x, int y);

#endif