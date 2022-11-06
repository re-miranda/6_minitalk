/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _types_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:37:07 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/23 09:36:15 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_c(t_data *data)
{
	char	*result;
	char	*width_str;
	char	cha;

	data->total_bytes_write++;
	result = ft_strdup("");
	cha = va_arg(data->va_ptr, int);
	if (data->width)
		data->width--;
	if (!ft_strchr(data->found_flags, '-'))
	{
		width_str = ft_strdup("");
		width_str = width(data, width_str);
		write(1, width_str, ft_strlen(width_str));
		free(width_str);
	}
	write(1, &cha, 1);
	return (result);
}

char	*type_s(t_data *data)
{
	char	*result;

	result = va_arg(data->va_ptr, char *);
	if (result == NULL)
	{
		if (data->precision == -1 || data->precision >= 6)
			result = ft_strdup("(null)");
		else
			result = ft_strdup("");
	}
	else
		result = ft_strdup(result);
	return (result);
}

char	*type_d_i(t_data *data)
{
	int		result;
	char	*str_result;
	char	*swap;

	result = va_arg(data->va_ptr, int);
	str_result = ft_itoa(result);
	swap = str_result;
	if (ft_strchr(data->found_flags, '+') && result >= 0)
	{
		str_result = ft_strjoin("+", str_result);
		free(swap);
		*ft_strchr(data->found_flags, '+') = 1;
	}
	else if (ft_strchr(data->found_flags, ' ') && result >= 0)
	{
		str_result = ft_strjoin(" ", str_result);
		free(swap);
		*ft_strchr(data->found_flags, ' ') = 1;
	}
	return (str_result);
}

char	*type_u(t_data *data)
{
	unsigned int	result;
	char			*str_result;

	result = va_arg(data->va_ptr, unsigned int);
	str_result = ft_uint_str(result);
	return (str_result);
}
