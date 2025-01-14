/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:17:16 by enogueir          #+#    #+#             */
/*   Updated: 2025/01/14 15:20:40 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int signal)
{
	(void)signal;
	g_ack_received = 1;
}

static int	validate_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (!g_ack_received)
			;
		bit--;
	}
}

static void	send_message(pid_t server_pid, char *message)
{
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3 || !ft_strlen(argv[2]) || !validate_pid(argv[1]))
	{
		ft_putstr_fd("\x1b[31mERROR!\xb1[0m\n", 2);
		ft_putstr_fd("Format: ./client <PID> <menssage>\n", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ack_handler);
	ft_printf("Sending message to PID server: %d\n", server_pid);
	send_message(server_pid, argv[2]);
	ft_printf("Message sent");
	return (0);
}
