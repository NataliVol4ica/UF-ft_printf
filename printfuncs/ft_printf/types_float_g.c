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
#include <float.h>

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
	//printf("exp %d\n", expon);

	if (FLT_ROUNDS == 1)
	{
		int	j;
		j = 0;
		while (++j <= p->precision)
			if (f->num[j] != '9')
				break;
		if (j > p->precision)
			if (f->num[j] >= '5')
				expon++;
	}
	else if ((FLT_ROUNDS == 2 && !p->isnegative) || (FLT_ROUNDS == 3 && p->isnegative))
	{
		int	j;
		j = 1;
		while (j <= p->precision && j < (int)f->size)
			if (f->num[j++] != '9')
				break;
		if (j > p->precision && !(p->precision == 1 && f->num[1] != '9'))
		{
			j--;
			while (++j < (int)f->size)
				if (f->num[j] != '0')
					break;
			if (j != (int)f->size)
				expon++;
		}
	}
	//printf("exp %d\n", expon);
	print_sign_pref(p);
	if (expon < -4 || expon >= p->precision)
	{
		f->point = 1;
		while (f->num[f->point - 1] == '0')
			f->point++;
		if (!f->num[f->point - 1])
			f->point = 2;
		//printf("%.70s\n", f->num);
		//if (f->num[1] != '0') 
		p->precision--;
		//printf("%d\n", p->precision);
		round_float(f, p, 1);
		if (f->num[0] != '0')
			f->point--;
		//printf("%.70s\n", f->num);
		p->precision = first_prec;
		p->precision = p->precision == 0 ? 1 : p->precision;
		p->precision = p->precision == -1 ? 6 : p->precision;
		print_symbol(p, f->num[f->point - 1]);
		p->precision--;
		if (!p->flags->hash)
			while (f->num[f->point + p->precision - 1] == '0')
				p->precision--;
		//printf("%d\n", p->precision);
		while (f->num[f->size - 1] == '0')
			f->size--;
		//printf("%c\n", f->num[f->size - 1]);
		//printf("%s\n", f->num);
		i = f->point - 1;
		if (p->flags->hash || (p->precision > 0 && f->size > f->point))
			print_symbol(p, '.');
		while (p->precision > 0 && ++i < f->size)
		{
			print_symbol(p, f->num[i]);
			p->precision--;
		}
		if (p->flags->hash)
			while (p->precision-- > 0)
				print_symbol(p, '0');
		print_e_exp(p, expon, c);
		float_flags(p);
	}
	else
	{
		//printf("%.70s\n", f->num);
		p->precision = first_prec;
		p->precision = p->precision == 0 ? 1 : p->precision;
		p->precision = p->precision == -1 ? 6 : p->precision;
		//printf("prec %d point %zu\n", p->precision, f->point);
		//p->precision = f->point - expon;
		//p->precision -= f->point;
		//p->precision += f->num[1] != '0' ? 1 : 0;
		//if (f->num[1] != '0') p->precision++;
	//	printf("%.70s\n", f->num);
		//printf("prec %d point %zu\n", p->precision, f->point);
		round_float_g(f, p, 0);
		//printf("%.70s\n", f->num);
		//printf("%.70s\n", f->num);
		//p->precision = first_prec;
		//p->precision = p->precision == 0 ? 1 : p->precision;
		//p->precision = p->precision == -1 ? 6 : p->precision;
		i = f->num[0] == '0' && f->point > 1 ? 0 : -1;
		while (++i < f->point)
		{
			print_symbol(p, f->num[i]);
			p->precision--;
		}
		i--;
		while (f->num[f->size - 1] == '0')
			f->size--;
		if (i == 1 && f->num[1] == '0' && f->size != 0)
			p->precision++;
		if (!p->flags->hash)
			while (f->num[f->point + p->precision - 1] == '0')
				p->precision--;
		if (p->flags->hash || (p->precision > 0 && f->size > f->point))
			print_symbol(p, '.');
		while (p->precision > 0 && ++i < f->size)
		{
			print_symbol(p, f->num[i]);
			p->precision--;
		}
		if (p->flags->hash)
			while (p->precision-- > 0)
				print_symbol(p, '0');
		float_flags(p);
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
