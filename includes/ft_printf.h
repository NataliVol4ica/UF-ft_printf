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
# include <wchar.h>
# include "ft_printf_structs.h"

# define MAX_STR 32
# define START_SIZE 2048
# define NUMBERS_S "0123456789abcdef"
# define NUMBERS_B "0123456789ABCDEF"

/*
** LENGTH CONVERTIONS
*/

void		convert_di(intmax_t *n, t_params *p);
void		convert_ouxbx(uintmax_t *n, t_params *p);

/*
** TOOLS
*/

intmax_t	printf_atoi(char *str, int *p);
void		rev_str(char *from, char *until);
size_t		count_bits(wchar_t k);
int			check_bits(size_t *b, wchar_t c, t_params *p);
size_t		get_next_length(char *str, t_length *ll);

/*
** PRINTERS
*/

void		print_symbol(t_params *p, char c);
void		print_str(t_params *p, char *str, _Bool ignore_prec);
int			printf_putwchar(wchar_t c, t_params *p);
void		print_number(uintmax_t n, size_t base, t_params *p, void (*preffunc)(t_params*));

/*
** PARAM INITIALISATION
*/

t_params	*init_params(void);
void		read_params(t_params *p, char *fmt, size_t *pos, va_list *ap);
void		del_params(t_params **p);
void		zero_params(t_params *p);
void		realloc_toprint(t_print_str *tp);

/*
** READING PARAMETERS
*/

size_t		get_n(char *str, int *p);
void		get_flags(char *str, int *p, t_flags *f);
int			get_width(char *str, int *p, va_list *ap, _Bool *b);
int			get_precision(char *str, int *p, va_list *ap, _Bool *b);
t_length	get_length(char *str, int *i);

/*
** PREFIXES
*/

void		print_sign_pref(t_params *p);
void		print_oct_pref(t_params *p);
void		print_hex_pref(t_params *p);

/*
** TYPE FUNCTIONS
*/

void		type_percent(va_list *ap, t_params *p);
void		type_c(va_list *ap, t_params *p);
void		type_bc(va_list *ap, t_params *p);
void		type_s(va_list *ap, t_params *p);
void		type_bs(va_list *ap, t_params *p);
void		type_di(va_list *ap, t_params *p);
void		type_bd(va_list *ap, t_params *p);
void		type_u(va_list *ap, t_params *p);
void		type_bu(va_list *ap, t_params *p);
void		type_o(va_list *ap, t_params *p);
void		type_bo(va_list *ap, t_params *p);
void		type_x(va_list *ap, t_params *p);
void		type_bx(va_list *ap, t_params *p);
void		type_p(va_list *ap, t_params *p);
void		type_fbf(va_list *ap, t_params *p);
void		type_n(va_list *ap, t_params *p);
void		type_none(char c, t_params *p);

#endif
