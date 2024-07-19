/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:00:21 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 14:00:21 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*int main() {

		printf("TESTING FT_LSTNEW\n");
	char *lstnew_content = "Hello, world!";
	t_list *lstnew_node = ft_lstnew(lstnew_content);
	if (lstnew_node)
	{
		printf("Node created successfully.\n");
		if (lstnew_node->content)
			printf("Content: %s\n", (char*)lstnew_node->content);
		else
			printf("Content is NULL.\n");

		// Free the allocated memory
		free(lstnew_node->content);
		free(lstnew_node);
	}
	else
		printf("Failed to create node.\n");
}*/