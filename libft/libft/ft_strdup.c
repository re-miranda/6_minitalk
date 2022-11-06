/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:38:18 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/15 02:04:19 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(str) + 1;
	dup = malloc(sizeof(char) * i);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, i);
	return (dup);
}
