/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:21:09 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/31 15:16:47 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t g_ack_received = 0;

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	return ((int)result);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack_received)
            pause();
		i++;
	}
}

void	confirmation_received(int signal)
{
	if (signal == SIGUSR1)
        g_ack_received = 1;
	else if (signal == SIGUSR2)
		ft_printf("Message received by server\n");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	struct sigaction sa;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Error! Correct usage : ./client <PID> <message>\n");
		return (1);
	}
	sa.sa_handler = confirmation_received;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
