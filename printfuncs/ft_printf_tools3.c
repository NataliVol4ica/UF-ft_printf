/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:32:15 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 20:32:15 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdint.h>

static char	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (c);
	return (0);
}

char		*get_flags(char *str)
{
	char	*ans;
	char	c;
	int		i;

	i = 0;
	while (is_flag(str[i]))
		i++;
	ans = ft_strnew(i);
	i = 0;
	while ((c = is_flag(str[i])))
		ans[i++] = c;
	return (ans);
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

int		convert_numeric(intmax_t *n, t_atributes *at)
{
	intmax_t	num;

	num = *n;
	if (!*(at->length))
		num = (int)num;
	else if (at->length[0] == 'h')
		if (at->length[1] == 'h')
			num = (char)num;
		else
			num = (short)num;
	else if (at->length[0] == 'l')
		if (at->length[1] == 'l')
			num = (long long)num;
		else
			num = (long)num;
	else if (at->length[0] == 'j')
		num = (intmax_t)num;
	else if (at->length[0] == 'z')
		num = (size_t)num;
	else
		return (0);
	*n = num;
	return (1);
}

int		uconvert_numeric(uintmax_t *n, t_atributes *at)
{
	uintmax_t	num;

	num = *n;
	if (!*(at->length))
		num = (unsigned int)num;
	else if (at->length[0] == 'h')
		if (at->length[1] == 'h')
			num = (unsigned char)num;
		else
			num = (unsigned short)num;
	else if (at->length[0] == 'l')
		if (at->length[1] == 'l')
			num = (unsigned long long)num;
		else
			num = (unsigned long)num;
	else if (at->length[0] == 'j')
		num = (uintmax_t)num;
	else if (at->length[0] == 'z')
		num = (size_t)num;
	else
		return (0);
	*n = num;
	return (1);
}
