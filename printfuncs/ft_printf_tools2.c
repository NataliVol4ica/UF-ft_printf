/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:47:29 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:47:29 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdint.h>

size_t	react_on_flags_di(intmax_t num, t_flags *flags)
{
	if (flags->plus && num > 0)
		return (ft_putchar('+'));
	else if (flags->space && num > 0)
		return (ft_putchar(' '));
	return (0);
}

size_t	react_on_flags_obo(t_flags *flags)
{
	if (flags->hash)
		return (ft_putchar('0'));
	return (0);
}

size_t	react_on_flags_x(t_flags *flags)
{
	if (flags->hash)
		return (ft_putstr("0x"));
	return (0);
}

size_t	react_on_flags_bx(t_flags *flags)
{
	if (flags->hash)
		return (ft_putstr("0X"));
	return (0);
}
