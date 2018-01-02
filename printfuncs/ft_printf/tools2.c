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
#include <stdlib.h>
#include <float.h>
#include <math.h>

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

void	zero_t_float(t_float *f)
{
	(void)f;
}

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

void	round_float(char *str, t_params *p, _Bool is_neg)
{
	int		i;

	i = p->precision - 1;
	if ((FLT_ROUNDS == 2 && !is_neg) || (FLT_ROUNDS == 3 && is_neg) || FLT_ROUNDS == 1)
		while (i >= 0)
			str[i] += ((str[i + 1] - '0') / 5);
}

void	lalala(void)
{

	/*
	size = p->precision > 200 ? p->precision + 1 : 200;
	str = ft_strnew(size + 1);
	for (size_t i = 0; i < size; i++)
		str[i] = '0';
	for (size_t i = 0; i < size; i++)
	{
		num *= 2.0;
		if (num >= 1.0)
		{
			num -= 1.0;
			dec_sum(str, g_decs[i]);
		}
	}
	if ((size_t)p->precision < size)
		round_float(str, p, is_neg);
	if (is_neg)
		printf("-");
	printf("0.%.*s\n", p->precision, str);*/
}
void	int_sum(char *str, char *s)
{
	//printf("Summing\n");
	//printf("%s\n%s\n", str, s);
	for (int i = 309; i > 0; i--)
	{
		str[i] += s[i];
		str[i] -= '0';
		str[i] -= '0';
		str[i - 1] += str[i] / 10;
		str[i] = str[i] % 10;
		str[i] += '0';

	}
}

void	set_float(t_float *f, double num)
{
	double	num_int;
	double 	num_frac;
	char	*str;

	f->is_pos = num < 0.0 ? 0 : 1;
	num = num < 0.0 ? -num : num;
	num_frac = modf(num, &num_int);
	str = (char*)malloc(sizeof(char) * 311);
	for (int i = 0; i < 310; i++)
		str[i] = '0';
	str[310] = '\0';
	int i = 0;
	while (num > 1.0)
	{
		if ((int)fmod(num, 2.0) == 1)
		{
			//printf("num == %f i == %d\n", num, i);
			int_sum(str, g_twos[i]);
			//printf("\n%s\n", str);
		}
		num /= 2;
		//printf("%d = %f\n", i, num);
		i++;
	}
	i = 0;
	while (str[i] == '0')
		i++;
	str += i;
	printf("%s\n", str);
}
