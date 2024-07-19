/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:01:42 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 14:01:42 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy_s;
	unsigned char	copy_c;
	size_t			i;

	copy_s = (unsigned char *)s;
	copy_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (copy_s[i] == copy_c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
