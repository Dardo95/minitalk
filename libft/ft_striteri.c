/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:30:43 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/28 16:30:51 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	ft_toup(unsigned int i, char *c)
{
	(void)i;
	if (c)
	{
		if (*c >= 'a' && *c <= 'z' && *c)
		{
			*c = *c - 32;
		}
	}
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	char	str[] = "hello";

	ft_striteri(str, ft_toup);
	printf("%s\n", str);
	return (0);
}*/
