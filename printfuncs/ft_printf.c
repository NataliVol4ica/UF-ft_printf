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
#include <stdint.h>
#include "../includes/ft_printf.h"
#include <stdio.h>

size_t		type_percent(va_list *ap, t_params *p)
{
	(void)ap;
	(void)p;
	return (ft_putchar('%'));
}	

size_t		type_cbc(va_list *ap, t_params *p)
{
	(void)ap;
	(void)p;
	return (ft_putchar((char)va_arg(*ap, int)));
}

size_t		type_s(va_list *ap, t_params *p)
{
	char	*str;

	(void)p;
	str = va_arg(*ap, char*);
	return (ft_putstr(str));
}

size_t		type_di(va_list *ap, t_params *p)
{
	size_t		ret;
	intmax_t	num;

	num = va_arg(*ap, intmax_t);
	/*if (!(convert_numeric_signed(&num, p)))
		return (print_signed_num_other_len(ap, p));*/
	ret = 0;
	convert_numeric_signed(&num, p);
	react_on_flags_di(num, p->flags);
	ret += ft_putnbr(num);
	return (ret);
}

size_t		type_bdubu(va_list *ap, t_params *at)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	/*if (!(convert_numeric_unsigned(&num, at)))
		return (print_unsigned_num_other_len(ap, at));*/
	convert_numeric_unsigned(&num, at);
	return (ft_putnbr_uns(num));
}

size_t		type_obo(va_list *ap, t_params *p)
{
	size_t		ret;
	char		*str;
	uintmax_t	num;

	ret = 0;
	num = va_arg(*ap, uintmax_t);
	convert_numeric_unsigned(&num, p);
	str = ft_itoa_base_uns(num, 8);
	ret += react_on_flags_obo(p->flags);
	ret += ft_putstr(str);
	return (ret);
}

size_t		type_x(va_list *ap, t_params *p)
{
	size_t		ret;
	char		*str;
	uintmax_t	num;

	ret = 0;
	num = va_arg(*ap, uintmax_t);
	convert_numeric_unsigned(&num, p);
	str = ft_itoa_base_uns(num, 16);
	ret += react_on_flags_x(p->flags);
	ret += ft_putstr(str);
	return (ret);
}

size_t		type_bx(va_list *ap, t_params *p)
{
	size_t		ret;
	char		*str;
	uintmax_t	num;

	ret = 0;
	num = va_arg(*ap, uintmax_t);
	convert_numeric_unsigned(&num, p);
	str = ft_itoa_base_uns(num, 16);
	ret += react_on_flags_bx(p->flags);
	ret += ft_putstr(str);
	return (ret);
}

void		type_n(va_list *ap, int ret)
{
	int	*n;

	n = va_arg(*ap, int*);
	*n = ret;
}

int			ft_printf(char *fmt, ...)
{
	va_list 	ap;
	size_t		i;
	size_t		j;
	size_t		ret;
	size_t		fret;
	t_params	*at;

	va_start(ap, fmt);
	i = -1;
	ret = 0;
	if (!fmt)
		return (ret);
	while (fmt[++i])
		if (fmt[i] == '%')
		{
			i++;
			at = read_params(fmt, &i, &ap);
			j = -1;
			fret = 0;
			while (++j < 13)
				if (fmt[i] == type_funcs[i].c)
					fret += type_funcs[i].func(&ap, at);
			ret += fret;
			if (fret == 0)
				if (fmt[i] == 'n')
					type_n(&ap, ret);
			del_params(&at);
		}
		else
			ret += ft_putchar(fmt[i]);
	va_end(ap);
	return (ret);
}
