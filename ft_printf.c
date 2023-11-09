/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:04:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/09 11:04:01 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_putstr_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	return ((int)ft_strlen(s));
}

static int	unsg_putnbr_base(unsigned int n, char *base)
{
	return (ft_putnbr_base(n, base));
}

static int	convert_flag(char c, va_list *ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*ap, int), 1);
	else if (c == 's')
		return (count_putstr_fd(va_arg(*ap, char *), 1));
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (2 + ft_putnbr_base((long)va_arg(*ap, char *), HEX_BASE_LO));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(*ap, int), DECI_BASE));
	else if (c == 'u')
		return (unsg_putnbr_base((MAX_UNSG_INT + va_arg(*ap, int)), DECI_BASE));
	else if (c == 'x')
		return (unsg_putnbr_base(MAX_UNSG_INT + va_arg(*ap, int), HEX_BASE_LO));
	else if (c == 'X')
		return (unsg_putnbr_base(MAX_UNSG_INT + va_arg(*ap, int), HEX_BASE_UP));
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		return (0);
	return (1);
}

static int	read_flag(const char *s, va_list *ap, int i, int *len)
{
	char	c;
	int		l;

	c = s[i + 1];
	l = 0;
	if (ft_strnstr(CHAR_FLAGS, &c, ft_strlen(CHAR_FLAGS)))
		return (0);
	else if (ft_strnstr(LEN_FLAGS, &c, ft_strlen(LEN_FLAGS)))
		return (0);
	else if (ft_strnstr(CONV_FLAGS, &c, ft_strlen(CONV_FLAGS)))
	{
		l = convert_flag(s[i + 1], ap);
		if (!l)
		{
			*len += 1;
			return (0);
		}
		*len += l;
	}
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
