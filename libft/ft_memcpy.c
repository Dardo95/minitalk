/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:53:29 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/25 16:50:43 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	src[] = "Hello, world!";

	char dest[20];
	ft_memcpy(dest, src, ft_strlen(src) + 1); 
	printf("original string: %s\n", src);
	printf("string copy: %s\n", dest);
	return (0);
} */
