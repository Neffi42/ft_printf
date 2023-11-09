/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:20:03 by abasdere          #+#    #+#             */
/*   Updated: 2023/09/22 19:13:29 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	read_flag(const char *s, va_list *ap, int i, int *len);
int	convert_flag(char c, va_list *ap);
int	count_putchar_fd(char c, int fd);
int	count_putstr_fd(const char *s, int fd);
int	unsg_putnbr_base(unsigned int n, char *base);
int	ft_putnbr_base(long n, char *base);

# define CONV_FLAGS "cspdiuxX%"
# define DECI_BASE  "0123456789"
# define HEX_BASE_LO "0123456789abcdef"
# define HEX_BASE_UP "0123456789ABCDEF"
# define MAX_UNSG_INT 4294967296

typedef struct s_arg
{
	int		pad_flag;
	void	*conv_flag;
}	t_arg;

#endif
