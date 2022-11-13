/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:53:59 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/13 06:27:28 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_mtdata	g_data;

void	caught_sig(int n)
{
	if (n == SIGUSR1)
		g_data.buffer &= ~1;
	else
		g_data.buffer |= 1;
	if (g_data.pid)
	{
		if (g_data.i++ == 7)
		{
			g_data.i = 0;
			write(1, (char *)&g_data.buffer, 1);
		}
		usleep(15);
		if (kill(g_data.pid, SIGUSR1))
			g_data.pid = 0;
	}
	else if (g_data.i++ == 31)
	{
		g_data.pid = g_data.buffer;
		g_data.i = 0;
		kill(g_data.pid, SIGUSR1);
	}
	g_data.buffer = g_data.buffer << 1;
}

int	main(void)
{
	struct sigaction	psa;

	psa.sa_handler = caught_sig;
	sigaction(SIGUSR1, &psa, NULL);
	sigaction(SIGUSR2, &psa, NULL);
	g_data.i = 0;
	g_data.pid = 0;
	ft_printf("Server PID: %i\n", getpid());
	while (1)
		pause();
	return (0);
}
