/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:53:59 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/13 05:54:00 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_buffer;

void	caught_sig(int n)
{
	static int	i;
	static int	pid;

	if (n == SIGUSR1)
		g_buffer &= ~1;
	else
		g_buffer |= 1;
	usleep(10);
	if (pid)
	{
		if (i++ == 7)
		{
			i = 0;
			write(1, (char *)&g_buffer, 1);
		}
		if (kill(pid, SIGUSR1))
			pid = 0;
	}
	else if (i++ == 31)
	{
		pid = g_buffer;
		if (kill(pid, 0))
			pid = 0;
		else
		{
			i = 0;
			kill(pid, SIGUSR1);
		}
	}
	g_buffer = g_buffer << 1;
}

int	main(void)
{
	struct sigaction	psa;

	psa.sa_handler = caught_sig;
	sigaction(SIGUSR1, &psa, NULL);
	sigaction(SIGUSR2, &psa, NULL);
	ft_printf("Server PID: %i\n", getpid());
	while (1)
		pause();
	return (0);
}
