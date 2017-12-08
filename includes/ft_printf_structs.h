/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:48:51 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/05 15:48:52 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H

# include <string.h>

typedef enum	e_length
{
	EMPTY = 0, HH = 2, H, L, LL, J, T, Z, BL
}				t_length;

typedef struct	s_output
{
	char	*str;
	size_t	len;
}				t_output;

typedef struct	s_flags
{
	_Bool	space;
	_Bool	hash;
	_Bool	plus;
	_Bool	minus;
	_Bool	zero;
	_Bool	apostrophe;
}				t_flags;

typedef struct	s_params
{
	size_t		n;
	t_flags		*flags;
	size_t		width;
	size_t		precision;
	t_length	length;
	t_output	*output;
	t_output	*prefix;
}				t_params;

typedef size_t	(*t_f)(va_list*, t_params*);
typedef struct	s_funcs
{
	char	c;
	t_f		func;
}				t_funcs;

#endif
