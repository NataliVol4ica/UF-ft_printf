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
#include "../includes/ft_printf_funcs.h"
#include <stdio.h>

size_t		type_percent(va_list *ap, t_params *p)
{
	(void)ap;
	printf_putchar('%', p);
	check_width_str(p);
	return (p->output->len + p->width);
}

size_t		type_cbc(va_list *ap, t_params *p)
{
	printf_putchar((char)va_arg(*ap, int), p);
	check_width_str(p);
	return (p->output->len + p->width);
}

size_t		type_s(va_list *ap, t_params *p)
{
	char	*temp;

	temp = p->output->str;
	p->output->str = va_arg(*ap, char*);
	if (p->output->str == NULL)
	{
		p->output->str = "(null)";
		p->output->len = 6;
	}
	else
		p->output->len = ft_strlen(p->output->str);
	check_width_str(p);
	p->output->str = temp;
	return (p->output->len + p->width);
}

size_t		type_di(va_list *ap, t_params *p)
{
	intmax_t	num;
	uintmax_t	n;

	num = va_arg(*ap, intmax_t);
	convert_numeric_signed(&num, p);
	if (num >= 0)
	{
		if (p->flags->plus)
			p->prefix->str[p->prefix->len++] = '+';
		else if (p->flags->space)
			p->prefix->str[p->prefix->len++] = ' ';
	}
	else if (num < 0)
		p->prefix->str[p->prefix->len++] = '-';
	n = num < 0 ? -num : num;
	printf_putnbr_uns(n, p);
	check_width_numeric(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_bdubu(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	printf("%zu\n", num);
	convert_numeric_unsigned(&num, p);
	printf("%zu\n", num);
	printf_putnbr_uns(num, p);
	check_width_numeric(p);
	return (p->output->len + p->width);
}

size_t		type_obo(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	convert_numeric_unsigned(&num, p);
	if (p->flags->hash && num != 0)
		p->prefix->str[p->prefix->len++] = '0';
	printf_convert_oboxbx(num, 8, p, '0');
	check_width_numeric(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_x(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	convert_numeric_unsigned(&num, p);
	if (p->flags->hash && num != 0)
	{
		p->prefix->str[p->prefix->len++] = '0';
		p->prefix->str[p->prefix->len++] = 'x';
	}
	printf_convert_oboxbx(num, 16, p, 'a');
	check_width_numeric(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_bx(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	convert_numeric_unsigned(&num, p);
	if (p->flags->hash && num != 0)
	{
		p->prefix->str[p->prefix->len++] = '0';
		p->prefix->str[p->prefix->len++] = 'X';
	}
	printf_convert_oboxbx(num, 16, p, 'A');
	check_width_numeric(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_p(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	p->prefix->str[p->prefix->len++] = '0';
	p->prefix->str[p->prefix->len++] = 'x';
	printf_convert_oboxbx(num, 16, p, 'a');
	check_width_numeric(p);
	return (p->output->len + p->prefix->len + p->width);
}

void		type_n(va_list *ap, int ret)
{
	int	*n;

	n = va_arg(*ap, int*);
	*n = ret;
}

int			ft_printf(char *fmt, ...)
{
	va_list 		ap;
	size_t			i;
	size_t			j;
	size_t			ret;
	size_t			fret;
	size_t			save_pos;
	static t_params	*p = NULL;

	p = p ? p : init_params();
	va_start(ap, fmt);
	i = -1;
	ret = 0;
	if (!fmt)
		return (ret);
	while (fmt[++i])
		if (fmt[i++] == '%')
		{
			save_pos = i;
			read_params(p, fmt, &i, &ap);
			j = -1;
			fret = 0;
			while (++j < NOFFUNCS)
			{
				if (fmt[i] == g_type_funcs[j].c)
					fret += g_type_funcs[j].func(&ap, p);
			}
			ret += fret;
			if (fret == 0)
			{
				if (fmt[i] == 'n')
					type_n(&ap, ret);
				else
					final_putstr(&fmt[save_pos], i - save_pos);
			}
		}
		else
			ret += ft_putchar(fmt[--i]);
	va_end(ap);
	return (ret);
}
