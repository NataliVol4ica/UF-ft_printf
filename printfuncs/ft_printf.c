/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int		print_c(char c)
{
	ft_putchar(c);
	return (1);
}

int		print_str(char *c)
{
	ft_putstr(c);
	return (ft_strlen(c));
}

int		print_signed_num(long long n)
{
	ft_putnbr(n);
	return (ft_count_digits(n, 10) + n < 0 ? 1 : 0);
}

int		print_unsigned_num(unsigned long n)
{
	ft_putnbr_uns(n);
	return (ft_count_digits_uns(n, 10));
}

int		ft_printf(char *fmt, ...)
{
	va_list ap;
	int		i;
	int		ret;

	va_start(ap, fmt);
	i = -1;
	ret = 0;
	if (!fmt)
		return (ret);
	while (fmt[++i])
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			if (fmt[i] == '%')
				ret += print_c('%');
			else if (fmt[i] == 's')
				ret += print_str(va_arg(ap, char *));
			else if (fmt[i] == 'd')
				ret += print_signed_num(va_arg(ap, int));
			else if (fmt[i] == 'D')
				ret += print_unsigned_num(va_arg(ap, unsigned int));
			else if (fmt[i] == 'c')
				ret += print_c((char)va_arg(ap, int));
			else if (fmt[i] == 'C')
				ret += print_c((unsigned char)va_arg(ap, int));
			else if (fmt[i] == 'u')
				ret += print_unsigned_num(va_arg(ap, unsigned int));
			else if (fmt[i] == 'o' || fmt[i] == 'O')
				ret += print_str(ft_itoa_base_uns(va_arg(ap, unsigned int), 8));
			else if (fmt[i] == 'x')
				ret += print_str(ft_itoa_base_uns(va_arg(ap, unsigned int), 16));
			else if (fmt[i] == 'X')
				ret += print_str(ft_strupper(ft_itoa_base_uns(va_arg(ap, unsigned int), 16)));
		}
		else
			ret += print_c(fmt[i]);
	va_end(ap);
	return (ret);
}
