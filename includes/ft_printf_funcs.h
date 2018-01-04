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

# define NOFFUNCS 20

static t_funcs	g_type_funcs[] =
{
	{'d', &type_di},
	{'i', &type_di},
	{'D', &type_bd},
	{'u', &type_u},
	{'U', &type_bu},
	{'c', &type_c},
	{'C', &type_bc},
	{'s', &type_s},
	{'S', &type_bs},
	{'f', &type_fbf},
	{'F', &type_fbf},
	{'e', &type_e},
	{'E', &type_be},
	{'o', &type_o},
	{'O', &type_bo},
	{'x', &type_x},
	{'X', &type_bx},
	{'%', &type_percent},
	{'p', &type_p},
	{'n', &type_n}
};

#endif
