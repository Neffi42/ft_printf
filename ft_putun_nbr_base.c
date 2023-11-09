/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:24:25 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/09 16:42:08 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nb_recu(unsigned long n, char *base, size_t b_size, int *len)
{
	*len = *len + 1;
	if (n / b_size)
		ft_nb_recu(n / b_size, base, b_size, len);
	n = base[n % b_size];
	write(1, &n, 1);
}

int	ft_putun_nbr_base(unsigned long n, char *base)
{
	size_t	b_size;
	int		len;

	len = 0;
	b_size = ft_strlen(base);
	if (ft_check_base(base, b_size))
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			len++;
		}
		ft_nb_recu(n, base, b_size, &len);
	}
	return (len);
}
