/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*get_frac_str(long double num_frac)
{
	static t_str	*str = NULL;
	size_t			i;

	str = str ? str : init_t_str(FRAC_DEFAULT_SIZE);
	i = -1;
	while (++i < str->size)
		str->str[i] = '0';
	i = -1;
	while (++i < 201)
	{
		num_frac *= 2.0;
		if (num_frac >= 1.0) //переделать на сохранение в строку
		{
			num_frac -= 1.0;
			dec_sum(str->str, g_decs[i]);
		}
	}
	return (str->str);
}

static char	*get_int_str(long double *num)
{
	uintmax_t	ts;
	char		*str;
	size_t		i;
	size_t		stepen_dvoiki;

	str = ft_strnew(20);
	stepen_dvoiki = 0;
	while (*num > ULLONG_MAX)
	{
		*num /= 2.0;
		stepen_dvoiki++;
	}
	ts = (uintmax_t)*num;
	*num -= ts;
	i = 0;
	if (ts == 0)
		str[i++] = '0';
	else
		while (ts > 0) // переделать цикл под разложение в двоичное
		{
			str[i++] = ts % 10 + '0';
			ts /= 10;
		}
	rev_str(str, &str[i - 1]);
	return (get_f_mul(stepen_dvoiki, str));
}

void		float_to_binary(t_float *f, long double num)
{
	char	*s1;
	char	*s2;

	s1 = get_int_str(&num);
	s2 = get_frac_str(num);
}

void		type_aba(va_list *ap, t_params *p, char c, _Bool is_cap)
{
	long double		num;
	static t_float	*f = NULL;

	num = get_float_num(ap, p, is_cap);
	if (num < 0.0)
		return ;
	f = !f ? init_t_float() : f;
	float_to_binary(f, num);
	(void)c;
}
