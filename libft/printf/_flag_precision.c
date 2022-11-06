/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _flag_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:16:16 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/27 00:10:32 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_precision(char *swap, char **result, char *sign, t_data *data)
{
	if ((size_t)data->precision >= ft_strlen(*result))
	{
		*result = ft_calloc(sizeof(char), data->precision + 1);
		ft_memset(*result, '0', data->precision);
		if (ft_strchr("-+ ", *swap))
		{
			ft_memcpy((*result + data->precision - ft_strlen(swap) + 1),
				(swap + 1), ft_strlen(swap) - 1);
			free(swap);
			swap = *result;
			*result = ft_strjoin(sign, *result);
		}
		else
			ft_memcpy((*result + data->precision - ft_strlen(swap)),
				swap, ft_strlen(swap));
		free(swap);
	}
	else if (data->precision == 0 && *result[0] == '0')
		*result[0] = 0;
}

char	*precision(t_data *data, char *result)
{
	char	*swap;
	char	sign[2];

	swap = result;
	sign[0] = swap[0];
	sign[1] = 0;
	if (data->precision == -1)
	{
		data->total_bytes_write += ft_strlen(result);
		return (result);
	}
	if ((int)ft_strlen(result) > data->precision)
	{
		if (data->type == 's')
			result[data->precision] = 0;
	}
	if (ft_strchr("diuxX", data->type))
		apply_precision(swap, &result, sign, data);
	data->total_bytes_write += ft_strlen(result);
	return (result);
}
