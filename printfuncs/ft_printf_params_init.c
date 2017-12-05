/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params_init.c                            :+:      :+:    :+:   */
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
	zero_flags_str(at->flags, at->output);
	get_flags(&fmt[i], &i, at->flags);
	at->width = get_width(&fmt[i], &i, ap);
	at->precision = get_precision(&fmt[i], &i, ap);
	at->length = get_length(&fmt[i], &i);
	*pos = i;
}

t_params	*init_params(void)
{
	t_params	*at;

	at = (t_params*)malloc(sizeof(t_params));
	at->flags = (t_flags*)malloc(sizeof(t_flags));
	at->output = (t_output*)malloc(sizeof(t_output));
	at->n = 0;
	at->width = 0;
	at->precision = 0;
	at->length = EMPTY;
	at->output->str = ft_strnew(MAX_STR);
	zero_flags_str(at->flags, at->output);
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

void		zero_flags_str(t_flags *f, t_output *outp)
{
	f->space = 0;
	f->hash = 0;
	f->plus = 0;
	f->minus = 0;
	f->zero = 0;
	outp->str[0] = '\0';
	outp->len = 0;
}

/*
** void		print_params(t_params *t)
** {
** 	printf("\n=======\n");
** 	printf("n = %zu\n", t->n);
** 	printf("Flags = %d%d%d%d%d\n", t->flags->space, t->flags->hash,
**	t->flags->plus, t->flags->minus, t->flags->zero);
** 	printf("Width = %zu\n", t->width);
** 	printf("Precision = %zu\n", t->precision);
** 	printf("Length = %u\n", t->length);
** 	printf("fi\n");
** }
*/
