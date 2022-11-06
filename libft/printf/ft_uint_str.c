/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _uint_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:14:53 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/18 09:51:03 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	if (n >= 10)
		return (1 + ft_nbrlen(n / 10));
	return (1);
}

static void	intstr(char *str, size_t str_i, unsigned int n)
{
	str[str_i] = (n % 10) + '0';
	if (n > 9)
		intstr(str, --str_i, n / 10);
}

char	*ft_uint_str(unsigned int n)
{
	char	*str;
	size_t	str_len;

	str_len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[str_len--] = '\0';
	intstr(str, str_len, n);
	return (str);
}
