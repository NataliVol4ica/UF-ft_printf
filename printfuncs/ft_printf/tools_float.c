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
#include <float.h>
#include <math.h>

#define frac_default_size 200

void	dec_sum(char *to, char *s) //200
{
	for (int i = 0; i < 201; i++)
	{
		to[i] -= '0';
		to[i] += s[i];
	}
	for (int i = 200; i > 0; i--)
	{
		to[i] -= '0';
		to[i - 1] += to[i] / 10;
		to[i] = to[i] % 10;
		to[i] += '0'; 
	}
}

void	round_float(char *str, t_params *p, _Bool is_pos)
{
	int		i;

	i = p->precision - 1;
	if ((FLT_ROUNDS == 2 && is_pos) || (FLT_ROUNDS == 3 && !is_pos) || FLT_ROUNDS == 1)
		while (i >= 0)
		{
			str[i] += ((str[i + 1] - '0') / 5);
			i--;
		}
}

char	*get_frac_str(double num_frac, t_params *p, _Bool is_pos)
{
	static t_str	*str = NULL;
	int				i;

	str = str ? str : init_t_str(frac_default_size);
	while (p->precision > str->size)
		realloc_t_str(str);
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
	if ((int)p->precision < str->size)
		round_float(str->str, p, is_pos);
	str->str[p->precision] = '\0';
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

char	*get_int_str(double num_int)
{
	static char	*str = NULL;
	int			i;

	if (!str)
		str = (char*)malloc(sizeof(char) * 311);
	i = -1;
	while (++i < 310)
		str[i] = '0';
	str[310] = '\0';
	i = 0;
	while (num_int > 1.0)
	{
		if ((int)fmod(num_int, 2.0) == 1)
			int_sum(str, g_twos[i]);
		num_int /= 2;
		i++;
	}
	i = 0;
	while (str[i] == '0' && str[i + 1])
		i++;
	return (&str[i]);
}

void	set_float(t_float *f, double num, t_params *p)
{
	double	num_int;
	double 	num_frac;
	char	*s1;
	char	*s2;

	f->is_pos = num < 0.0 ? 0 : 1;
	num = num < 0.0 ? -num : num;
	num_frac = modf(num, &num_int);
	s1 = get_int_str(num_int);
	s2 = get_frac_str(num_frac, p, f->is_pos);
}
