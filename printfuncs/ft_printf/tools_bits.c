/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:20 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:24:21 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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

int			check_bits(size_t *b, wchar_t c, t_params *p)
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
	if (p->precision >= 0 && f + p->toprint->len > (size_t)p->precision)
		return (0);
	return (1);
}
