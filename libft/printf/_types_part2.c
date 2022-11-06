/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:45:20 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/21 06:01:03 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_x(t_data *data)
{
	char			*swap;
	unsigned int	result;
	char			*str_result;

	result = va_arg(data->va_ptr, unsigned int);
	str_result = ft_uint_base_str(result, "0123456789abcdef");
	if (ft_strchr(data->found_flags, '#') && result)
	{
		swap = str_result;
		str_result = ft_strjoin("0x", str_result);
		free(swap);
	}
	return (str_result);
}

char	*type_xx(t_data *data)
{
	char			*swap;
	unsigned int	result;
	char			*str_result;
	int				index;

	index = 0;
	result = va_arg(data->va_ptr, unsigned int);
	str_result = ft_uint_base_str(result, "0123456789abcdef");
	while (str_result[index])
	{
		str_result[index] = ft_toupper(str_result[index]);
		index++;
	}
	if (ft_strchr(data->found_flags, '#') && result)
	{
		swap = str_result;
		str_result = ft_strjoin("0X", str_result);
		free(swap);
	}
	return (str_result);
}

char	*type_p(t_data *data)
{
	char			*swap;
	size_t			result;
	char			*str_result;

	result = va_arg(data->va_ptr, size_t);
	if (result == 0)
		str_result = ft_strdup("(nil)");
	else
	{
		str_result = ft_sizet_base_str((size_t)result, "0123456789abcdef");
		swap = str_result;
		str_result = ft_strjoin("0x", str_result);
		free(swap);
	}
	return (str_result);
}
