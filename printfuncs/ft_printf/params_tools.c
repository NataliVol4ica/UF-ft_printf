/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:51:15 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 20:51:15 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void		read_params(t_params *p, char *fmt, size_t *pos, va_list *ap)
{
	int			i;

	i = *pos;
	p->n = get_n(&fmt[i], &i);
	zero_params(p);
	get_flags(&fmt[i], &i, p->flags);
	p->width = get_width(&fmt[i], &i, ap);
	p->precision = get_precision(&fmt[i], &i, ap);
	p->length = get_length(&fmt[i], &i);
	p->flags->minus = p->width < 0 ? 1 : p->flags->minus;
	p->width = p->width < 0 ? -p->width : p->width;
	p->flags->zero = p->flags->minus ? 0 : p->flags->zero;
	*pos = i;
}

t_params	*init_params(void)
{
	t_params	*p;

	p = (t_params*)malloc(sizeof(t_params));
	p->flags = (t_flags*)malloc(sizeof(t_flags));
	p->output = (t_output*)malloc(sizeof(t_output));
	p->prefix = (t_output*)malloc(sizeof(t_output));
	p->output->str = ft_strnew(MAX_STR);
	p->prefix->str = ft_strnew(2);
	zero_params(p);
	return (p);
}

void		del_params(t_params **p)
{
	if (p)
	{
		if (*p)
		{
			free((*p)->flags);
			free(*p);
		}
		*p = NULL;
	}
}

void		zero_params(t_params *p)
{
	p->flags->space = 0;
	p->flags->hash = 0;
	p->flags->plus = 0;
	p->flags->minus = 0;
	p->flags->zero = 0;
	p->flags->apostrophe = 0;
	p->output->len = 0;
	p->prefix->len = 0;
}
