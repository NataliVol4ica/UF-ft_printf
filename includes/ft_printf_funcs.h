/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:48:51 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/05 15:48:52 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FUNCS_H
# define FT_PRINT_FUNCS_H

# include "ft_printf.h"

typedef size_t	(*t_f)(va_list*, t_params*);

typedef struct	s_funcs
{
	char	*c;
	t_f		func;
}				t_funcs;

static t_funcs	type_funcs[] = 
{
	{"%", &type_percent},
	{"c", &type_cbc},
	{"C", &type_cbc},
	{"s", &type_s},
	{"d", &type_di},
	{"i", &type_di},
	{"D", &type_bdubu},
	{"u", &type_bdubu},
	{"U", &type_bdubu},
	{"o", &type_obo},
	{"O", &type_obo},
	{"x", &type_x},
	{"X", &type_bx}
};

#endif
