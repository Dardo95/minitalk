#include "include/minitalk.h"

static void	signal_handler(int signal, siginfo_t *sinfo, void *content)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;

	(void)content;
	if (sinfo->si_pid == 0)
		return ;
	character |= (signal == SIGUSR2);
	bit_count++;
	//ft_printf("bit_count: %d\n", bit_count);
	if(bit_count == 8)
	{
		if (character == '\0')
			ft_printf("\n[INFO] Full message received. Waiting for more...\n");
		else
			ft_putchar_fd(character, 1);
		character = 0;
		bit_count = 0;

	}
	else
		character <<= 1;
	kill(sinfo->si_pid, SIGUSR1);
}

int	main()
{
	pid_t pid;
	struct sigaction sa;

	pid = getpid();
	ft_printf("Server Started, PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	//sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return 0;
}
