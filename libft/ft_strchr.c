/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:48:56 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/06 12:16:20 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	str = (char *)s;
	ch = c;
	i = 0;
	while (str[i])
	{
		if (ch == str[i])
			return (str + i);
		i++;
	}
	if (ch == str[i])
		return (str + i);
	return (NULL);
}
