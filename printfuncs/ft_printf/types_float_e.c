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

static void	print_e_float(t_params *p, t_float *f)
{
	size_t			i;

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
}

static void	print_e_exp(t_params *p, int point, char c)
{
	size_t			savelen_exp;

	print_symbol(p, c);
	print_symbol(p, point < 0 ? '-' : '+');
	point = point < 0 ? -point : point;
	if (point == 0)
		print_str(p, "00", 1);
	else if (point < 10)
	{
		print_symbol(p, '0' + point / 10);
		print_symbol(p, '0' + point % 10);
	}
	else
	{
		savelen_exp = p->toprint->len;
		while (point > 0)
		{
			print_symbol(p, '0' + point % 10);
			point /= 10;
		}
		rev_str(&p->toprint->str[savelen_exp],
			&p->toprint->str[p->toprint->len - 1]);
	}
}

static void	type_ebe(va_list *ap, t_params *p, char c)
{
	long double		num;
	int				point;
	static t_float	*f = NULL;
	
	num = get_float_num(ap, p);
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
	print_e_float(p, f);
	point -= f->point;
	print_e_exp(p, point, c);
	float_flags(p);
}

void		type_e(va_list *ap, t_params *p)
{
	type_ebe(ap, p, 'e');
}

void		type_be(va_list *ap, t_params *p)
{
	type_ebe(ap, p, 'E');
}
