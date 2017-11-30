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

int		print_oct_hex(va_list *ap, t_atributes *at, char sys)
{
	char		*str;
	intmax_t	num;

	num = va_arg(*ap, intmax_t);
	(void)at;
	if (sys == 'o' || sys == 'O')
		str = ft_itoa_base_uns(num, 8);
	else
		str = ft_itoa_base_uns(num, 16);
	if (sys == 'X')
		ft_strupper(str);
	ft_putstr(str);
	return (ft_strlen(str));
}
