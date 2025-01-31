/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:20:54 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/31 09:20:28 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;
	static char	*buffer = NULL;
	static int	i;

	(void)context;
	buffer = malloc_buffer(&buffer, &i);
	(void)context;
	if (signal == SIGUSR1)
		c |= (0 << bit);
	else if (signal == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			print_buffer(&buffer, &i);
			kill(info->si_pid, SIGUSR2);
		}
		else
			fill_buffer(c, buffer, &i);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action_on_signal;

	ft_printf("Serveur PID : %d\n", getpid());
	action_on_signal.sa_sigaction = handle_signal;
	sigemptyset(&action_on_signal.sa_mask);
	action_on_signal.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &action_on_signal, NULL);
	sigaction(SIGUSR2, &action_on_signal, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
