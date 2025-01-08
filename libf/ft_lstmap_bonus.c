/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:39:35 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/07 19:52:24 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void *ft_dup(void *content)
{
    return (ft_strdup((char *)content));
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_map;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	list_map = NULL;
	while (lst)
	{
		node = ft_lstnew(NULL);
		if (!node)
		{
			ft_lstclear(&list_map, del);
			return (NULL);
		}
		node->content = f(lst->content);
		ft_lstadd_back(&list_map, node);
		lst = lst->next;
	}
	return (list_map);
}

/*int main(void)
{
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(ft_strdup("first node")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("seccond node")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Third node")));

	t_list *new_list = ft_lstmap(list, ft_dup, &free);

	t_list *list2 = new_list;
	while (list2)
	{
		printf("%s\n", (char *)list2->content);
		list2 = list2->next;
	}

	ft_lstclear(&list, &free);
    ft_lstclear(&new_list, &free);

	return (0);
}*/
