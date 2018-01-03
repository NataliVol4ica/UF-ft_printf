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
	size_t			i;
	static t_float	*f = NULL;
	
	num = va_arg(*ap, double);
	p->precision = p->precision < 0 ? 6 : p->precision;
	f = !f ? init_t_float() : f;
	set_float(f, num);
	round_float(f, p);
	if (!f->is_pos)
		print_symbol(p, '-');
	i = f->num[0] == '0' && f->point > 1 ? 0 : -1;
	while (++i < f->point)
		print_symbol(p, f->num[i]);
	if (!(!p->flags->hash && f->size == f->point))
	{
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
