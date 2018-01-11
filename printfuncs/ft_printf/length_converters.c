/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_converters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:12:26 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/06 15:12:26 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stddef.h>

void	convert_di(intmax_t *n, t_params *p)
{
	intmax_t	num;

	num = *n;
	if (p->length == HH)
		num = (signed char)num;
	else if (p->length == H)
		num = (short)num;
	else if (p->length == LL)
		num = (long long)num;
	else if (p->length == L)
		num = (long)num;
	else if (p->length == J)
		num = (intmax_t)num;
	else if (p->length == Z)
		num = (size_t)num;
	else if (p->length == T)
		num = (ptrdiff_t)num;
	else
		num = (int)num;
	*n = num;
}

void	convert_ouxbx_t(uintmax_t *n, t_params *p)
{
	uintmax_t	num;

	num = *n;
	if (p->length != T)
		return ;
	if (sizeof(unsigned char) == sizeof(ptrdiff_t))
		num = (unsigned char)num;
	else if (sizeof(unsigned short) == sizeof(ptrdiff_t))
		num = (unsigned short)num;
	else if (sizeof(unsigned long long) == sizeof(ptrdiff_t))
		num = (unsigned long long)num;
	else if (sizeof(unsigned long int) == sizeof(ptrdiff_t))
		num = (unsigned long int)num;
	else
		num = (unsigned int)num;
	*n = num;
}

void	convert_ouxbx(uintmax_t *n, t_params *p)
{
	uintmax_t	num;

	num = *n;
	if (p->length == HH)
		num = (unsigned char)num;
	else if (p->length == H)
		num = (unsigned short)num;
	else if (p->length == LL)
		num = (unsigned long long)num;
	else if (p->length == L)
		num = (unsigned long int)num;
	else if (p->length == J)
		num = (uintmax_t)num;
	else if (p->length == Z)
		num = (size_t)num;
	else if (p->length == T)
		convert_ouxbx_t(n, p);
	else
		num = (unsigned int)num;
	*n = num;
}
