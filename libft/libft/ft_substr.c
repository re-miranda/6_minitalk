/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:56:38 by rmiranda          #+#    #+#             */
/*   Updated: 2022/05/13 03:39:07 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	truelen;
	unsigned int	slen;

	if (s == NULL)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		truelen = 1;
	else if (len >= slen)
		truelen = slen - start + 1;
	else
		truelen = len + 1;
	sub = (char *)malloc(truelen);
	if (!sub)
		return (NULL);
	while ((start < slen) && (i < len))
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
