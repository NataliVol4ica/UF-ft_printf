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
#include <stdarg.h>
#include <stdint.h>

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
	p->width -= p->width <= p->prefix->len + p->output->len ? p->width :
				p->prefix->len + p->output->len;
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
