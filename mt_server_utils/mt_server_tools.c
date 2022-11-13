/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:08:36 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/09 10:01:08 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	server_func(void)
{
	return ;
}

void	set_bit(char byte, int position)
{
	char mask;

	mask = 1<<position;
	byte = byte | mask;
}

void	clear_bit(char byte, int position)
{
	char mask;

	mask = 1<<position;
	byte = byte & ~mask;
}