/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:31:29 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/03 15:31:29 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

/*
** % [param] [flags] [width]  [precision] [length]    [type]
** % [n$]    [ #0+-] [n || *] [.n||.*]    [hlhhlljzLt][sSpdDioOuUxXcCeEfFgGaAn]
*/

size_t		get_n(char *str, int *p)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '$')
	{
		*p = *p + 1;
		return (printf_atoi(str, p));
	}
	return (0);
}

void		get_flags(char *str, int *p, t_flags *f)
{
	int		i;
	char	cont;

	i = 0;
	cont = 1;
	while (cont)
	{
		if (str[i] == '+')
			f->plus = 1;
		else if (str[i] == '-')
			f->minus = 1;
		else if (str[i] == '0')
			f->zero = 1;
		else if (str[i] == '#')
			f->hash = 1;
		else if (str[i] == ' ')
			f->space = 1;
		else if (str[i] == '\'')
			f->apostrophe = 1;
		else
		{
			i--;
			cont = 0;
		}
		i++;
	}
	*p = *p + i;
}

intmax_t	get_width(char *str, int *p, va_list *ap)
{
	if (ft_isdigit(str[0]))
		return (printf_atoi(str, p));
	if (str[0] == '*')
	{
		*p = *p + 1;
		return (va_arg(*ap, size_t));
	}
	return (0);
}

intmax_t	get_precision(char *str, int *p, va_list *ap)
{
	if (str[0] != '.')
		return (-1);
	*p = *p + 1;
	if (str[1] == '*')
	{
		*p = *p + 1;
		return (va_arg(*ap, intmax_t));
	}
	return (printf_atoi(&str[1], p));
}

t_length	get_length(char *str, int *i)
{
	t_length l;

	l = EMPTY;
	while (1)
	{
		*i = *i + 1;
		if (*str == 'h')
			if (*(str + 1) == 'h')
			{
				str++;
				*i = *i + 1;
				l = l < HH ? HH : l;
			}
			else
				l = l < H ? H : l;
		else if (*str == 'l')
			if (*(str + 1) == 'l')
			{
				*i = *i + 1;
				str++;
				l = l < LL ? LL : l;
			}
			else
				l = l < L ? L : l;
		else if (*str == 'j')
			l = l < J ? J : l;
		else if (*str == 'z')
			l = l < Z ? Z : l;
		else if (*str == 'L')
			l = l < BL ? BL : l;
		else
		{
			*i = *i - 1;
			break;
		}
		str++;
	}
	return (l);
}
