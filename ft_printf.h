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
int	ft_putnbr_base(long n, char *base);
int	ft_putun_nbr_base(unsigned long n, char *base);
int	s_flag(char *s);
int	p_flag(unsigned long p);
int	ft_check_base(char *base, size_t b_size);

# define FLAGS "-0.# +$2*1cspdiuxX%"
# define CONV_FLAGS "cspdiuxX%"
# define DECI_BASE  "0123456789"
# define X_BASE_LO "0123456789abcdef"
# define X_BASE_UP "0123456789ABCDEF"

typedef struct s_arg
{
	int		pad_flag;
	void	*conv_flag;
}	t_arg;

#endif
