/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_recogn.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:31:29 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/03 15:31:29 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
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

char		*get_flags(char *str, int *p)
{
	char	*ans;
	char	c;
	int		i;

	i = 0;
	while (is_flag(str[i]))
		i++;
	*p = *p + i;
	ans = ft_strnew(i);
	i = 0;
	while ((c = is_flag(str[i])))
		ans[i++] = c;
	ans = ft_rmdupsymb(ans);
	return (ans);
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

char		*get_length(char *str)
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
	return (ft_strnew(0));
}
