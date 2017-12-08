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
#include <stdint.h>

void	printf_putchar(char c, t_params *p)
{
	p->output->str[p->output->len++] = c;
}

void	printf_putnbr_uns(uintmax_t n, t_params *p)
{
	if (n == 0 && p->precision != 0)
		p->output->str[p->output->len++] = '0';
	else
		while (n != 0)
		{
			p->output->str[p->output->len++] = n % 10 + '0';
			n /= 10;
		}
	if (p->precision >= 0)
		while (p->output->len < (uintmax_t)p->precision)
			p->output->str[p->output->len++] = '0';
	rev_str(p->output->str, p->output->len - 1);
}

void	printf_convert_base(uintmax_t n, size_t base, t_params *p, char c)
{
	if (n == 0)
	{
		if (p->precision != 0)
			printf_putchar('0', p);
		else if (p->precision == 0 && c == '0' && p->flags->hash)
			printf_putchar('0', p);
	}
	while (n != 0)
	{
		p->output->str[p->output->len] = n % base;
		p->output->str[p->output->len] +=
			p->output->str[p->output->len] > 9 ? -10 + c : '0';
		n /= base;
		p->output->len++;
	}
	if (p->precision > 0)
		while (p->output->len < (size_t)p->precision)
			p->output->str[p->output->len++] = '0';
	rev_str(p->output->str, p->output->len - 1);
}
