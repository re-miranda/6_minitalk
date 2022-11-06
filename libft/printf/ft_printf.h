/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:58:40 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/24 07:48:33 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_data
{
	va_list			va_ptr;
	int				total_bytes_write;
	char			*original_src_str;
	char			*src_str;
	char			valid_flags[6];
	char			valid_types[9];
	char			found_flags[6];
	unsigned int	width;
	int				precision;
	char			type;
}	t_data;

int		ft_printf(const char *format_string, ...);
void	find_type(t_data *data);
void	find_precision(t_data *data);
void	find_width(t_data *data);
void	find_flags(t_data *data);
char	*type_c(t_data *data);
char	*type_s(t_data *data);
char	*type_d_i(t_data *data);
char	*type_u(t_data *data);
char	*type_x(t_data *data);
char	*type_xx(t_data *data);
char	*type_p(t_data *data);
char	*width(t_data *data, char *result);
char	*precision(t_data *data, char *result);
char	*ft_uint_base_str(unsigned int nbr, char *base);
char	*ft_uint_str(unsigned int n);
char	*ft_sizet_base_str(size_t nbr, char *base);

#endif
