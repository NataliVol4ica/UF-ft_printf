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

static void	react_on_flags(char *flags, char sys)
{
	if ((ft_memchr(flags, '#', ft_strlen(flags))))
	{
		ft_putchar('0');
		if (sys != 'o' && sys != 'O')
			ft_putchar(sys);
	}
}

int			print_oct_hex(va_list *ap, t_atributes *at, char sys)
{
	char		*str;
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	uconvert_numeric(&num, at);
	if (sys == 'o' || sys == 'O')
		str = ft_itoa_base_uns(num, 8);
	else
		str = ft_itoa_base_uns(num, 16);
	if (sys == 'X')
		ft_strupper(str);
	if (num)
		react_on_flags(at->flags, sys);
	ft_putstr(str);
	return (ft_strlen(str));
}
