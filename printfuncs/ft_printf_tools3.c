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
