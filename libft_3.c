/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:56:45 by oleg              #+#    #+#             */
/*   Updated: 2022/02/08 15:00:15 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*b;

	a = (char *)malloc(ft_strlen(s1) + 1);
	b = a;
	if (a == 0)
		return (0);
	while (*s1)
	{
		*a = *s1;
		a++;
		s1++;
	}
	*a = *s1;
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*b;

	if (s == 0)
		return (0);
	if (ft_strlen(s) <= (size_t)start)
	{
		b = (char *)ft_calloc(1, 1);
		return (b);
	}
	if ((unsigned int)ft_strlen(s) - start < len)
		len = (unsigned int)ft_strlen(s) - start;
	b = (char *)ft_calloc(len + 1, sizeof(char));
	if (b == 0)
		return (0);
	ft_strlcpy(b, &s[start], len + 1);
	return (b);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}