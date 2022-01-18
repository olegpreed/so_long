/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:31:09 by preed             #+#    #+#             */
/*   Updated: 2022/01/18 14:31:11 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			j++;
		i++;
	}
	if (s[0] == c)
		j--;
	return (j);
}

static char	*calc(char *s, char c, const char **pointer)
{
	char	*beg;
	char	*end;
	char	*word;

	while (*s == c)
		s++;
	if (*s != c)
		beg = s;
	while (*s != c && *s != 0)
		s++;
	end = s - 1;
	*pointer = s;
	word = (char *)ft_calloc(end - beg + 2, sizeof(char));
	if (word == 0)
		return (0);
	ft_strlcpy(word, beg, end - beg + 2);
	return (word);
}

static void	freak(char **strings)
{
	int	j;

	j = 0;
	while (strings[j])
	{
		free(strings[j]);
		j++;
	}
	free(strings);
}

char	**ft_split(char const *s, char c)
{
	char		**strings;
	int			j;
	int			i;
	const char	**pointer;

	if (!s)
		return (0);
	if (ft_strlen(s) == 0)
		return ((char **)ft_calloc(1, sizeof(char *)));
	pointer = &s;
	j = count(s, c) + 2;
	strings = (char **)ft_calloc(j, sizeof(char *));
	if (strings == 0)
		return (0);
	i = -1;
	while (++i < j - 1)
	{
		strings[i] = calc((char *)s, c, pointer);
		if (strings[i] == 0)
		{
			freak(strings);
			return (0);
		}
	}
	return (strings);
}
