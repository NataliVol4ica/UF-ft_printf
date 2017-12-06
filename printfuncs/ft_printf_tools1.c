/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:20 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:24:21 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdint.h>

uintmax_t	printf_atoi(char *str, int *p)
{
	uintmax_t	ans;
	int			i;

	i = 0;
	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	*p = *p + i;
	return (ans);
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
	p->width -= p->width <= p->prefix->len + p->output->len ? p->width :
				p->prefix->len + p->output->len;
	if (p->flags->minus)
	{
		if (p->prefix->len > 0)
			final_putstr(p->prefix);
		final_putstr(p->output);
		print_width(' ', p->width);
		return ;
	}
	if (p->flags->zero && !p->precision)
	{
		if (p->prefix->len > 0)
			final_putstr(p->prefix);
		print_width('0', p->width);
	}
	else
	{
		print_width(' ', p->width);
		if (p->prefix->len > 0)
			final_putstr(p->prefix);
	}
	final_putstr(p->output);
}
