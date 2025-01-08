/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:24:14 by enogueir          #+#    #+#             */
/*   Updated: 2024/09/25 16:51:20 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-' )
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int main(void) {
    const char *test1 = "   -123";
    const char *test2 = "42";
    const char *test3 = "   +0";
    const char *test4 = "--+-189";
    const char *test5 = "  +2147abc56";
    const char *test6 = " -2147483648";

    printf("Test 1: \"%s\" -> %d\n", test1, atoi(test1));
    printf("Test 2: \"%s\" -> %d\n", test2, atoi(test2));
    printf("Test 3: \"%s\" -> %d\n", test3, atoi(test3));
    printf("Test 4: \"%s\" -> %d\n", test4, atoi(test4));
    printf("Test 5: \"%s\" -> %d\n", test5, atoi(test5));
    printf("Test 6: \"%s\" -> %d\n", test6, ft_atoi(test6));

    return 0;
}*/
