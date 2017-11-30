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

#include "libft.h"
#include <stdarg.h>
#include "libft.h"
#include <stdint.h>
static int	print_signed_num_other_len(va_list *ap, char *len)
{
	(void)ap;
	(void)len;
	return (0);
}

int			print_signed_num(va_list *ap, char *len)
{
	intmax_t	num;

	num = va_arg(*ap, intmax_t);
	if (!*len)
		num = (int)num;
	else if (len[0] == 'h')
		if (len[1] == 'h')
			num = (char)num;
		else
			num = (short)num;
	else if (len[0] == 'l')
		if (len[1] == 'l')
			num = (long long)num;
		else
			num = (long)num;
	else if (len[0] == 'j')
		num = (intmax_t)num;
	else if (len[0] == 'z')
		num = (size_t)num;
	else
		return (print_signed_num_other_len(ap, len));
	ft_putnbr(num);
	return (ft_count_digits(num, 10) + num < 0 ? 1 : 0);
}

static int	print_unsigned_num_other_len(va_list *ap, char *len)
{
	(void)ap;
	(void)len;
	return (0);
}

int			print_unsigned_num(va_list *ap, char *len)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	if (!*len)
		num = (unsigned int)num;
	else if (len[0] == 'h')
		if (len[1] == 'h')
			num = (unsigned char)num;
		else
			num = (unsigned short)num;
	else if (len[0] == 'l')
		if (len[1] == 'l')
			num = (unsigned long long)num;
		else
			num = (unsigned long)num;
	else if (len[0] == 'j')
		num = (uintmax_t)num;
	else if (len[0] == 'z')
		num = (size_t)num;
	else
		return (print_unsigned_num_other_len(ap, len));
	ft_putnbr_uns(num);
	return (ft_count_digits_uns(num, 10));
}
