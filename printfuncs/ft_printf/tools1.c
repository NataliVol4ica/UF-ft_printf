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
#include "libft.h"
#include <stdlib.h>

void		set_null_string(t_params *p)
{
	p->output->str = "(null)";
	p->output->len = 6;
}

size_t		ft_wstrlen(const wchar_t *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t		count_bits(wchar_t k)
{
	size_t	wn;

	wn = 1;
	while (k >>= 1)
		wn++;
	return (wn);
}

int		check_bits(size_t *b, wchar_t c, t_params *p)
{
	size_t f;

	*b = count_bits(c);
	if (*b < 8)
		f = 1;
	else if (*b < 12)
		f = 2;
	else if (*b < 17)
		f = 3;
	else
		f = 4;
	if (p->precision >= 0 && f + p->output->len > (size_t)p->precision)
		return (0);
	return (1);
}

intmax_t	printf_atoi(char *str, int *p)
{
	uintmax_t	ans;
	int			sign;
	int			i;

	i = 0;
	ans = 0;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	*p = *p + i;
	return (ans * sign);
}

void		rev_str(char *from, size_t n)
{
	char	c;
	char	*until;

	until = &from[n];
	while (from < until)
	{
		c = *from;
		*from = *until;
		*until = c;
		from++;
		until--;
	}
}

void		check_width(t_params *p)
{
	p->width -= p->prefix->len + p->output->len;
	p->width = p->width < 0 ? 0 : p->width;
	if (p->flags->minus)
	{
		final_putstr(p->prefix->str, p->prefix->len);
		final_putstr(p->output->str, p->output->len);
		print_width(' ', p->width);
		return ;
	}
	if (p->flags->zero)
	{
		final_putstr(p->prefix->str, p->prefix->len);
		print_width('0', p->width);
	}
	else
	{
		print_width(' ', p->width);
		final_putstr(p->prefix->str, p->prefix->len);
	}
	final_putstr(p->output->str, p->output->len);

}
