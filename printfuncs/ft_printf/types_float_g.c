/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"

static void	type_gbg(va_list *ap, t_params *p, char c, _Bool is_cap)
{
	(void)ap;
	(void)p;
	(void)c;
	(void)is_cap;
}

void		type_g(va_list *ap, t_params *p)
{
	type_gbg(ap, p, 'e', 0);
}

void		type_bg(va_list *ap, t_params *p)
{
	type_gbg(ap, p, 'E', 1);
}
