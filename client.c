#include "include/minitalk.h"

static void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while(i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

static void send_message(pid_t server_pid, char *message)
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
	
	if (argc != 3)
		ft_putstr_fd("Uso: ./client <PID> <mensaje>\n",1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Error: Pid Invalido", 2);
		return (1);
	}
	send_message(server_pid, argv[2]);
	return (0);
}