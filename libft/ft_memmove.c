/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:51:49 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/04 20:25:53 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	if (dest - src <= 0)
	{
		i = -1;
		while (++i < n)
			dest_ptr[i] = src_ptr[i];
	}
	else
	{
		i = n;
		while (--i > 0)
			dest_ptr[i] = src_ptr[i];
		dest_ptr[i] = src_ptr[i];
	}
	return (dest);
}
