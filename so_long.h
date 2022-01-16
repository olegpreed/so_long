#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

#define W_key 13
#define A_key 0
#define S_key 1
#define D_key 2

typedef struct	s_vector 
{
	int		x;
	int		y;
}				t_vector;

typedef struct s_image {
	void	*reference;
	char	*pixels;
	t_vector	size;
	t_vector	location;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char 	*path;
}				t_image;

typedef struct	s_root {
	void	*mlx;
	void	*mlxw;
	t_vector symbolsize;
	t_vector pixelsize;
	t_image grass;
	t_image wall;
	char	*map;

}				t_root;

int map(t_root *game);
char *get_next_line(int fd);
void count_map(t_root *game);
size_t	ft_strlen(const char *s);
void sprites_init(t_root *game);
void start(t_root *game);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen_n(const char *s);
void map_to_string(t_root *game);
int action(int keypress, t_root *game);

#endif