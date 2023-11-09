/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:56:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/09 16:40:57 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_recu(long n, char *base, size_t b_size, int *len)
{
	*len = *len + 1;
	if (n / b_size)
		ft_putnbr_base_recu(n / b_size, base, b_size, len);
	n = base[n % b_size];
	write(1, &n, 1);
}

int	ft_check_base(char *base, size_t b_size)
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

int	ft_putnbr_base(long n, char *base)
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
		ft_putnbr_base_recu(n, base, b_size, &len);
	}
	return (len);
}
