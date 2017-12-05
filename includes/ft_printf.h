/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:28:41 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 15:28:41 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <string.h>

#include <stdio.h>

typedef enum	e_length
{
	EMPTY = 0, L = 2, LL, H, HH, J, Z, T, BL
}				t_length;

typedef struct	s_flags
{
	_Bool	space;
	_Bool	hash;
	_Bool	plus;
	_Bool	minus;
	_Bool	zero;
}				t_flags;

typedef struct	s_params
{
	size_t		n;
	t_flags		*flags;
	size_t		width;
	size_t		precision;
	t_length	length;
}				t_params;

/*
** FLAG PARSING
*/

size_t			react_on_flags_di(intmax_t num, t_flags *flags);
size_t			react_on_flags_obo(t_flags *flags);
size_t			react_on_flags_x(t_flags *flags);
size_t			react_on_flags_bx(t_flags *flags);

int				convert_numeric_signed(intmax_t *n, t_params *at);
int				convert_numeric_unsigned(uintmax_t *n, t_params *at);

/*
** PRINTERS
*/

int				print_signed_num(va_list *ap, t_params *at);
int				print_unsigned_num(va_list *ap, t_params *at);
int				print_oct_hex(va_list *ap, t_params *at, char sys);

/*
** PARAM INITIALISATION
*/

t_params		*init_params(void);
void			read_params(t_params *at, char *fmt, size_t *pos, va_list *ap);
void			del_params(t_params **at);
void			zero_flags(t_flags *f);

/*
** READING PARAMETERS
*/

size_t			get_n(char *str, int *p);
void			get_flags(char *str, int *p, t_flags *f);
size_t			get_width(char *str, int *p, va_list *ap);
size_t			get_precision(char *str, int *p, va_list *ap);
t_length		get_length(char *str, int *i);

uintmax_t		printf_atoi(char *str, int *p);

void			type_n(va_list *ap, int ret);

/*
** TYPE FUNCTIONS
*/

size_t			type_percent(va_list *ap, t_params *p);
size_t			type_cbc(va_list *ap, t_params *p);
size_t			type_s(va_list *ap, t_params *p);
size_t			type_di(va_list *ap, t_params *p);
size_t			type_bdubu(va_list *ap, t_params *at);
size_t			type_obo(va_list *ap, t_params *p);
size_t			type_x(va_list *ap, t_params *p);
size_t			type_bx(va_list *ap, t_params *p);

/*
** DEVELOPMENT
*/

void			print_params(t_params *t);

#endif
