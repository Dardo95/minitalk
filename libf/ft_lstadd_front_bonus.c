/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:39:31 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/07 13:34:36 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*list;

	node1 = ft_lstnew("hello");
	node2 = ft_lstnew("world");
	list = NULL;
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
    while (list)                                                                 
    {                                                                           
        printf("Content node: %s\n", (char *)list->content);               
        list = list->next;
      
        return (0);
}*/
