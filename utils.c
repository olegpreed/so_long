#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	char	k;

	k = (char)c;
	while (*s != k && *s != 0)
		s++;
	if ((k == 0 && *s == 0) || *s != 0)
		return ((char *)s);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
size_t	ft_strlen_n(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\n' && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	h;

	i = 0;
	j = ft_strlen(dst);
	h = j;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (j < (dstsize - 1) && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (dstsize >= h)
		dst[j] = 0;
	if (dstsize >= h)
		return (h + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (char *)malloc(size * count);
	if (a == 0)
		return (0);
	ft_bzero(a, size * count);
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;

	if (s1 == 0 || s2 == 0)
		return (0);
	a = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (a == 0)
		return (0);
	ft_strlcpy(a, s1, ft_strlen(s1) + 1);
	ft_strlcat(a, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (a);
}



int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
// void	my_mlx_pixel_put(t_root *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


