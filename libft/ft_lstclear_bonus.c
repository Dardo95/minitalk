/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:20:02 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/07 19:59:41 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list2;

	if (!del)
		return ;
	while (*lst)
	{
		list2 = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = list2;
	}
}

/*int main(void)
{
        t_list *list = NULL;
        t_list *node1 = ft_lstnew(ft_strdup("First node"));
        t_list *node2 = ft_lstnew(ft_strdup("Second node"));
        t_list *node3 = ft_lstnew(ft_strdup("Third node"));
        ft_lstadd_back(&list, node1);
        ft_lstadd_back(&list, node2);
        ft_lstadd_back(&list, node3);

        t_list *list2 = list;

        while (list2)
        {
                printf("%s\n", (char *)list2-> content);
                list2 = list2->next;
        }
		ft_lstclear(&list, &free);
        if (list2 == NULL)
        {
                printf("Eliminate Node\n");
        }
        else
        {
                printf("Not eliminated all the node\n");
        }
        return (0);
}*/
