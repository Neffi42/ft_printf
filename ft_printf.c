/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:04:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/19 15:38:15 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	// va_list	ap;
	int		count_args;
	// char	*x;

	count_args = count_char(format, '%');
	printf("%d\n", count_args);
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
