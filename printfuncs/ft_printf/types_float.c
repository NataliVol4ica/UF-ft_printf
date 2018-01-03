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

void	type_fbf(va_list *ap, t_params *p)
{
	double			num;
	static t_float	*f = NULL;
	
	num = va_arg(*ap, double);
	p->precision = p->precision < 0 ? 6 : p->precision;
	f = !f ? init_t_float() : f;
	set_float(f, num);
	if ((size_t)p->precision < f->size - f->point)
		round_float(&f->num[f->point], p, f->is_pos);
	f->num[f->point + p->precision] = '\0';
	for (size_t i = 0; i < f->point; i++)
		print_symbol(p, f->num[i]);
	if (!(!p->flags->hash && f->size == f->point))
	{
		print_symbol(p, '.');
		f->size = f->point + p->precision < f->size ? f->point + p->precision : f->size;
		for (size_t i = f->point; i < f->size; i++)
			print_symbol(p, f->num[i]);
		p->precision += f->point;
		for (int i = f->size; i < p->precision; i++)
			print_symbol(p, '0');
	}
}
