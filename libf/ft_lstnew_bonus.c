/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:04:53 by enogueir          #+#    #+#             */
/*   Updated: 2024/10/07 13:20:36 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

/*int	main()
{
	t_list	*node1;

	node1 = ft_lstnew("hola");
	if (node1 != NULL)
	{
		printf("Direction node: %p: ", (void *)node1);
		printf("%s", (char *)node1->content);
	}
	return (0);
}*/
