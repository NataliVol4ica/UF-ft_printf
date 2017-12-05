/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:20 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:24:21 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdint.h>

void	final_putstr(t_params *p)
{
	write(1, p->output->str, p->output->len);
}

void	print_width(char c, size_t num)
{
	while (num-- > 0)
		write(1, &c, 1);
}

void	printf_putchar(char c, t_params *p)
{
	p->output->str[p->output->len++] = c;
	p->output->str[p->output->len] = '\0';
}

void	printf_putnbr(intmax_t n, t_params *p)
{
	uintmax_t	num;
	char		*from;

	if (n == 0)
	{
		printf_putchar('0', p);
		return ;
	}
	if (n < 0)
		p->output->str[p->output->len++] = '-';
	num = n < 0 ? -n : n;
	num = n < 0 && (intmax_t)(n - 1) > 0 ? num + 1 : num;
	from = &p->output->str[p->output->len];
	while (num != 0)
	{
		p->output->str[p->output->len++] = num % 10 + '0';
		num /= 10;
	}
	p->output->str[p->output->len] = '\0';
	rev_str(from, &p->output->str[p->output->len - 1]);
}
