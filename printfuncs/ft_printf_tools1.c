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

static int	print_signed_num_other_len(va_list *ap, t_atributes *at)
{
	(void)ap;
	(void)at;
	return (0);
}

static void	react_on_flags(intmax_t num, char *flags)
{
	if ((ft_memchr(flags, '+', ft_strlen(flags))) && num > 0)
		ft_putchar('+');
	else if ((ft_memchr(flags, ' ', ft_strlen(flags))) && num > 0)
		ft_putchar(' ');
}

int			print_signed_num(va_list *ap, t_atributes *at)
{
	intmax_t	num;

	num = va_arg(*ap, intmax_t);
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
		return (print_signed_num_other_len(ap, at));
	react_on_flags(num, at->flags);
	ft_putnbr(num);
	return (ft_count_digits(num, 10) + num < 0 ? 1 : 0);
}

static int	print_unsigned_num_other_len(va_list *ap, t_atributes *at)
{
	(void)ap;
	(void)at;
	return (0);
}

int			print_unsigned_num(va_list *ap, t_atributes *at)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
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
		return (print_unsigned_num_other_len(ap, at));
	ft_putnbr_uns(num);
	return (ft_count_digits_uns(num, 10));
}
