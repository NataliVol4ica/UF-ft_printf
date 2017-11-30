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

#include <stdarg.h>

typedef struct	s_atributes
{
	char	*flags;
	char	*length;
}				t_atributes;

int				print_signed_num(va_list *ap, t_atributes *at);
int				print_unsigned_num(va_list *ap, t_atributes *at);
char			*get_length(char *str);
char			*get_flags(char *str);

t_atributes		*read_atributes(char *fmt, int *pos);
void			del_atributes(t_atributes **at);

#endif
