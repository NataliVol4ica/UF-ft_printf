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
#include <stdint.h>

void	type_fbf(va_list *ap, t_params *p)
{
	double			num;
	static t_float	*f = NULL;
	//char	*str;
	//size_t	size;

	num = va_arg(*ap, double);
	p->precision = p->precision < 0 ? 6 : p->precision;
	f = !f ? init_t_float() : f;
	set_float(f, num, p);
}
