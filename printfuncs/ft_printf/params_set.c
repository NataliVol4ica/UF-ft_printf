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
#include <stdint.h>
#include <stdio.h>

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
		else
		{
			i--;
			cont = 0;
		}
		i++;
	}
	*p = *p + i;
}

size_t		get_width(char *str, int *p, va_list *ap)
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

size_t		get_precision(char *str, int *p, va_list *ap)
{
	if (str[0] != '.')
		return (0);
	*p = *p + 1;
	if (str[1] == '*')
	{
		*p = *p + 1;
		return (va_arg(*ap, size_t));
	}
	return (printf_atoi(&str[1], p));
}

t_length	get_length(char *str, int *i)
{
	*i = *i + 1;
	if (str[0] == 'h')
		if (str[1] == 'h')
		{
			*i = *i + 1;
			return (HH);
		}
		else
			return (H);
	else if (str[0] == 'l')
		if (str[1] == 'l')
		{
			*i = *i + 1;
			return (LL);
		}
		else
			return (L);
	else if (str[0] == 'j')
		return (J);
	else if (str[0] == 'z')
		return (Z);
	else if (str[0] == 'L')
		return (BL);
	*i = *i - 1;
	return (EMPTY);
}
