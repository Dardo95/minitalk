/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:41:53 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/01 19:53:23 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* int main() {
	int *arr;
	int n = 5;
	int i = 0;

	arr = (int *)ft_calloc(n, sizeof(int));
	if (arr == NULL) {
		printf("Error to asign memory.\n");
		return 1;
	}
	printf("Coontent array next calloc:\n");

	while (i < n) {
		printf("%d ", arr[i]);
		i++;
	}

	printf("\n");
	free(arr);

	return 0;
} */
