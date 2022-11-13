/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:06:02 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/13 05:47:01 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft_gnl_printf.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_mtdata
{
	pid_t	pid;
	char	buffer;
	int		i;
}	t_mtdata;

// CLIENT
// SERVER

#endif