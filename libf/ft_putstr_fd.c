/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:46 by enogueir          #+#    #+#             */
/*   Updated: 2024/11/02 16:53:36 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_strlen(s));
}
/*
int	main(void)
{
	ft_putstr_fd("hello world", 1);
}*/
