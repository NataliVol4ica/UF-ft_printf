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

typedef struct	s_params
{
	size_t	n;
	char	*flags;
	size_t	width;
	size_t	precision;
	char	*length;
}				t_params;

size_t			react_on_flags_di(intmax_t num, char *flags);
size_t			react_on_flags_obo(char *flags);
size_t			react_on_flags_x(char *flags);
size_t			react_on_flags_bx(char *flags);

int				convert_numeric_signed(intmax_t *n, t_params *at);
int				convert_numeric_unsigned(uintmax_t *n, t_params *at);

int				print_signed_num(va_list *ap, t_params *at);
int				print_unsigned_num(va_list *ap, t_params *at);
int				print_oct_hex(va_list *ap, t_params *at, char sys);

t_params		*read_params(char *fmt, size_t *pos, va_list *ap);
void			del_params(t_params **at);

size_t			get_n(char *str, int *p);
char			*get_flags(char *str, int *p);
size_t			get_width(char *str, int *p, va_list *ap);
size_t			get_precision(char *str, int *p, va_list *ap);
char			*get_length(char *str);

char			is_flag(char c);
uintmax_t		printf_atoi(char *str, int *p);

void			type_n(va_list *ap, int ret);

size_t			type_percent(va_list *ap, t_params *p);
size_t			type_cbc(va_list *ap, t_params *p);
size_t			type_s(va_list *ap, t_params *p);
size_t			type_di(va_list *ap, t_params *p);
size_t			type_bdubu(va_list *ap, t_params *at);
size_t			type_obo(va_list *ap, t_params *p);
size_t			type_x(va_list *ap, t_params *p);
size_t			type_bx(va_list *ap, t_params *p);

#endif
