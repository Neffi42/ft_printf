/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:51:35 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/15 08:59:23 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = c;
	i = ft_strlen(((char *)s));
	while (i > 0)
	{
		if (ch == ((char *)s)[i])
			return (((char *)s) + i);
		i--;
	}
	if (ch == ((char *)s)[i])
		return (((char *)s) + i);
	return (NULL);
}
