/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:20:03 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/21 13:57:22 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_putnbr_base(int nbr, char *base);

# define CHAR_FLAGS "-0.# +"
# define LEN_FLAGS "*$12"
# define CONV_FLAGS "cspdiuxX%"

typedef struct s_arg
{
	int		pad_flag;
	void	*conv_flag;
}	t_arg;

#endif
