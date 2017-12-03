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
#include <stdarg.h>
#include <stdint.h>

static int	print_signed_num_other_len(va_list *ap, t_params *at)
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

int			print_signed_num(va_list *ap, t_params *at)
{
	intmax_t	num;

	num = va_arg(*ap, intmax_t);
	if (!(convert_numeric(&num, at)))
		return (print_signed_num_other_len(ap, at));
	react_on_flags(num, at->flags);
	ft_putnbr(num);
	return (ft_count_digits(num, 10) + num < 0 ? 1 : 0);
}

static int	print_unsigned_num_other_len(va_list *ap, t_params *at)
{
	(void)ap;
	(void)at;
	return (0);
}

int			print_unsigned_num(va_list *ap, t_params *at)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	if (!(uconvert_numeric(&num, at)))
		return (print_unsigned_num_other_len(ap, at));
	ft_putnbr_uns(num);
	return (ft_count_digits_uns(num, 10));
}
