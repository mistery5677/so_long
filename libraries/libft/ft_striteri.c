/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:19:22 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 15:19:22 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/*void my_function(unsigned int index, char *character)
{
		*character = *character + 1;
}

#include <stdio.h>
int	main(void) {
	char strmapi_string[] = "Hello";
	printf("Input string: %s\n", strmapi_string);

	ft_striteri(strmapi_string, &my_function);

	printf("Result: %s\n", strmapi_string);
}*/