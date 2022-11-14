/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:03:31 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/14 10:57:24 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

pid_t	g_pid;

static void	client_func(unsigned int n, char *c)
{
	int	i;

	(void)n;
	i = 8;
	while (i--)
	{
		usleep(USLEEP_AMOUNT);
		if (*c & 1 << i)
			kill(g_pid, SIGUSR2);
		else
			kill(g_pid, SIGUSR1);
		pause();
	}
}

static void	caught_sig(int n)
{
	(void)n;
}

static void	validate_arguments(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client PID \"string\"\n");
		exit(1);
	}
	g_pid = ft_atoi(argv[1]);
	if (kill(g_pid, 0))
	{
		ft_printf("Error: Invalid PID\n");
		exit(2);
	}
	return ;
}

static struct sigaction	initialize_sigaction_struct(void)
{
	struct sigaction	action;

	action.sa_handler = caught_sig;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &action, NULL);
	return (action);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sigusr1_action;

	sigusr1_action = initialize_sigaction_struct();
	validate_arguments(argc, argv);
	ft_striteri(argv[2], client_func);
	client_func(0, "\n");
	ft_printf("Message sent.\n");
	return (0);
}
