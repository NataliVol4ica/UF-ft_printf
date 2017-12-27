/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_string_forming.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:12:26 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/06 15:12:26 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

int		printf_putwchar(wchar_t c, t_params *p)
{
	size_t	b;

	if (!check_bits(&b, c, p))
		return (1);
	if (b < 8 || MB_CUR_MAX == 1)
		print_symbol(p, c);
	else if ((b < 12 && MB_CUR_MAX > 2) || MB_CUR_MAX == 2)
	{
		print_symbol(p, (c >> 6) + 0xC0);
		print_symbol(p, (c & 0x3F) + 0x80);
	}
	else if ((b < 17 && MB_CUR_MAX > 3) || MB_CUR_MAX == 3)
	{
		print_symbol(p, (c >> 12) + 0xE0);
		print_symbol(p, ((c >> 6) & 0x3F) + 0x80);
		print_symbol(p, (c & 0x3F) + 0x80);
	}
	else if ((b < 22 && MB_CUR_MAX > 4) || MB_CUR_MAX == 4)
	{
		print_symbol(p, (c >> 18) + 0xF0);
		print_symbol(p, ((c >> 12) & 0x3F) + 0x80);
		print_symbol(p, ((c >> 6) & 0x3F) + 0x80);
		print_symbol(p, (c & 0x3F) + 0x80);
	}
	return (0);
}

void	print_number(uintmax_t n, size_t base, t_params *p, void (*preffunc)(t_params*))
{
	t_output	o;
	size_t		sum;

	o.str = &p->toprint->str[p->toprint->len];
	o.len = p->toprint->len;
	if (n == 0 && p->precision != 0)
		print_symbol(p, '0');
	else
		while (n != 0)
		{
			print_symbol(p, p->alphabet[n % base]);
			n /= base;
		}
	sum = o.len + (size_t)p->precision;
	if (p->precision >= 0)
		while (p->toprint->len < sum)
			print_symbol(p, '0');
	if (p->flags->minus)
	{
		preffunc(p);
		rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
		sum = o.len + (size_t)p->width;
		while (p->toprint->len < sum)
			print_symbol(p, ' ');
	}
	else if (p->flags->zero)
	{
		if (o.len + (size_t)p->width > p->pref_len)
			sum = o.len + (size_t)p->width - p->pref_len;
		else
			sum = 0;
		while (p->toprint->len < sum)
			print_symbol(p, '0');
		preffunc(p);
		rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
	}
	else
	{
		preffunc(p);
		sum = o.len + (size_t)p->width;
		while (p->toprint->len < sum)
			print_symbol(p, ' ');
		rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
	}
}
