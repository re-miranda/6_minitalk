/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:16:22 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/13 01:51:00 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)(big));
	while (big[i] && len - i)
	{
		while (little[j] == big[i + j] && len - i - j)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
