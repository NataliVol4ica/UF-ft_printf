/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
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

t_float		*init_t_float(void)
{
	t_float	*f;

	f = (t_float*)malloc(sizeof(t_float));
	f->num = (char*)malloc(sizeof(char) * (FLOAT_STR_MAX_SIZE + 1));
	f->size = 0;
	f->point = -1;
	return (f);
}

t_str		*init_t_str(size_t size)
{
	t_str	*tstr;

	tstr = (t_str*)malloc(sizeof(t_str));
	tstr->str = ft_strnew(size + 1);
	tstr->str[size] = '\0';
	tstr->size = size;
	return (tstr);
}

static void	final_round(t_float *f, t_params *p)
{
	int j;

	j = p->precision - 1;
	while (--j >= 0)
	{
		f->num[j + 1] -= '0';
		f->num[j] += f->num[j + 1] / 10;
		f->num[j + 1] %= 10;
		f->num[j + 1] += '0';
	}
}

void		round_float(t_float *f, t_params *p)
{
	size_t	j;

	p->precision += f->point;
	if ((size_t)p->precision > f->size)
		return;
	if (FLT_ROUNDS == 1)
	{
		if (!((size_t)p->precision == f->point &&
		(f->point > 2 || f->num[1] == '0')))
			f->num[p->precision - 1] += ((f->num[p->precision] - '0') / 5);
		final_round(f, p);
	}
	else if ((FLT_ROUNDS == 2 && !p->isnegative) || (FLT_ROUNDS == 3 && p->isnegative))
	{
		j = p->precision - 1;
		while (++j < f->size)
			if (f->num[j] != '0')
				break;
		if (j != f->size && !(f->num[1] == '0'))
			f->num[p->precision - 1]++;
		final_round(f, p);
	}
}
