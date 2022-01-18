/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:33:09 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 14:33:12 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
