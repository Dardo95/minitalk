/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:10:14 by enogueir          #+#    #+#             */
/*   Updated: 2024/11/01 15:47:15 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(long n, int fd)
{
	size_t	i;

	i = 0;
	if (n == (-__LONG_MAX__) - 1)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('9', fd);
		i += 2;
		n = 223372036854775808;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i ++;
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
	return (i + 1);
}

/*#include <stdio.h>
int	main(void)
{
    int number = -84574451;

    printf("\n%lu\n", ft_putnbr_fd(number, 1));
    return 0;
}*/