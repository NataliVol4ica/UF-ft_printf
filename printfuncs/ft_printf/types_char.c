/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"
#include <stdlib.h>

size_t		type_percent(va_list *ap, t_params *p)
{
	(void)ap;
	printf_putchar('%', p);
	check_width(p);
	return (p->output->len + p->width);
}

size_t		type_c(va_list *ap, t_params *p)
{
	printf_putchar((char)va_arg(*ap, int), p);
	check_width(p);
	return (p->output->len + p->width);
}

#if MOULINETTE == 1
size_t		type_bc(va_list *ap, t_params *p)
{
	printf_putchar((char)va_arg(*ap, int), p);
	check_width(p);
	return (p->output->len + p->width);
}
#else
size_t		type_bc(va_list *ap, t_params *p)
{
	printf_putwchar((wchar_t)va_arg(*ap, wchar_t), p);
	check_width(p);
	return (p->output->len + p->width);
}
#endif

size_t		type_s(va_list *ap, t_params *p)
{
	char	*temp;

	temp = p->output->str;
	p->output->str = va_arg(*ap, char*);
	if (p->output->str == NULL)
	{
		p->output->str = "(null)";
		p->output->len = 6;
	}
	else
		p->output->len = ft_strlen(p->output->str);
	if (p->precision > -1 && p->output->len > (uintmax_t)p->precision)
		p->output->len = (uintmax_t)p->precision;
	check_width(p);
	p->output->str = temp;
	return (p->output->len + p->width);
}

size_t		type_bs(va_list *ap, t_params *p)
{
	char	*temp;
	wchar_t	*str;
	size_t	i;

	str = va_arg(*ap, wchar_t*);
	if (str == NULL)
	{
		p->output->str = "(null)";
		p->output->len = 6;
		check_width(p);
	}
	else
	{
		temp = p->output->str;
		p->output->str = ft_strnew(ft_wstrlen(str) * 4);
		i = -1;
		while (str[++i])
			printf_putwchar(str[i], p);
		check_width(p);
		free(p->output->str);
		p->output->str = temp;
	}
	return (p->output->len + p->width);
}
