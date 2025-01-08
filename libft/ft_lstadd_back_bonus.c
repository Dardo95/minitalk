/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:51:55 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/07 17:14:54 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lastnode = ft_lstlast(*lst);
	lastnode->next = new;
}

/*int main()
{
    t_list  *node1;
    t_list  *node2;
    t_list  *new_node;
    t_list  *head;

    node1 = ft_lstnew("node 1");
    node2 = ft_lstnew("node 2");

    node1->next = node2;
    head = node1;
    new_node = ft_lstnew("new node at the end");

    ft_lstadd_back(&head, new_node);

	while (head)
    {
        printf("Content node: %s\n", (char *)head->content);
        head = head->next;
    }

    return 0;
}*/
