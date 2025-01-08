/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:13:25 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/30 13:10:39 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_num(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = (long)n;
	len = ft_count_num(n);
	if (n < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		str[len - 1] = ((nb % 10) + '0');
		nb = (nb / 10);
		len--;
	}
	str[len - 1] = ((nb % 10) + '0');
	return (str);
}

/* 
int main() {
    int test_cases[] = {
		0,
		1,
		-1,
		42,
		-42,
		123456,
		-123456,
		2147483647,
		-2147483648
	};

	int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
	int i = 0;

	while (i < num_cases) {
		char *result = ft_itoa(test_cases[i]);
		printf("ft_itoa(%d) = \"%s\"\n", test_cases[i], result);
		free(result);
		i++;
	}

	return 0;
} */
