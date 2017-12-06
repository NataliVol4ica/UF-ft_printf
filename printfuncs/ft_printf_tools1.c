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

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdint.h>

uintmax_t	printf_atoi(char *str, int *p)
{
	uintmax_t	ans;
	int			i;

	i = 0;
	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	*p = *p + i;
	return (ans);
}

void		rev_str(char *from, char *until)
{
	char		c;

	while (from < until)
	{
		c = *from;
		*from = *until;
		*until = c;
		from++;
		until--;
	}
}
