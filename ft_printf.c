/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:04:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/22 09:52:28 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	convert_flag(char c, va_list *ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*ap, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (2 + ft_putnbr_base((long)va_arg(*ap, char *), HEXA_BASE_LO));
	}
	else if (c == 'd')
		return (ft_putnbr_base(va_arg(*ap, int), DECI_BASE));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*ap, int), HEXA_BASE_LO));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*ap, int), HEXA_BASE_UP));
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

static int	read_flag(const char *s, va_list *ap, int i, int *len)
{
	char	c;

	c = s[i +1];
	if (ft_strnstr(CHAR_FLAGS, &c, ft_strlen(CHAR_FLAGS)))
		return (0);
	else if (ft_strnstr(LEN_FLAGS, &c, ft_strlen(LEN_FLAGS)))
		return (0);
	else if (ft_strnstr(CONV_FLAGS, &c, ft_strlen(CONV_FLAGS)))
		*len += convert_flag(s[i + 1], ap);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		start;
	int		len;
	va_list	ap;

	i = -1;
	start = 0;
	len = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (!s[i + 1])
			write(1, &(s[start]), i + 1 - start);
		if (s[i] == '%')
		{
			write(1, &(s[start]), i - start);
			i += read_flag(s, &ap, i, &len);
			start = i + 1;
		}
		else
			len++;
	}
	va_end(ap);
	return (len);
}
