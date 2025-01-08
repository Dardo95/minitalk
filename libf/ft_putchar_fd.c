/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:31:56 by enogueir          #+#    #+#             */
/*   Updated: 2024/11/01 15:22:18 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
/*
int	main(void)
{
	int i;
	char num;

	i = 0;
	num = '0';
	while(i < 10)
	{
		ft_putchar_fd(num, 1);
		i++;
		num++;
	}
}*/
