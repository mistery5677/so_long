/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:04:42 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 14:04:50 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*temp_str1;
	char	*temp_str2;

	temp_str1 = (char *)str1;
	temp_str2 = (char *)str2;
	i = -1;
	if (str1 == NULL && str2 == NULL)
		return (0);
	if (str1 > str2)
	{
		while (n-- > 0)
			temp_str1[n] = temp_str2[n];
	}
	else
	{
		while (++i < n)
			temp_str1[i] = temp_str2[i];
	}
	return (str1);
}
