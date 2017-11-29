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
# include <stdio.h>

int		print_symbol(char c)
{
	ft_putchar(c);
	return (1);
}

int		print_line(char *c)
{
	ft_putstr(c);
	return (ft_strlen(c));
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
				ret += print_symbol('%');
			else if (fmt[i] == 's')
				ret += print_line(va_arg(ap, char *));
		}
		else
			ret += print_symbol(fmt[i]);
	va_end(ap);
	return (ret);
}