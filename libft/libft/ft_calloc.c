/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:41:05 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/13 04:11:29 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*allocated_space;
	size_t	size_total;

	size_total = elsize * nelem;
	if (nelem != 0 && size_total / nelem != elsize)
		return (NULL);
	allocated_space = malloc(sizeof(char) * size_total);
	if (allocated_space != NULL)
	{
		while (size_total--)
			((char *)allocated_space)[size_total] = 0;
	}
	return (allocated_space);
}
