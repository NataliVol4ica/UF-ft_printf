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

#include "libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_funcs.h"
#include <unistd.h>

int			ft_printf(const char *fmt, ...)
{
	va_list			ap;
	size_t			i;
	size_t			j;
	static t_params	*p = NULL;

	p = p ? p : init_params();
	p->toprint->len = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			read_params(p, (char*)fmt, &i, &ap);
			j = -1;
			while (++j < NOFFUNCS)
				if (fmt[i] == g_type_funcs[j].c)
				{
					g_type_funcs[j].func(&ap, p);
					break ;
				}
			if (j == NOFFUNCS)
				type_none(fmt[i], p);
		}
		else
			print_symbol(p, fmt[i]);
		i++;
	}
	va_end(ap);
	write (1, p->toprint->str, p->toprint->len);
	return (p->toprint->len);
}
