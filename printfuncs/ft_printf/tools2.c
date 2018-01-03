/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
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

t_float	*init_t_float(void)
{
	t_float	*f;
	size_t	i;

	f = (t_float*)malloc(sizeof(t_float));
	f->is_pos = 1;
	f->num = (char*)malloc(sizeof(char) * (513));
	i = -1;
	while (++i < 512)
		f->num[i] = '0';
	f->num[i] = '\0';
	f->size = 0;
	f->point = -1;
	f->mal_len = 512;
	return (f);
}

void	zero_t_float(t_float *f)
{
	(void)f;
}

t_str	*init_t_str(size_t size)
{
	t_str	*tstr;

	tstr = (t_str*)malloc(sizeof(t_str));
	tstr->str = ft_strnew(size + 1);
	tstr->str[size] = '\0';
	tstr->size = size;
	return (tstr);
}

void	round_float(char *str, t_params *p, _Bool is_pos)
{
	int		i;

	i = p->precision - 1;
	if ((FLT_ROUNDS == 2 && is_pos) || (FLT_ROUNDS == 3 && !is_pos) || FLT_ROUNDS == 1)
		{
			str[i] += ((str[i + 1] - '0') / 5);
			while (--i >= 0)
			{
				str[i + 1] -= '0';
				str[i] += str[i + 1] / 10;
				str[i + 1] %= 10;
				str[i + 1] += '0';
			}
		}
}