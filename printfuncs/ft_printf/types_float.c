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
#include "locale.h"

void	type_fbf(va_list *ap, t_params *p)
{
	size_t			savelen;
	int				until;
	long double		num;
	size_t			i;
	struct lconv	*loc;
	static t_float	*f = NULL;
	
	loc = localeconv();
	num = p->length == BL ? va_arg(*ap, long double) : va_arg(*ap, double);
	p->isnegative = num < 0 ? 1 : 0;
	num = num < 0 ? -num : num;
	savelen = p->toprint->len;
	p->precision = p->precision < 0 ? 6 : p->precision;
	f = !f ? init_t_float() : f;
	set_float(f, num);
	round_float(f, p);
	p->pref_len = p->isnegative || p->flags->plus || p->flags->space ? 1 : 0;
	print_sign_pref(p);
	i = f->num[0] == '0' && f->point > 1 ? 0 : -1;
	while (++i < f->point)
	{
		if (p->flags->apostrophe && p->toprint->len != savelen + p->pref_len && (f->point - i) % 3 == 0)
			print_str(p, loc->thousands_sep, 1);
		print_symbol(p, f->num[i]);
	}
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
