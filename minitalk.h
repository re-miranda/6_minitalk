/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:06:02 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/09 10:00:46 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft_gnl_printf.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_global
{
	pid_t	pid;
	int		flag;
	char	buffer;
}	t_global;

// CLIENT
void	client_func(unsigned int n, char *c);
// SERVER
void	server_func(void);
void	set_bit(char byte, int position);
void	clear_bit(char byte, int position);

#endif