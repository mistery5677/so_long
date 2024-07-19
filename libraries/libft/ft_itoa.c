/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:56:11 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 13:56:46 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	divide_nbr(int n)
{
	int			i;
	long int	nbr;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void	build_p(char *str, int n, int size)
{
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
	}
}

void	build_n(char *str, int n, int size)
{
	long int	nbr;

	nbr = n;
	nbr *= -1;
	str[size] = '\0';
	while (--size > 0)
	{
		str[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str[size] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = divide_nbr(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n >= 0)
		build_p(str, n, size);
	else
		build_n(str, n, size);
	return (str);
}

/*int main()
{
	printf("123 --> %s\n", ft_itoa(-2147483648));
	//printf("0 --> %s\n", ft_itoa(0));
	//printf("-123 --> %s\n", ft_itoa(-12321312));
	//printf("divided by %d\n", divide_nbr(n_itoa));
}*/