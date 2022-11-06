/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:19:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/04/26 03:00:02 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	string_size;
	size_t	i;

	i = 0;
	string_size = ft_strlen(s);
	while (i <= string_size)
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
