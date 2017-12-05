/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_intnum.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:35:31 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/03 18:35:31 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdint.h>

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
		return (0);
		num = (int)num;
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
		num = (unsigned short)num;
	else if (at->length == LL)
		num = (unsigned long long)num;
	else if (at->length == L)
		num = (unsigned long)num;
	else if (at->length == J)
		num = (uintmax_t)num;
	else if (at->length == Z)
		num = (size_t)num;
	else
	{
		return (0);
		num = (unsigned int)num;
	}
	*n = num;
	return (1);
}
