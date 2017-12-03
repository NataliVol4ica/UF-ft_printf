/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:32:15 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 20:32:15 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdint.h>

int			convert_numeric(intmax_t *n, t_params *at)
{
	intmax_t	num;

	num = *n;
	if (!*(at->length))
		num = (int)num;
	else if (at->length[0] == 'h')
		if (at->length[1] == 'h')
			num = (char)num;
		else
			num = (short)num;
	else if (at->length[0] == 'l')
		if (at->length[1] == 'l')
			num = (long long)num;
		else
			num = (long)num;
	else if (at->length[0] == 'j')
		num = (intmax_t)num;
	else if (at->length[0] == 'z')
		num = (size_t)num;
	else
		return (0);
	*n = num;
	return (1);
}

int			uconvert_numeric(uintmax_t *n, t_params *at)
{
	uintmax_t	num;

	num = *n;
	if (!*(at->length))
		num = (unsigned int)num;
	else if (at->length[0] == 'h')
		if (at->length[1] == 'h')
			num = (unsigned char)num;
		else
			num = (unsigned short)num;
	else if (at->length[0] == 'l')
		if (at->length[1] == 'l')
			num = (unsigned long long)num;
		else
			num = (unsigned long)num;
	else if (at->length[0] == 'j')
		num = (uintmax_t)num;
	else if (at->length[0] == 'z')
		num = (size_t)num;
	else
		return (0);
	*n = num;
	return (1);
}
