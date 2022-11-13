/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:05:53 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/13 06:43:26 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		usleep(USLEEP_AMOUNT);
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
