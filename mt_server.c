/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:05:53 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/13 03:44:59 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int buffer;

void	caught_sig(int n)
{
	static int	i;
	static int	pid;

	if (n == SIGUSR1)
		buffer &= ~1;
	else
		buffer |= 1;
	if (pid)
	{
		if (i++ == 7)
		{
			i = 0;
			write(1, (((char *)&buffer) + 3), 1);
		}
		if (kill(pid, SIGUSR1))
			pid = 0;
	}
	else if (i++ == 31)
	{
		pid = buffer;
		if (kill(pid, 0))
			pid = 0;
		else
		{
			i = 0;
			ft_printf("(%i)", pid);
			kill(pid, SIGUSR1);
		}
	}
	buffer = buffer<<1;
}

int	main(void)
{
	struct sigaction	psa;

	psa.sa_handler = caught_sig;
	sigaction(SIGUSR1, &psa, NULL);
	sigaction(SIGUSR2, &psa, NULL);
	ft_printf("Server PID: %i\n", getpid());
	ft_printf("Ready to receive message...\n");
	while (1)
		pause();
	return (0);
}
