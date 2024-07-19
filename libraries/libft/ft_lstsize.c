/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:01:01 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 14:01:01 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = (t_list *)lst;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
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

	int size = ft_lstsize(&head);
	printf("Size of the list: %d\n", size);

	free(node1);
	free(node2);
	free(node3);

}*/