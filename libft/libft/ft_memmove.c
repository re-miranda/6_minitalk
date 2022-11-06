/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:24:30 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/13 02:18:31 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (!s1 && !s2)
		return (NULL);
	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	while (n--)
		((char *)s1)[n] = ((char *)s2)[n];
	return (s1);
}
