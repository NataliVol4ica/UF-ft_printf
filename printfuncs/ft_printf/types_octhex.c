/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_octhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

size_t		type_o(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	convert_ouxbx(&num, p);
	if (p->flags->hash && num != 0)
	{
		p->prefix->str[p->prefix->len++] = '0';
		p->precision -= 1;
	}
	printf_convert_base(num, 8, p, '0');
	p->flags->zero = p->precision >= 0 ? 0 : p->flags->zero;
	if (p->precision > 0 && p->output->len > (uintmax_t)p->precision)
		p->output->len = (uintmax_t)p->precision;
	check_width(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_bo(va_list *ap, t_params *p)
{
	unsigned long	num;

	num = va_arg(*ap, unsigned long);
	if (p->flags->hash && num != 0)
		p->prefix->str[p->prefix->len++] = '0';
	printf_convert_base(num, 8, p, '0');
	check_width(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_x(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	convert_ouxbx(&num, p);
	if (p->flags->hash && num != 0)
	{
		p->prefix->str[p->prefix->len++] = '0';
		p->prefix->str[p->prefix->len++] = 'x';
	}
	printf_convert_base(num, 16, p, 'a');
	p->flags->zero = p->precision >= 0 ? 0 : p->flags->zero;
	check_width(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_bx(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	convert_ouxbx(&num, p);
	if (p->flags->hash && num != 0)
	{
		p->prefix->str[p->prefix->len++] = '0';
		p->prefix->str[p->prefix->len++] = 'X';
	}
	printf_convert_base(num, 16, p, 'A');
	p->flags->zero = p->precision >= 0 ? 0 : p->flags->zero;
	if (p->precision > 0 && p->output->len > (uintmax_t)p->precision)
		p->output->len = (uintmax_t)p->precision;
	check_width(p);
	return (p->output->len + p->prefix->len + p->width);
}
