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
#include <stdlib.h>

void	final_putstr(char *str, size_t len)
{
	write(1, str, len);
}

void	print_width(char c, size_t num)
{
	char	*str;
	size_t	i;

	if (num == 0)
		return ;
	str = (char*)malloc(sizeof(char) * num);
	i = num;
	while (i-- > 0)
		str[i] = c;
	write(1, str, num);
	free(str);
}

void	printf_putchar(char c, t_params *p)
{
	p->output->str[p->output->len++] = c;
}

void	printf_putnbr_uns(uintmax_t n, t_params *p)
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
		p->output->str[p->output->len++] = n % 10 + '0';
		n /= 10;
	}
	rev_str(p->output->str, p->output->len - 1);
}
