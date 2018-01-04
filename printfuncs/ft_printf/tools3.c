/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:20 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:24:21 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_consts.h"

long double	get_float_num(va_list *ap, t_params *p)
{
	long double num;

	num = p->length == BL ? va_arg(*ap, long double) : va_arg(*ap, double);
	p->isnegative = num < 0 ? 1 : 0;
	num = num < 0 ? -num : num;
	p->savelen = p->toprint->len;
	p->precision = p->precision < 0 ? 6 : p->precision;
	return (num);
}

void		float_flags(t_params *p)
{
	int		until;
	int		j;
	size_t	from;
	char	c;
	
	j = 0;
	until = p->width - (p->toprint->len - p->savelen);
	if (p->flags->minus)
	{
		while (j++ < until)
			print_symbol(p, ' ');
		return ;
	}
	from = p->flags->zero ? p->savelen + p->pref_len : p->savelen;
	c = p->flags->zero ? '0' : ' ';
	rev_str(&p->toprint->str[from],
		&p->toprint->str[p->toprint->len - 1]);
	while (j++ < until)
		print_symbol(p, c);
	rev_str(&p->toprint->str[from],
		&p->toprint->str[p->toprint->len - 1]);
}
