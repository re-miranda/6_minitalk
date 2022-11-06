/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:57:49 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/26 18:05:43 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*type(t_data *data)
{
	if (data->type == 'c')
		return (type_c(data));
	else if (data->type == 's')
		return (type_s(data));
	else if (data->type == 'd' || data->type == 'i')
		return (type_d_i(data));
	else if (data->type == 'u' )
		return (type_u(data));
	else if (data->type == 'x' )
		return (type_x(data));
	else if (data->type == 'X' )
		return (type_xx(data));
	else if (data->type == 'p' )
		return (type_p(data));
	return (NULL);
}

static void	format(t_data *data)
{
	char	*result;

	ft_memset(data->found_flags, 1, 5);
	data->src_str++;
	if (*data->src_str == '%')
	{
		data->total_bytes_write ++;
		data->src_str++;
		write(1, "%", 1);
		return ;
	}
	find_flags(data);
	find_width(data);
	find_precision(data);
	find_type(data);
	result = type(data);
	result = precision(data, result);
	result = width(data, result);
	write(1, result, ft_strlen(result));
	free(result);
}

static void	interpret_format_string(t_data *data)
{
	while (*data->src_str)
	{
		if (*data->src_str != '%')
		{
			write(1, data->src_str, 1);
			data->src_str++;
			data->total_bytes_write++;
		}
		else
			format(data);
	}
}

static void	intialize(const char *format_string, t_data *data)
{
	data->total_bytes_write = 0;
	data->found_flags[5] = 0;
	data->src_str = ft_strdup(format_string);
	data->original_src_str = data->src_str;
	ft_strlcpy(data->valid_flags, "-0# +", 6);
	ft_strlcpy(data->valid_types, "diuxXcsp", 9);
}

int	ft_printf(const char *format_string, ...)
{
	t_data	data;

	if (!format_string)
		return (-1);
	if (format_string[0] == 0)
		return (1);
	intialize(format_string, &data);
	va_start(data.va_ptr, format_string);
	interpret_format_string(&data);
	free(data.original_src_str);
	va_end(data.va_ptr);
	return (data.total_bytes_write);
}
