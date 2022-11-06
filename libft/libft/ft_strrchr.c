/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:57:41 by rmiranda          #+#    #+#             */
/*   Updated: 2022/04/13 23:57:45 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_size;

	s_size = ft_strlen(s);
	while (s_size >= 0)
	{
		if (s[s_size] == (const char)c)
			return ((char *)&s[s_size]);
		s_size--;
	}
	return (NULL);
}
