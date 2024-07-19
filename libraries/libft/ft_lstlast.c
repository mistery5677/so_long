/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:59:09 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 13:59:09 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;
	int		count;
	int		size;

	size = ft_lstsize(lst);
	temp = lst;
	count = 1;
	while (count < size)
	{
		temp = lst->next;
		lst = temp;
		count++;
	}
	return (temp);
}

/*int main()
{
	t_list *head = NULL;

	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "Node 1";
	node2->content = "Node 2";
	node3->content = "Node 3";

	head = node3;
	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;

	t_list *last = ft_lstlast(head);
	printf("Last list: %s\n", (char *)last->content);

	free(node1);
	free(node2);
	free(node3);
}*/