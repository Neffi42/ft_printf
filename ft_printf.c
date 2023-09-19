/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:04:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/19 17:17:37 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	int	start;
	// va_list	ap;
	// char	*x;

	i = -1;
	start = 0;
	while (format[++i])
	{
		if (format[i] == '%' || (!format[i + 1] && start))
		{
			write(1, &(format[start]), i + 1 - start);
			start = i + 1;
		}
	}
	if (!start)
		ft_putstr_fd(format, 1);
	// va_start(ap, format);
	// x = va_arg(ap, char *);
	// printf("%s\n%d\n", x, count_args);
	// va_end(ap);
	return (0);
}

int	count_char(const char *s, char c)
{
	int			count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}
