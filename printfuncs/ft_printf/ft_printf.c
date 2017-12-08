/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_funcs.h"

int			ft_printf(char *fmt, ...)
{
	va_list 		ap;
	size_t			i;
	size_t			j;
	size_t			ret;
	intmax_t		fret;
	size_t			save_pos;
	static t_params	*p = NULL;

	p = p ? p : init_params();
	va_start(ap, fmt);
	i = -1;
	ret = 0;
	if (!fmt)
		return (ret);
	while (fmt[++i])
		if (fmt[i++] == '%')
		{
			save_pos = i;
			read_params(p, fmt, &i, &ap);
			
			j = -1;
			fret = -1;
			while (++j < NOFFUNCS)
			{
				if (fmt[i] == g_type_funcs[j].c)
				{
					fret += fret == -1 ? 1 : 0;
					fret += g_type_funcs[j].func(&ap, p);
				}
			}
			ret += fret > 0 ? fret : 0;
			if (fret == -1)
			{
				if (fmt[i] == 'n')
					type_n(&ap, p, ret);
				else
					i--;
					//final_putstr(&fmt[save_pos], i-- - save_pos);
			}
		}
		else
			ret += ft_putchar(fmt[--i]);
	va_end(ap);
	return (ret);
}
