/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:12:26 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/06 15:12:26 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdint.h>

void	printf_convert_oboxbx(uintmax_t n, size_t base, t_params *p, char c)
{
	char		*from;

	if (n == 0)
	{
		printf_putchar('0', p);
		return ;
	}
	from = &p->output->str[p->output->len];
	while (n != 0)
	{
		p->output->str[p->output->len] = n % base;
		p->output->str[p->output->len] +=
			p->output->str[p->output->len] > 9 ? -10 + c : '0';
		n /= base;
		p->output->len++;
	}
	p->output->str[p->output->len] = '\0';
	rev_str(p->output->str, p->output->len - 1);
}

int			convert_numeric_signed(intmax_t *n, t_params *at)
{
	intmax_t	num;

	num = *n;
	if (at->length == EMPTY)
		num = (int)num;
	else if (at->length == HH)
		num = (char)num;
	else if (at->length == H)
		num = (short)num;
	else if (at->length == LL)
		num = (long long)num;
	else if (at->length == L)
		num = (long)num;
	else if (at->length == J)
		num = (intmax_t)num;
	else if (at->length == Z)
		num = (size_t)num;
	else
	{		
		num = (int)num;
		return (0);
	}
	*n = num;
	return (1);
}

int			convert_numeric_unsigned(uintmax_t *n, t_params *at)
{
	uintmax_t	num;

	num = *n;
	if (at->length == EMPTY)
		num = (unsigned int)num;
	else if (at->length == HH)
		num = (unsigned char)num;
	else if (at->length == H)
		num = (unsigned short int)num;
	else if (at->length == LL)
		num = (unsigned long long int)num;
	else if (at->length == L)
		num = (unsigned long int)num;
	else if (at->length == J)
		num = (uintmax_t)num;
	else if (at->length == Z)
		num = (size_t)num;
	else
	{
		num = (unsigned int)num;
		return (0);
	}
	*n = num;
	return (1);
}
