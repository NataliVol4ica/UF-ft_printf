/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

void	type_ebe(va_list *ap, t_params *p, char c)
{
	size_t			savelen;
	int				until;
	long double		num;
	size_t			i;
	int				point;
	static t_float	*f = NULL;
	
	num = p->length == BL ? va_arg(*ap, long double) : va_arg(*ap, double);
	p->isnegative = num < 0 ? 1 : 0;
	num = num < 0 ? -num : num;
	savelen = p->toprint->len;
	p->precision = p->precision < 0 ? 6 : p->precision;
	f = !f ? init_t_float() : f;
	set_float(f, num);
	point = f->point;
	f->point = 1;
	while (f->num[f->point - 1] == '0')
		f->point++;
	if (!f->num[f->point - 1])
		f->point = 2;
	round_float(f, p);
	if (f->num[0] != '0')
	{
		f->point--;
		p->precision--;
	}
	p->pref_len = p->isnegative || p->flags->plus || p->flags->space ? 1 : 0;
	print_sign_pref(p);
	i = -1;
	while (f->num[i + 1] == '0')
		i++;
	if (!f->num[i + 1])
		i = 0;
	while (++i < f->point)
		print_symbol(p, f->num[i]);
	if (!(!p->flags->hash && f->size == f->point))
	{
		if ((size_t)p->precision != f->point || p->flags->hash)
			print_symbol(p, '.');
		while (i < f->size && i < (size_t)p->precision)
		{
			print_symbol(p, f->num[i]);
			i++;
		}
		i -= 1;
		while (++i < (size_t)p->precision)
			print_symbol(p, '0');
	}
	point -= f->point;
	print_symbol(p, c);
	print_symbol(p, point < 0 ? '-' : '+');
	point = point < 0 ? -point : point;
	print_symbol(p, '0' + point / 10);
	print_symbol(p, '0' + point % 10);
	until = p->width - (p->toprint->len - savelen);
	if (p->flags->minus)
		for (int j = 0; j <until; j++)
			print_symbol(p, ' ');
	else if (p->flags->zero)
	{
		rev_str(&p->toprint->str[savelen + p->pref_len], &p->toprint->str[p->toprint->len - 1]);
		for (int j = 0; j <until; j++)
			print_symbol(p, '0');
		rev_str(&p->toprint->str[savelen + p->pref_len], &p->toprint->str[p->toprint->len - 1]);
	}
	else
	{
		rev_str(&p->toprint->str[savelen], &p->toprint->str[p->toprint->len - 1]);
		for (int j = 0; j <until; j++)
			print_symbol(p, ' ');
		rev_str(&p->toprint->str[savelen], &p->toprint->str[p->toprint->len - 1]);
	}
}

void	type_e(va_list *ap, t_params *p)
{
	type_ebe(ap, p, 'e');
}

void	type_be(va_list *ap, t_params *p)
{
	type_ebe(ap, p, 'E');
}
