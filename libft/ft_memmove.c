/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:51:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/14 11:22:56 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = n;
		while (i-- > 0)
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
