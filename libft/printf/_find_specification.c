/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _find_specification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:58:43 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/23 10:42:05 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_type(t_data *data)
{
	data->type = 0;
	if (ft_strchr(data->valid_types, *data->src_str))
	{
		data->type = *data->src_str;
		data->src_str++;
	}
}

void	find_precision(t_data *data)
{
	if (*data->src_str != '.')
	{
		data->precision = -1;
		return ;
	}
	data->src_str++;
	data->precision = ft_atoi(data->src_str);
	while (ft_isdigit(*data->src_str))
		data->src_str++;
}

void	find_width(t_data *data)
{
	data->width = 0;
	if (ft_isdigit(*data->src_str))
		data->width = ft_atoi(data->src_str);
	while (ft_isdigit(*data->src_str))
		data->src_str++;
}

void	find_flags(t_data *data)
{
	while (ft_strchr(data->valid_flags, *data->src_str))
	{
		if (!ft_strchr(data->found_flags, *data->src_str))
			ft_memset(ft_strchr(data->found_flags, 1), *data->src_str, 1);
		data->src_str++;
	}
}
