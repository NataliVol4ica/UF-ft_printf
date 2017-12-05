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


void		read_params(t_params *at, char *fmt, size_t *pos, va_list *ap)
{
	int			i;

	i = *pos;
	at->n = get_n(&fmt[i], &i);
	get_flags(&fmt[i], &i, at->flags);
	at->width = get_width(&fmt[i], &i, ap);
	at->precision = get_precision(&fmt[i], &i, ap);
	at->length = get_length(&fmt[i], &i);
	*pos = i;
}

t_params	*init_params(void)
{
	t_params	*at;

	if ((at = (t_params*)malloc(sizeof(t_params))))
	{
		if ((at->flags = (t_flags*)malloc(sizeof(t_flags))))
		{
			at->n = 0;
			at->flags->space = 0;
			at->flags->hash = 0;
			at->flags->plus = 0;
			at->flags->minus = 0;
			at->flags->zero = 0;
			at->width = 0;
			at->precision = 0;
			at->length = EMPTY;
		}
		else
			free(at);
	}
	return (at);
}

void		del_params(t_params **at)
{
	if (at)
	{
		if (*at)
		{
			free((*at)->flags);
			free(*at);
		}
		*at = NULL;
	}
}
