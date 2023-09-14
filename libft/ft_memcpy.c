/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:41:39 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/04 20:02:46 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_ptr;
	unsigned char		*dest_ptr;

	i = -1;
	src_ptr = (const unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	while (++i < n)
		dest_ptr[i] = src_ptr[i];
	return (dest);
}
