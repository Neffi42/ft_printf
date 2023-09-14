/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:21:16 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/05 19:56:30 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	size_l;

	i = 0;
	size_l = ft_strlen(little);
	if (!size_l)
		return ((char *)(&(big[i])));
	while (i < len && big[i])
	{
		if (!ft_strncmp(big + i, little, size_l))
			return ((char *)(&(big[i])));
		i++;
	}
	return (NULL);
}
