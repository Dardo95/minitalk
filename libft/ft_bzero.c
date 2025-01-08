/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:31:56 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/21 18:49:33 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int     main(void)
{
        char    str[] = "hello how are you";
        ft_bzero(str, 12);
        write(1, str, 12);
		bzero(str, 12);
		write(1, str, 12);
}*/
