/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:58:36 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 13:58:36 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (lst != NULL)
	{
		f(temp->content);
		temp = temp->next;
		lst = temp;
	}
}

#include <stdio.h> // For printf

// A function to be applied to the content of each list node
void iterate_content(void *content)
{
    int *num = (int *)content;
    printf("%d\n", *num);
}
