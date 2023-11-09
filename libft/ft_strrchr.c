/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:51:35 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/07 11:15:44 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	str = (char *)s;
	ch = c;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (ch == str[i])
			return (str + i);
		i--;
	}
	if (ch == str[i])
		return (str + i);
	return (NULL);
}
