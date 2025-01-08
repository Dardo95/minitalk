/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:59:46 by enogueir          #+#    #+#             */
/*   Updated: 2024/11/07 16:53:38 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_hex(size_t n, int uppercase)
{
	size_t	hex_num;

	hex_num = 0;
	if (n == 0)
		return (hex_num + ft_putchar_fd('0', 1));
	if (n >= 16)
	{
		hex_num += ft_putnbr_hex(n / 16, uppercase);
		hex_num += ft_putnbr_hex(n % 16, uppercase);
	}
	else if (n <= 9)
	{
		hex_num += ft_putchar_fd(n + '0', 1);
	}
	else
	{
		if (uppercase)
			hex_num += ft_putchar_fd(n - 10 + 'A', 1);
		else
			hex_num += ft_putchar_fd(n - 10 + 'a', 1);
	}
	return (hex_num);
}

size_t	ft_putptr(size_t ptr)
{
	size_t	addr;

	addr = 0;
	if (ptr == 0)
	{
		return (ft_putstr_fd(("(nil)"), 1));
	}
	addr += ft_putchar_fd('0', 1);
	addr += ft_putchar_fd('x', 1);
	addr += ft_putnbr_hex(ptr, 0);
	return (addr);
}
