/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:19:44 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/07 17:18:56 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*int main(void)
{
   	t_list *list = NULL;

	t_list *node1 = ft_lstnew(ft_strdup("First node"));
	t_list *node2 = ft_lstnew(ft_strdup("Second node"));
	t_list *node3 = ft_lstnew(ft_strdup("Third nodo"));

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	t_list *list2 = list;

	while (list2)
	{
		printf("%s\n", (char *)list2-> content);
		list = list2->next;
		ft_lstdelone(list2, &free);
		list2 = list;
	}

	if (list2 == NULL)
	{
		printf("Se han eliminado los nodos\n");
	}
	else
	{
		printf("No se han eliminado todos los nodos\n");
	}
	return (0);
}*/
