/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:32:29 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/26 17:32:49 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	lendst = ft_strlen(dst);
	i = 0;
	if (!size)
		return (size + lensrc);
	while (src[i] && (i + lendst < size - 1))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	if (lendst < size)
		return (lendst + lensrc);
	return (size + lensrc);
}
/*
int main(void)
{
	char src[5] = "hello";
	char dst[10] = "house";
	ft_strlcat(dst, src, 10);
	printf("%s", dst);
}*/
