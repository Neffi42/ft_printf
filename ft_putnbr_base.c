/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:56:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/21 14:06:10 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_base_recu(long n, char *base, size_t b_size)
{
	if (n / b_size)
		ft_putnbr_base_recu(n / b_size, base, b_size);
	n = base[n % b_size];
	write(1, &n, 1);
}

static int	ft_check_base(char *base, size_t b_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (b_size <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[i + 1] != '\0' && base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	size_t	b_size;
	long	n;

	n = nbr;
	b_size = ft_strlen(base);
	if (ft_check_base(base, b_size))
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		ft_putnbr_base_recu(n, base, b_size);
	}
	return ;
}
