/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:20 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/30 16:24:21 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <unistd.h>

void	final_putstr(t_params *p)
{
	write(1, p->output->str, p->output->len);
}

void	printf_putchar(char c, t_params *p)
{
	p->output->str[p->output->len++] = c;
	p->output->str[p->output->len] = '\0';
}

void	printf_putstr(char *str, t_params *p)
{
	while (*str)
		p->output->str[p->output->len++] = *str++;
	p->output->str[p->output->len] = '\0';
}
