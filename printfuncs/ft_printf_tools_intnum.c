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

/*static int	print_signed_num_other_len(va_list *ap, t_params *at)
{
	(void)ap;
	(void)at;
	return (0);
}*/

size_t	react_on_flags_di(intmax_t num, char *flags)
{
	if ((ft_memchr(flags, '+', ft_strlen(flags))) && num > 0)
		return (ft_putchar('+'));
	else if ((ft_memchr(flags, ' ', ft_strlen(flags))) && num > 0)
		return (ft_putchar(' '));
	return (0);
}

/*static int	print_unsigned_num_other_len(va_list *ap, t_params *at)
{
	(void)ap;
	(void)at;
	return (0);
}*/
