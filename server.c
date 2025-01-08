#include "include/minitalk.h"

static void	signal_handler(int signal)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;

	if (signal == SIGUSR2)
		character |= (1 << (7 - bit_count));
	bit_count++;
	//ft_printf("bit_count: %d\n", bit_count);
	if(bit_count == 8)
	{
		if (character == '\0')
			write(1, "\n", 1);
		else
			write(1, &character, 1);
		character = 0;
		bit_count = 0;

	}
}

int	main()
{
	pid_t pid;
	struct sigaction sa;


	pid = getpid();
	ft_printf("PID del servidor: %d\n", pid);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return 0;
}
