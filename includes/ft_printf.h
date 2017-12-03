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

typedef struct	s_params
{
	size_t	n;
	char	*flags;
	size_t	width;
	size_t	precision;
	char	*length;
}				t_params;

int				convert_numeric(intmax_t *n, t_params *at);
int				uconvert_numeric(uintmax_t *n, t_params *at);

int				print_signed_num(va_list *ap, t_params *at);
int				print_unsigned_num(va_list *ap, t_params *at);
int				print_oct_hex(va_list *ap, t_params *at, char sys);

t_params		*read_params(char *fmt, int *pos, va_list *ap);
void			del_params(t_params **at);

size_t			get_n(char *str, int *p);
char			*get_flags(char *str, int *p);
size_t			get_width(char *str, int *p, va_list *ap);
size_t			get_precision(char *str, int *p, va_list *ap);
char			*get_length(char *str);

char			is_flag(char c);
uintmax_t		printf_atoi(char *str, int *p);

#endif
