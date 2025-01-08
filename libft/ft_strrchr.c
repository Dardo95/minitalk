/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:33:24 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/23 12:33:29 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	lenstr;

	lenstr = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[lenstr]);
	while (lenstr >= 0)
	{
		if (s[lenstr] == (char)c)
			return ((char *)&s[lenstr]);
		lenstr--;
	}
	return (NULL);
}
/*
int main(void) {
    char str[] = "hello World, my name is Dardo";
    char *result = ft_strrchr(str, 'l');

    if (result) {
        if (*result == '\0')
                printf("%s this character is null\n", result);
        printf("%s\n", result);
    } else {
        printf("character not found.\n");
    }

    return 0;
}*/
