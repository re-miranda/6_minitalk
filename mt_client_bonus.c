/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:03:31 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/13 06:43:11 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

pid_t	g_pid;

void	validate_arguments(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client PID \"string\"\n");
		exit(2);
	}
	g_pid = ft_atoi(argv[1]);
	if (kill(g_pid, 0))
	{
		ft_printf("Error: Invalid PID\n");
		exit(1);
	}
	return ;
}

void	client_func(unsigned int n, char *c)
{
	int	i;

	i = 8;
	(void)n;
	while (i--)
	{
		usleep(USLEEP_AMOUNT);
		if (*c & 1 << i)
			kill(g_pid, SIGUSR2);
		else
			kill(g_pid, SIGUSR1);
		pause();
	}
	return ;
}

void	transmit_pid(int server_pid)
{
	int	i;

	i = 32;
	while (i--)
	{
		usleep(100000);
		if (server_pid & 1 << i)
			kill(g_pid, SIGUSR2);
		else
			kill(g_pid, SIGUSR1);
	}
	pause();
}

void	caught_sig(int n)
{
	(void)n;
	return ;
}

int	main(int argc, char *argv[])
{
	struct sigaction	psa;

	psa.sa_handler = caught_sig;
	sigaction(SIGUSR1, &psa, NULL);
	validate_arguments(argc, argv);
	transmit_pid(getpid());
	ft_striteri(argv[2], client_func);
	client_func(0, "\n");
	ft_printf("Message sent.\n");
	return (0);
}

