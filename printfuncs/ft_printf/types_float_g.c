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

static void	print_e_exp(t_params *p, int expon, char c)
{
	size_t			savelen_exp;

	print_symbol(p, c);
	print_symbol(p, expon < 0 ? '-' : '+');
	expon = expon < 0 ? -expon : expon;
	if (expon == 0)
		print_str(p, "00", 1);
	else if (expon < 10)
	{
		print_symbol(p, '0' + expon / 10);
		print_symbol(p, '0' + expon % 10);
	}
	else
	{
		savelen_exp = p->toprint->len;
		while (expon > 0)
		{
			print_symbol(p, '0' + expon % 10);
			expon /= 10;
		}
		rev_str(&p->toprint->str[savelen_exp],
			&p->toprint->str[p->toprint->len - 1]);
	}
}

static void	type_gbg(va_list *ap, t_params *p, char c, _Bool is_cap)
{
	long double		num;
	int				expon;
	size_t			i;
	int				j;
	size_t			save;
	size_t			saveprec;
	int				first_prec;
	static t_float	*f = NULL;
	
	first_prec = p->precision;
	num = get_float_num(ap, p, is_cap);
	p->precision = p->precision == 0 ? 1 : p->precision;
	if (num < 0.0)
		return ;
	f = !f ? init_t_float() : f;
	set_float(f, num);
	i = 0;
	while (f->num[i] == '0')
		i++;
	if (i == f->size)
		i = 1;
	expon = f->point - i - 1;
	print_sign_pref(p);
	//printf("expon %d precision %d\n", expon, p->precision);
	if (expon < -4 || expon >= p->precision)
	{
		saveprec = p->precision;
		p->precision += i - f->point;
		round_float(f, p);
		p->precision = saveprec;
		i -= f->num[i - 1] == '0' ? 0 : 1;
		expon += f->num[i - 1] == '0' ? 0 : 1;
		print_symbol(p, f->num[i++]);
		j = i + p->precision;
		if (!p->flags->hash)
			while (f->num[--j] == '0')
				p->precision--;
		if (p->precision > 1 || p->flags->hash)
		{
			if (p->flags->hash && first_prec == -6)
				p->precision += 6;
			print_symbol(p, '.');
			f->size = p->precision + (f->num[0] == '0' ? 1 : 0);
			j = 0;
			while (++j < p->precision)	
				print_symbol(p, f->num[i + j - 1]);		
		}
		print_e_exp(p, expon, c);
		float_flags(p);
	}
	else
	{
		saveprec = p->precision;
		p->precision -= f->point - 1;
		round_float(f, p);
		p->precision = saveprec;
		i = 0;
		while (f->num[i] == '0' && i < f->point - 1)
			i++;
		i--;
		if ((int)f->size > p->precision + (f->num[0] == '0' ? 1 : 0))
			f->size = p->precision + (f->num[0] == '0' ? 1 : 0);
		while (++i < f->point)
			print_symbol(p, f->num[i]);
		j = f->size - 1;
		while (f->num[j] == '0' && j > -1)
			j--;
		j = j == -1 ? 0 : j;
		f->size = f->size > (size_t)j && !p->flags->hash ? j + 1 : f->size;
		if (f->size > f->point || p->flags->hash)
		{
			//if (p->flags->hash && f->size <= f->point && first_prec == -1)
		//		f->size += 6;
			i--;
			print_symbol(p, '.');
			save = p->toprint->len;
			while (++i < f->size)
				print_symbol(p, f->num[i]);
			if (p->flags->hash)
				while ((int)++i < p->precision)
					print_symbol(p, '0');
			float_flags(p);
		}
	}
}

void		type_g(va_list *ap, t_params *p)
{
	type_gbg(ap, p, 'e', 0);
}

void		type_bg(va_list *ap, t_params *p)
{
	type_gbg(ap, p, 'E', 1);
}
