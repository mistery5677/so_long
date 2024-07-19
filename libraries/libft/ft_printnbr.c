/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:28 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/17 12:26:03 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	divide_nbrbase(long long int nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len);
}

size_t	ft_printnbr(int nbr)
{
	size_t	len;

	len = 0;
	ft_putnbr_fd(nbr, 1);
	len = divide_nbrbase(nbr, 10);
	return (len);
}

size_t	ft_print_unsigned(unsigned int nbr)
{
	size_t	len;

	len = 0;
	len = divide_nbrbase(nbr, 10);
	if (nbr >= 10)
	{
		ft_print_unsigned(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr <= 9)
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
	}
	return (len);
}

size_t	ft_print_hex(unsigned int nbr, int format)
{
	size_t	len;

	len = divide_nbrbase(nbr, 16);
	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16, format);
		nbr = nbr % 16;
	}
	if (nbr <= 9)
		nbr = nbr + '0';
	else
		nbr = nbr + format - 10;
	write(1, &nbr, 1);
	return (len);
}
