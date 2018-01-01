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

void	dec_sum(char *to, char *s)
{
	//printf("Suming\n%s\n%s\n", to, s);
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
	//printf("%s\n", to);
}

void	type_fbf(va_list *ap, t_params *p)
{
	double	num;
	char	*str;
	size_t	size;

	num = va_arg(*ap, double);
	printf("num1 = %.*lf\n", p->precision, num);
	p->precision = p->precision < 0 ? 6 : p->precision;
	size = p->precision > 200 ? p->precision + 1 : 200;
	str = ft_strnew(size + 1);
	for (size_t i = 0; i < size; i++)
		str[i] = '0';
	for (int i = 0; i < p->precision; i++)
	{
		num *= 2.0;
		if (num >= 1.0)
		{
			num -= 1.0;
			dec_sum(str, g_decs[i]);
		}
	}
	printf("num2 = 0.%.*s\n", p->precision, str);
}
