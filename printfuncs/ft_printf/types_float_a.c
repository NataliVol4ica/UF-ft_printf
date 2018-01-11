/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		type_aba(va_list *ap, t_params *p, char c, _Bool is_cap)
{
	long double		num;
	static t_float	*f = NULL;

	num = get_float_num(ap, p, is_cap);
	if (num < 0.0)
		return ;
	f = !f ? init_t_float() : f;
	set_float(f, num);
	(void)c;
}
