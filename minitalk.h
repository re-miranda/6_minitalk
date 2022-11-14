/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:06:02 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/14 06:10:48 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft_gnl_printf.h"
# include <signal.h>
# include <unistd.h>

# define USLEEP_AMOUNT 15
# define SAFE_USLEEP_AMOUNT 110000

typedef struct s_mtdata
{
	int	pid;
	int	buffer;
	int	i;
}	t_mtdata;

#endif