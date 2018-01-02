/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:20 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:24:21 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_consts.h"
#include "libft.h"
#include <stdlib.h>
#include <float.h>
#include <math.h>

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

void	realloc_t_float(t_float *f)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(char) * (f->mal_len * 2 + 1));
	i = -1;
	while (++i < f->mal_len)
		str[i] = f->num[i];
	i = -1;
	while (++i < f->mal_len)
		str[f->mal_len + i] = '\0';
	str[f->mal_len * 2] = '\0';
	free(f->num);
	f->num = str;
}

void	realloc_t_str(t_str *tstr)
{
	free(tstr->str);
	tstr->str = ft_strnew(tstr->size * 2 + 1);
	tstr->size = tstr->size * 2;
}
