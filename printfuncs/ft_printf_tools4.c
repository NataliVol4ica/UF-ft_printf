/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:51:15 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 20:51:15 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_atributes	*read_atributes(char *fmt, int *pos)
{
	t_atributes *at;
	int			i;

	if ((at = (t_atributes*)malloc(sizeof(t_atributes))))
	{
		i = *pos;
		at->flags = get_flags(&fmt[i]);
		i += ft_strlen(at->flags);
		at->flags = ft_rmdupsymb(at->flags);
		at->length = get_length(&fmt[i]);
		i += ft_strlen(at->length);
		*pos = i;
	}
	return (at);
}

void		del_atributes(t_atributes **at)
{
	if (at)
	{
		if (*at)
		{
			ft_strdel(&((*at)->length));
			ft_strdel(&((*at)->flags));
			free(*at);
		}
		*at = NULL;
	}
}
