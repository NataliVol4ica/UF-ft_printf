/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <stdint.h>

int		print_c(char c)
{
	ft_putchar(c);
	return (1);
}

int		print_str(char *c)
{
	ft_putstr(c);
	return (ft_strlen(c));
}

int		print_signed_num_other_flag(va_list *ap, char *flag)
{
	(void)ap;
	(void)flag;
	return (0);
}

int		print_signed_num(va_list *ap, char *flag)
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

int		print_unsigned_num_other_flag(va_list *ap, char *flag)
{
	(void)ap;
	(void)flag;
	return (0);
}

int		print_unsigned_num(va_list *ap, char *flag)
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

char	*get_flag(char *str)
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

int		ft_printf(char *fmt, ...)
{
	va_list ap;
	int		i;
	int		ret;
	char	*flag;

	va_start(ap, fmt);
	i = -1;
	ret = 0;
	if (!fmt)
		return (ret);
	while (fmt[++i])
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			flag = get_flag(&fmt[i]);
			i += ft_strlen(flag);
			if (fmt[i] == '%')
				ret += print_c('%');
			else if (fmt[i] == 's')
				ret += print_str(va_arg(ap, char *));
			else if (fmt[i] == 'd' || fmt[i] == 'i')
				ret += print_signed_num(&ap, flag);
			else if (fmt[i] == 'D' || fmt[i] == 'u')
				ret += print_unsigned_num(&ap, flag);
			else if (fmt[i] == 'c')
				ret += print_c((char)va_arg(ap, int));
			else if (fmt[i] == 'C')
				ret += print_c((unsigned char)va_arg(ap, int));			
			else if (fmt[i] == 'o' || fmt[i] == 'O')
				ret += print_str(ft_itoa_base_uns(va_arg(ap, unsigned int), 8));
			else if (fmt[i] == 'x')
				ret += print_str(ft_itoa_base_uns(va_arg(ap, unsigned int), 16));
			else if (fmt[i] == 'X')
				ret += print_str(ft_strupper(ft_itoa_base_uns(va_arg(ap, unsigned int), 16)));
			if (flag)
				ft_strdel(&flag);
		}
		else
			ret += print_c(fmt[i]);
	va_end(ap);
	return (ret);
}
