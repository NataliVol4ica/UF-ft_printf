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
# include "ft_printf_structs.h"

#include <stdio.h>

# define MAX_STR 32

# define XSTR "abcdef"
# define BXSTR "ABCDEF"

/*
** FLAG PARSING
*/

int				convert_numeric_signed(intmax_t *n, t_params *p);
int				convert_numeric_unsigned(uintmax_t *n, t_params *p);
uintmax_t		printf_atoi(char *str, int *p);
void			check_width_str(t_params *p);
void			check_width_numeric(t_params *p);
void			rev_str(char *from, size_t n);
/*
** PRINTERS
*/

void			final_putstr(char *str, size_t len);
void			print_width(char c, size_t num);
void			printf_putchar(char c, t_params *p);
void			printf_putnbr_uns(uintmax_t n, t_params *p);
void			printf_convert_oboxbx(uintmax_t n, size_t base,
										t_params *p, char c);

int				print_signed_num(va_list *ap, t_params *p);
int				print_unsigned_num(va_list *ap, t_params *p);
int				print_oct_hex(va_list *ap, t_params *p, char sys);

/*
** PARAM INITIALISATION
*/

t_params		*init_params(void);
void			read_params(t_params *p, char *fmt, size_t *pos, va_list *ap);
void			del_params(t_params **p);
void			zero_params(t_params *p);

/*
** READING PARAMETERS
*/

size_t			get_n(char *str, int *p);
void			get_flags(char *str, int *p, t_flags *f);
size_t			get_width(char *str, int *p, va_list *ap);
size_t			get_precision(char *str, int *p, va_list *ap);
t_length		get_length(char *str, int *i);

/*
** TYPE FUNCTIONS
*/

size_t			type_percent(va_list *ap, t_params *p);
size_t			type_cbc(va_list *ap, t_params *p);
size_t			type_s(va_list *ap, t_params *p);
size_t			type_di(va_list *ap, t_params *p);
size_t			type_bdubu(va_list *ap, t_params *p);
size_t			type_obo(va_list *ap, t_params *p);
size_t			type_x(va_list *ap, t_params *p);
size_t			type_bx(va_list *ap, t_params *p);
size_t			type_p(va_list *ap, t_params *p);
void			type_n(va_list *ap, int ret);

/*
** DEVELOPMENT
*/

void			print_params(t_params *t);

#endif
