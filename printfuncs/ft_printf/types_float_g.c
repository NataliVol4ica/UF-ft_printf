/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

static void	type_gbg(va_list *ap, t_params *p, char c, _Bool is_cap)
{
	long double		num;
	int				expon;
	size_t			i;
	int				j;
	size_t			save;
	size_t			saveprec;
	static t_float	*f = NULL;
	
	num = get_float_num(ap, p, is_cap);
	p->precision = p->precision == 0 ? 1 : p->precision;
	if (num < 0.0)
		return ;
	f = !f ? init_t_float() : f;
	set_float(f, num);
	expon = f->point;
	saveprec = p->precision;
	p->precision -= f->point - 1;
	round_float(f, p);
	i = 0;
	while (f->num[i] == '0')
		i++;
	if (i == f->size)
		i = 0;
	expon -= i + 1;
	p->precision = saveprec;
	if (expon < -4 || expon >= p->precision)
	{
		;//print exp
	}
	else
	{
		i = 0;
		while (f->num[i] == '0' && i < f->point - 1)
			i++;
		i--;
		f->size = p->precision + (f->num[0] == '0' ? 1 : 0);
		while (++i < f->point)
			print_symbol(p, f->num[i]);
		j = f->size - 1;
		while (f->num[j] == '0' && j > -1)
			j--;
		f->size = f->size > (size_t)j ? j + 1 : f->size;
		if (f->size > f->point)
		{
			i--;
			print_symbol(p, '.');
			save = p->toprint->len;
			while (++i < f->size)
				print_symbol(p, f->num[i]);
			float_flags(p);
		}
	}
	(void)c;
}

void		type_g(va_list *ap, t_params *p)
{
	type_gbg(ap, p, 'e', 0);
}

void		type_bg(va_list *ap, t_params *p)
{
	type_gbg(ap, p, 'E', 1);
}
