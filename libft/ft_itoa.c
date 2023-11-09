/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:49:26 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/07 14:08:29 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	int	get_nbr_char(long nbr)
{
	int	count;

	count = 1;
	while (nbr / 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		count;
	char	*str_n;

	nbr = n;
	count = get_nbr_char(nbr);
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	str_n = ft_calloc(count + 1, sizeof(char));
	if (!str_n)
		return (NULL);
	str_n[count--] = '\0';
	if (!nbr)
		str_n[count--] = nbr + '0';
	while (nbr)
	{
		str_n[count--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (!count)
		str_n[count] = '-';
	return (str_n);
}
