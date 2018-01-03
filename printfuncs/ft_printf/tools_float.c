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
#include <math.h>

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

char	*get_int_str(long double num_int, size_t *len)
{
	static char	*str = NULL;
	size_t		i;
	size_t		count;

	if (!str)
		str = (char*)malloc(sizeof(char) * 311);
	i = -1;
	while (++i < 310)
		str[i] = '0';
	str[310] = '\0';
	i = 0;
	count = 0;
	while (num_int > 1.0)
	{
		if ((int)fmodl(num_int, 2.0) == 1)
		{
			count++;
			int_sum(str, g_twos[i]);
		}
		num_int /= 2;
		i++;
	}
	if (count == 0 && i > 0)
		int_sum(str, g_twos[i]);
	i = 0;
	if (str[i] == '0')
		while (str[i + 1] == '0' && str[i + 2])
			i++;
	*len = 310 - i;
	return (&str[i]);
}

void	set_float(t_float *f, long double num)
{
	long double	num_int;
	long double	num_frac;
	char	*s1;
	char	*s2;
	size_t	i;

	num_frac = modfl(num, &num_int);
	s1 = get_int_str(num_int, &f->point);
	s2 = get_frac_str(num_frac);
	f->size = f->point + frac_default_size;
	i = -1;
	while (++i < f->point)
		f->num[i] = s1[i];
	i = -1;
	while (++i < frac_default_size)
		f->num[f->point + i] = s2[i];
	f->num[f->point + i] = '\0';
}
