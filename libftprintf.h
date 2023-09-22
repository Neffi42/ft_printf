/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:20:03 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/22 09:48:32 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putnbr_base(long n, char *base);

# define CHAR_FLAGS "-0.# +"
# define LEN_FLAGS "*$12"
# define CONV_FLAGS "cspdiuxX%"
# define DECI_BASE  "0123456789"
# define HEXA_BASE_LO "0123456789abcdef"
# define HEXA_BASE_UP "0123456789ABCDEF"

typedef struct s_arg
{
	int		pad_flag;
	void	*conv_flag;
}	t_arg;

#endif
