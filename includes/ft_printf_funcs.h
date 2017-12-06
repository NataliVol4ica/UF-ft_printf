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

#ifndef FT_PRINTF_FUNCS_H
# define FT_PRINTF_FUNCS_H

# include "ft_printf.h"

# define NOFFUNCS 14

static t_funcs	g_type_funcs[] =
{
	{'d', &type_di},
	{'i', &type_di},
	{'D', &type_bdubu},
	{'u', &type_bdubu},
	{'U', &type_bdubu},
	{'c', &type_cbc},
	{'C', &type_cbc},
	{'s', &type_s},
	{'o', &type_obo},
	{'O', &type_obo},
	{'x', &type_x},
	{'X', &type_bx},
	{'%', &type_percent},
	{'p', &type_p}
};

#endif
