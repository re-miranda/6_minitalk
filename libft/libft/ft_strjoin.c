/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:31:36 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/13 02:10:53 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strjoin)
	{
		while (*s1)
			strjoin[i++] = *s1++;
		while (*s2)
			strjoin[i++] = *s2++;
		strjoin[i] = '\0';
	}
	return (strjoin);
}
