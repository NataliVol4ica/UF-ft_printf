/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

static void	set_sign(t_params *p, intmax_t num)
{
	if (num >= 0)
	{
		if (p->flags->plus)
			p->prefix->str[p->prefix->len++] = '+';
		else if (p->flags->space)
			p->prefix->str[p->prefix->len++] = ' ';
	}
	else if (num < 0)
		p->prefix->str[p->prefix->len++] = '-';
}

size_t		type_di(va_list *ap, t_params *p)
{
	intmax_t	num;
	uintmax_t	n;

	num = va_arg(*ap, intmax_t);
	convert_di(&num, p);
	set_sign(p, num);
	n = num < 0 ? -num : num;
	printf_putnbr_uns(n, p);
	p->flags->zero = p->precision >= 0 ? 0 : p->flags->zero;
	check_width(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_bd(va_list *ap, t_params *p)
{
	intmax_t	num;
	uintmax_t	n;

	num = va_arg(*ap, long int);
	set_sign(p, num);
	n = num < 0 ? -num : num;
	printf_putnbr_uns(n, p);
	p->flags->zero = p->precision >= 0 ? 0 : p->flags->zero;
	check_width(p);
	return (p->output->len + p->prefix->len + p->width);
}

size_t		type_u(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	convert_ouxbx(&num, p);
	printf_putnbr_uns(num, p);
	p->flags->zero = p->precision >= 0 ? 0 : p->flags->zero;
	check_width(p);
	return (p->output->len + p->width);
}

size_t		type_bu(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, unsigned long);
	printf_putnbr_uns(num, p);
	p->flags->zero = p->precision >= 0 ? 0 : p->flags->zero;
	check_width(p);
	return (p->output->len + p->width);
}
