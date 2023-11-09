/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:42:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/09 16:41:12 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_putchar_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	count_putstr_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	return ((int)ft_strlen(s));
}

int	s_flag(char *s)
{
	if (!s)
		return (count_putstr_fd("(null)", 1));
	if (!(*s))
		return (-1);
	return (count_putstr_fd(s, 1));
}

int	p_flag(unsigned long p)
{
	if (!p)
		return (count_putstr_fd("(nil)", 1));
	ft_putstr_fd("0x", 1);
	return (2 + ft_putun_nbr_base((long long)p, X_BASE_LO));
}
