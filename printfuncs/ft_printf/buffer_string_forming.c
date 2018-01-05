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
#include <locale.h>

int			printf_putwchar(wchar_t c, t_params *p)
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

static void	pn_flags_minus(t_params *p, void (*preffunc)(t_params*))
{
	size_t	sum;

	preffunc(p);
	rev_str(&p->toprint->str[p->savelen],
		&p->toprint->str[p->toprint->len - 1]);
	sum = p->savelen + (size_t)p->width;
	while (p->toprint->len < sum)
		print_symbol(p, ' ');
}

static void	pn_flags_zero(t_params *p, void (*preffunc)(t_params*))
{
	size_t	sum;

	sum = p->savelen + (size_t)p->width > p->pref_len ?
			p->savelen + (size_t)p->width - p->pref_len : 0;
	while (p->toprint->len < sum)
		print_symbol(p, '0');
	preffunc(p);
	rev_str(&p->toprint->str[p->savelen],
		&p->toprint->str[p->toprint->len - 1]);
}

static void	pn_flags_none(t_params *p, void (*preffunc)(t_params*))
{
	size_t	sum;

	preffunc(p);
	sum = p->savelen + (size_t)p->width;
	while (p->toprint->len < sum)
		print_symbol(p, ' ');
	rev_str(&p->toprint->str[p->savelen],
		&p->toprint->str[p->toprint->len - 1]);
}

void		print_number(uintmax_t n, size_t base, t_params *p,
						void (*preffunc)(t_params*))
{
	size_t			sum;
	size_t			i;
	struct lconv	*loc;

	p->savelen = p->toprint->len;
	i = 0;
	loc = localeconv();
	if (n == 0 && p->precision != 0)
		print_symbol(p, '0');
	else
		while (n != 0)
		{
			print_symbol(p, p->alphabet[n % base]);
			n /= base;
			if (p->flags->apostrophe && ++i % 3 == 0 && n != 0)
				print_str(p, loc->thousands_sep, 1);
		}
	sum = p->savelen + (size_t)p->precision;
	if (p->precision >= 0)
		while (p->toprint->len < sum)
			print_symbol(p, '0');
	if (p->flags->minus)
		pn_flags_minus(p, preffunc);
	p->flags->zero ? pn_flags_zero(p, preffunc) : pn_flags_none(p, preffunc);
}
