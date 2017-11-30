/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:55:03 by nkolosov          #+#    #+#             */
/*   Updated: 2017/10/25 13:55:05 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static void	small_f(uintmax_t n, int fd, int ismin)
{
	char	c;

	if (n >= 10)
	{
		small_f(n / 10, fd, 0);
		c = n % 10 + '0';
		if (ismin == 1)
			c += 1;
		ft_putchar_fd(c, fd);
	}
	else
		ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(intmax_t n, int fd)
{
	uintmax_t	num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = n < 0 ? -n : n;
	num = n < 0 && (intmax_t)(n - 1) > 0 ? num + 1 : num;
	small_f(num, fd, n < 0 && (long long)(n - 1) > 0 ? 1 : 0);
}
