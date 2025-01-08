/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:32:15 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/27 12:47:36 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(void) {
    char str[] = "Hello World";
    char *result = ft_strchr(str, 'l');

    if (result) {
        if (*result == '\0')
		printf("%s this character is null\n", result);
	printf("%s\n", result);
    } else {
        printf("Character not found.\n");
    }

    return 0;
}*/
