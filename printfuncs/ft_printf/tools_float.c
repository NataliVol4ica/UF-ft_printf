/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_float.                                       :+:      :+:    :+:   */
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
#include <limits.h>

#define frac_default_size 200

void	dec_sum(char *to, char *s) //200
{
	for (int i = 0; i < 200; i++)
	{
		to[i] -= '0';
		to[i] += s[i];
	}
	for (int i = 199; i > 0; i--)
	{
		to[i] -= '0';
		to[i - 1] += to[i] / 10;
		to[i] = to[i] % 10;
		to[i] += '0'; 
	}
}

char	*get_frac_str(long double num_frac)
{
	static t_str	*str = NULL;
	int				i;

	str = str ? str : init_t_str(frac_default_size);
	i = -1;
	while (++i < str->size)
		str->str[i] = '0';
	i = -1;
	while (++i < 201)
	{
		num_frac *= 2.0;
		if (num_frac >= 1.0)
		{
			num_frac -= 1.0;
			dec_sum(str->str, g_decs[i]);
		}
	}
	return (str->str);
}

void	int_sum(char *str, char *s)
{
	size_t	i;

	i = 310;
	while (--i > 0)
	{
		str[i] += s[i];
		str[i] -= '0';
		str[i] -= '0';
		str[i - 1] += str[i] / 10;
		str[i] = str[i] % 10;
		str[i] += '0';

	}
}

char	*get_int_str(long double *num)
{
	uintmax_t	ts;
	char	*str;
	size_t	i;
	size_t	stepen_dvoiki;
	size_t	mass_index;
	char	*temp;

	str = ft_strnew(20);
	stepen_dvoiki = 0;
	while (*num > ULLONG_MAX)
	{
		*num /= 2.0;
		stepen_dvoiki ++;
	}
	ts = (uintmax_t)*num;
	*num -= ts;
	i = 0;
	if (ts == 0)
		str[i++] = '0';
	else
		while (ts > 0)
		{
			str[i++] = ts % 10 + '0';
			ts /= 10;
		}
	rev_str(str, &str[i - 1]);
	mass_index = TWOS_POWS_MASS_SIZE;
	while (stepen_dvoiki > 0 && mass_index--)
		while (stepen_dvoiki >= g_twos_pows[mass_index].pow)
		{
			stepen_dvoiki -= g_twos_pows[mass_index].pow;
			temp = long_mul(str, g_twos_pows[mass_index].val);
			free(str);
			str = temp;
		}
	return (str);
}

void	set_float(t_float *f, long double num)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = get_int_str(&num);
	s2 = get_frac_str(num);
	f->point = ft_strlen(s1);
	f->size = f->point + frac_default_size;
	i = -1;
	while (++i < f->point)
		f->num[i] = s1[i];
	i = -1;
	while (++i < frac_default_size)
		f->num[f->point + i] = s2[i];
	f->num[f->point + i] = '\0';
	free(s1);
}
