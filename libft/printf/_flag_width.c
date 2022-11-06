/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _flag_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:18:18 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/23 10:23:28 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_name
{
	int		missing_width;
	char	sign[2];
	char	*swap;
	char	*padding;
	char	padding_type;
}	t_name;

static char	*apply_width(t_data *data, t_name *name, char *result)
{
	if (name->padding_type == '0' && ft_strchr("di", data->type)
		&& !ft_isdigit(*(name->sign)))
		result++;
	data->total_bytes_write += name->missing_width;
	name->padding = ft_calloc(1, name->missing_width + 1);
	ft_memset(name->padding, name->padding_type, name->missing_width);
	if (ft_strchr(data->found_flags, '-'))
		result = ft_strjoin(result, name->padding);
	else
		result = ft_strjoin(name->padding, result);
	free(name->padding);
	free(name->swap);
	if (name->padding_type == '0' && !ft_isdigit(*name->sign)
		&& ft_strchr("di", data->type))
	{
		name->swap = result;
		result = ft_strjoin(name->sign, result);
		free(name->swap);
	}
	return (result);
}

char	*width(t_data *data, char *result)
{
	t_name	name;

	name.swap = result;
	name.sign[0] = *result;
	name.sign[1] = 0;
	name.missing_width = data->width - ft_strlen(result);
	name.padding_type = ' ';
	if (ft_strchr(data->found_flags, '0'))
	{
		if (data->precision == -1 && !ft_strchr(data->found_flags, '-'))
			name.padding_type = '0';
	}
	if (name.missing_width > 0)
	{
		result = apply_width(data, &name, result);
	}
	data->width = 0;
	return (result);
}
