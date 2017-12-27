/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	type_percent(va_list *ap, t_params *p)
{
	int		i;
	char	filler;

	(void)ap;
	p->width--;
	i = -1;
	filler = p->flags->zero ? '0' : ' ';
	if (p->flags->minus)
	{
		print_symbol(p, '%');
		while (++i < p->width)
			print_symbol(p, ' ');
		return ;
	}
	while (++i < p->width)
		print_symbol(p, filler);
	print_symbol(p, '%');
}

void	type_c(va_list *ap, t_params *p)
{
	int		i;
	char	filler;
	char	c;

	if (p->length == L)
	{
		type_bc(ap, p);
		return ;
	}
	c = (char)va_arg(*ap, int);
	p->width--;
	i = -1;
	filler = p->flags->zero ? '0' : ' ';
	if (p->flags->minus)
	{
		print_symbol(p, c);
		while (++i < p->width)
			print_symbol(p, ' ');
		return ;
	}
	while (++i < p->width)
		print_symbol(p, filler);
	print_symbol(p, c);
}

void	type_bc(va_list *ap, t_params *p)
{
	t_output	o;
	size_t		sum;
	char		filler;

	o.str = &p->toprint->str[p->toprint->len];
	o.len = p->toprint->len;
	p->precision = -1;
	printf_putwchar((wchar_t)va_arg(*ap, wchar_t), p);
	filler = p->flags->zero ? '0' : ' ';
	if (p->flags->minus)
	{
		sum = o.len + p->width;
		while (p->toprint->len < sum)
			print_symbol(p, ' ');
	}
	else
	{
		rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
		sum = o.len + p->width;
		while (p->toprint->len < sum)
			print_symbol(p, filler);
		rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
	}
}

void	type_s(va_list *ap, t_params *p)
{
	char		*str;
	t_output	o;
	size_t		sum;
	char		filler;

	if (p->length == L)
	{
		type_bs(ap, p);
		return ;
	}
	o.str = &p->toprint->str[p->toprint->len];
	o.len = p->toprint->len;
	str = va_arg(*ap, char*);
	print_str(p, str);
	filler = p->flags->zero ? '0' : ' ';
	if (p->flags->minus)
	{
		sum = o.len + p->width;
		while (p->toprint->len < sum)
			print_symbol(p, ' ');
	}
	else
	{
		rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
		sum = o.len + p->width;
		while (p->toprint->len < sum)
			print_symbol(p, filler);
		rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
	}
}

void	type_bs(va_list *ap, t_params *p)
{
	wchar_t		*str;
	t_output	o;
	size_t		sum;
	char		filler;

	o.str = &p->toprint->str[p->toprint->len];
	o.len = p->toprint->len;
	str = va_arg(*ap, wchar_t*);
	sum = -1;
	if (!str)
		print_str(p, NULL);
	else
	{
		p->precision += p->precision >= 0 ? o.len : 0;
		while (str[++sum])
			if ((printf_putwchar(str[sum], p)))
				break ;
	}
	filler = p->flags->zero ? '0' : ' ';
	if (p->flags->minus)
	{
		sum = o.len + p->width;
		while (p->toprint->len < sum)
			print_symbol(p, ' ');
		return ;
	}
	rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
	sum = o.len + p->width;
	while (p->toprint->len < sum)
		print_symbol(p, filler);
	rev_str(o.str, &p->toprint->str[p->toprint->len - 1]);
}
