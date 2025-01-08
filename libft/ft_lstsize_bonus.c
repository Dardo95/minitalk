/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:44:25 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/07 13:31:08 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*int main()
{
    t_list  *node1;
    t_list  *node2;
    t_list  *node3;
    t_list  *head;

    node1 = ft_lstnew("nodo 1");
    node2 = ft_lstnew("nodo 2");
    node3 = ft_lstnew("nodo 3");

    node1->next = node2;
    node2->next = node3;
	head = node1;

    int size = ft_lstsize(head);
    printf("the size is: %d\n", size);
	free(head);
    return 0;
}*/
