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

size_t		met_percent(va_list *ap, t_params *p, char c, size_t *ret)
{
	size_t	j;
	int		fret;

	j = -1;
	fret = -1;
	while (++j < NOFFUNCS)
	{
		if (c == g_type_funcs[j].c)
		{
			fret += fret == -1 ? 1 : 0;
			fret += g_type_funcs[j].func(ap, p);
		}
	}
	if (fret == -1)
	{
		if (c == 'n')
			type_n(ap, p, *ret);
		else
			return (1);
	}
	*ret += fret > 0 ? fret : 0;
	return (0);
}

int			ft_printf(char *fmt, ...)
{
	va_list			ap;
	size_t			i;
	size_t			ret;
	static t_params	*p = NULL;

	p = p ? p : init_params();
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	i = -1;
	ret = 0;
	while (fmt[++i])
		if (fmt[i++] == '%')
		{
			read_params(p, fmt, &i, &ap);
			i -= met_percent(&ap, p, fmt[i], &ret);
		}
		else
			ret += ft_putchar(fmt[--i]);
	va_end(ap);
	return (ret);
}
