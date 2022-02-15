/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:32:40 by preed             #+#    #+#             */
/*   Updated: 2022/02/15 18:52:18 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
