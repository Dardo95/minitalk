/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:10:16 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/28 15:16:13 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	let;
	size_t			i;

	str = ((unsigned char *) s);
	let = ((unsigned char) c);
	i = 0;
	while (i < n)
	{
		if (str[i] == let)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/* int main(void)
{
	const char *str = "How are you";
	char c = 'a';
	size_t n = 14;

	char *result = (char *)ft_memchr(str, c, n);

	if (result)
		write (1, result, 1);
	else
		write(1, "Not found", 13);
	return (0);
} */
