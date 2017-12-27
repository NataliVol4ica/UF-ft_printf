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
	p->alphabet = NUMBERS_S;
}

t_params	*init_params(void)
{
	t_params	*p;

	p = (t_params*)malloc(sizeof(t_params));
	p->flags = (t_flags*)malloc(sizeof(t_flags));
	p->output = (t_output*)malloc(sizeof(t_output));
	p->prefix = (t_output*)malloc(sizeof(t_output));
	p->toprint = (t_print_str*)malloc(sizeof(t_print_str));
	p->output->str = (char*)malloc(sizeof(char) * (MAX_STR + 1));
	p->prefix->str = (char*)malloc(sizeof(char) * 3);
	p->toprint->str = (char*)malloc(sizeof(char) * (START_SIZE + 1));
	p->toprint->size = START_SIZE;
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

void		realloc_toprint(t_print_str *tp)
{
	char	*new;
	size_t	i;

	new = (char*)malloc(sizeof(char) * (tp->size * 2 + 1));
	i = -1;
	while (++i < tp->len)
		new[i] = tp->str[i];
	tp->str[tp->len] = '\0';
	free(tp->str);
	tp->str = new;
	tp->size *= 2;
}
