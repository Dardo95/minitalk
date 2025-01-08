/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:44:08 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/26 18:20:50 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len);
	return (str);
}
/*
int	main(void)
{
	char *s = "hello";
	char *str;

	str = ft_strdup(s);
	printf("%s", str);
	free(str);
	return(0);
}*/
