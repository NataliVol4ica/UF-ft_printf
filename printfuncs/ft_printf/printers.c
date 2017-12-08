/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:20 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:24:21 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

void	final_putstr(char *str, size_t len)
{
	if (len == 0)
		return ;
	write(1, str, len);
}

void	print_width(char c, size_t num)
{
	char	*str;
	size_t	i;

	if (num == 0)
		return ;
	str = (char*)malloc(sizeof(char) * num);
	i = num;
	while (i-- > 0)
		str[i] = c;
	write(1, str, num);
	free(str);
}
