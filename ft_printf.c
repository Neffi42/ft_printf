/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:04:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/10 10:00:20 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	read_flag(const char *s, va_list *ap, int i, int *len)
{
	int		l;

	l = 0;
	if (ft_strchr(CONV_FLAGS, s[i + 1]))
	{
		l = convert_flag(s[i + 1], ap);
		if (!l)
		{
			*len += 1;
			return (0);
		}
		else if (l == -1)
			return (1);
		*len += l;
	}
	return (1);
}

int	convert_flag(char c, va_list *ap)
{
	if (c == 'c')
		return (count_putchar_fd(va_arg(*ap, int), 1));
	else if (c == 's')
		return (s_flag(va_arg(*ap, char *)));
	else if (c == 'p')
		return (p_flag(va_arg(*ap, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(*ap, int), DECI_BASE));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), DECI_BASE));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), X_BASE_LO));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*ap, unsigned int), X_BASE_UP));
	else if (c == '%')
		return (count_putchar_fd('%', 1));
	return (0);
}
