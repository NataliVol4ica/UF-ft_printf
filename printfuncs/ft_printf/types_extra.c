/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

size_t		type_p(va_list *ap, t_params *p)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	p->prefix->str[p->prefix->len++] = '0';
	p->prefix->str[p->prefix->len++] = 'x';
	printf_convert_base(num, 16, p, 'a');
	check_width(p);
	return (p->output->len + p->prefix->len + p->width);
}

void		type_n(va_list *ap, t_params *p, size_t ret)
{
	if (p->length == HH)
		*(va_arg(*ap, signed char*)) = (signed char)ret;
	else if (p->length == H)
		*(va_arg(*ap, short*)) = (short)ret;
	else if (p->length == LL)
		*(va_arg(*ap, long long*)) = (long long)ret;
	else if (p->length == L)
		*(va_arg(*ap, long*)) = (long)ret;
	else if (p->length == J)
		*(va_arg(*ap, intmax_t*)) = (intmax_t)ret;
	else if (p->length == Z)
		*(va_arg(*ap, size_t*)) = (size_t)ret;
	else
		*(va_arg(*ap, int*)) = (int)ret;
}
