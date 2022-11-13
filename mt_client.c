/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:03:31 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/13 03:49:35 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


pid_t	pid;

static pid_t	validate_arguments(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client PID \"string\"\n");
		exit(2);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0))
	{
		ft_printf("Error: Invalid PID\n");
		exit(1);
	}
	return (pid);
}

void	client_func(unsigned int n, char *c)
{
	int	i;

	i = 8;
	(void)n;
	while (i--)
	{
		usleep(10000);
		if (*c & 1<<i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
	}
	return ;
}

void	transmit_pid(int server_pid)
{
	int	i;

	i = 32;
	ft_printf("(%i)", server_pid);
	while (i--)
	{
		usleep(100000);
		if (server_pid & 1<<i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
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
	pid = validate_arguments(argc, argv);
	transmit_pid(getpid());
	ft_striteri(argv[2], client_func);
	client_func(0, "\n");
	ft_printf("Message sent.\n");
	return (0);
}
