/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_octhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_consts.h"
#include "libft.h"
#include <stdlib.h>
#include <float.h>

void	dec_sum(char *to, char *s)
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

void	type_fbf(va_list *ap, t_params *p)
{
	double	num;
	char	*str;
	size_t	size;
	_Bool	is_neg;

	num = va_arg(*ap, double);
	is_neg = num < 0.0 ? 1 : 0;
	num = num < 0.0 ? -num : num;
	p->precision = p->precision < 0 ? 6 : p->precision;
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
	printf("0.%.*s\n", p->precision, str);
}
