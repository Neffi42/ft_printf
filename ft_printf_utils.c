/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:42:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/09 11:44:15 by abasdere         ###   ########.fr       */
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

int	unsg_putnbr_base(unsigned int n, char *base)
{
	return (ft_putnbr_base(n, base));
}
