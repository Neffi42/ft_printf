/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:42:32 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/16 10:19:56 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	count_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	putstr_len(const char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	return ((int)len);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = c;
	i = 0;
	while (((char *)s)[i])
	{
		if (ch == ((char *)s)[i])
			return (((char *)s) + i);
		i++;
	}
	if (ch == ((char *)s)[i])
		return (((char *)s) + i);
	return (NULL);
}
