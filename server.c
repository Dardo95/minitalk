#include "include/minitalk.h"


int	main()
{
	pid_t pid;

	pid = getpid();
	ft_printf("PID del servidor: %d\n", pid);
}