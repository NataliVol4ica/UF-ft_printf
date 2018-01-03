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

typedef struct	s_print_str
{
	char	*str;
	size_t	len;
	size_t	size;
}				t_print_str;

typedef struct	s_str
{
	char	*str;
	int		size;
}				t_str;

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
	int			width;
	int			precision;
	_Bool		is_width_subst;
	_Bool		is_precision_subst;
	t_length	length;
	t_print_str	*toprint;
	size_t		pref_len;
	_Bool		isnegative;
	char		*alphabet;
}				t_params;

typedef void	(*t_f)(va_list*, t_params*);
typedef struct	s_funcs
{
	char		c;
	t_f			func;
}				t_funcs;

typedef struct	s_float
{
	_Bool		is_pos;
	char		*num;
	size_t		size;
	size_t		point;

}				t_float;

#endif
