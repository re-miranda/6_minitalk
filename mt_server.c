/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:53:59 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/14 10:59:46 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	catch_sigusr_1_2(int n, siginfo_t *siginfo, void *context)
{
	static int	buffer;
	static int	i;

	(void)context;
	if (n == SIGUSR1)
		buffer &= ~1;
	else
		buffer |= 1;
	if (i++ == 7)
	{
		i = 0;
		write(1, (char *)&buffer, 1);
	}
	buffer <<= 1;
	usleep(USLEEP_AMOUNT);
	if (kill(siginfo->si_pid, SIGUSR1))
		i = 0;
}

static struct sigaction	initialize_sigaction_struct(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_sigaction = catch_sigusr_1_2;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	return (action);
}

int	main(void)
{
	struct sigaction	sigusr_1_2_action;

	sigusr_1_2_action = initialize_sigaction_struct();
	ft_printf("Server PID: %i\n", getpid());
	while (1)
		pause();
	return (0);
}
