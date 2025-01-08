/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:16:45 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/28 16:17:52 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static	char	ft_toup(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z' && c)
	{
		return (c - 32);
	}
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*nstr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	while (s[i])
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[len] = '\0';
	return (nstr);
}
/*
int	main() {
	char *str = ft_strmapi("helloMy999999999name", ft_toup);
	if (str)
	{
		printf("%s\n", str);
		free(str);
	}
	else
	{
	printf("Faile operation because de result is NULL");
	}
	return 0;
}*/
