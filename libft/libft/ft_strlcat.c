/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:10:20 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/03 01:53:11 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_i;
	size_t	original_dst_size;

	i = ft_strlen(dst);
	src_i = 0;
	original_dst_size = ft_strlen(dst);
	if (!size || size <= original_dst_size)
		return (ft_strlen(src) + size);
	while (src[src_i] && i < size - 1)
	{
		dst[i] = src[src_i];
		i++;
		src_i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + original_dst_size);
}
