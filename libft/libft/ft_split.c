/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 08:04:59 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/15 02:09:39 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countsubstr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (i);
}

static void	fillsubstr(char *s, char c, char **split, size_t substr_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < substr_count)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		while (s[j] && s[j] != c)
			j++;
		split[i++] = ft_substr(s, 0, j);
		s += j;
	}
	split[substr_count] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	substr_count;

	if (!s)
		return (NULL);
	substr_count = countsubstr((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (substr_count + 1));
	if (split == NULL)
		return (NULL);
	fillsubstr((char *)s, c, split, substr_count);
	return (split);
}
