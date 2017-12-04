/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:51:15 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 20:51:15 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_params	*read_params(char *fmt, size_t *pos, va_list *ap)
{
	t_params	*at;
	int			i;

	if ((at = (t_params*)malloc(sizeof(t_params))))
	{
		i = *pos;
		at->n = get_n(&fmt[i], &i);
		at->flags = get_flags(&fmt[i], &i);
		at->width = get_width(&fmt[i], &i, ap);
		at->precision = get_precision(&fmt[i], &i, ap);
		at->length = get_length(&fmt[i]);
		i += ft_strlen(at->length);
		*pos = i;
	}
	(void)fmt;
	return (at);
}

void		del_params(t_params **at)
{
	if (at)
	{
		if (*at)
		{
			ft_strdel(&((*at)->length));
			ft_strdel(&((*at)->flags));
			free(*at);
		}
		*at = NULL;
	}
}
