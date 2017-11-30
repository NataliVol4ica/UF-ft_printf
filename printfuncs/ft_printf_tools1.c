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

static int	print_signed_num_other_flag(va_list *ap, char *flag)
{
	(void)ap;
	(void)flag;
	return (0);
}

int			print_signed_num(va_list *ap, char *flag)
{
	intmax_t	num;

	num = va_arg(*ap, intmax_t);
	if (!flag)
		num = (int)num;
	else if (flag[0] == 'h')
		if (flag[1] == 'h')
			num = (char)num;
		else
			num = (short)num;
	else if (flag[0] == 'l')
		if (flag[1] == 'l')
			num = (long long)num;
		else
			num = (long)num;
	else if (flag[0] == 'j')
		num = (intmax_t)num;
	else if (flag[0] == 'z')
		num = (size_t)num;
	else
		return (print_signed_num_other_flag(ap, flag));
	ft_putnbr(num);
	return (ft_count_digits(num, 10) + num < 0 ? 1 : 0);
}

static int	print_unsigned_num_other_flag(va_list *ap, char *flag)
{
	(void)ap;
	(void)flag;
	return (0);
}

int			print_unsigned_num(va_list *ap, char *flag)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	if (!flag)
		num = (unsigned int)num;
	else if (flag[0] == 'h')
		if (flag[1] == 'h')
			num = (unsigned char)num;
		else
			num = (unsigned short)num;
	else if (flag[0] == 'l')
		if (flag[1] == 'l')
			num = (unsigned long long)num;
		else
			num = (unsigned long)num;
	else if (flag[0] == 'j')
		num = (uintmax_t)num;
	else if (flag[0] == 'z')
		num = (size_t)num;
	else
		return (print_unsigned_num_other_flag(ap, flag));
	ft_putnbr_uns(num);
	return (ft_count_digits_uns(num, 10));
}

char		*get_flag(char *str)
{
	if (str[0] == 'h')
		if (str[1] == 'h')
			return (ft_strdup("hh"));
		else
			return (ft_strdup("h"));
	else if (str[0] == 'l')
		if (str[1] == 'l')
			return (ft_strdup("ll"));
		else
			return (ft_strdup("l"));
	else if (str[0] == 'j')
		return (ft_strdup("j"));
	else if (str[0] == 'z')
		return (ft_strdup("z"));
	else if (str[0] == 'L')
		return (ft_strdup("L"));
	return (NULL);
}
