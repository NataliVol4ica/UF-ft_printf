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

static void	small_f(long long n, int fd, int ismin)
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

void		ft_putnbr_fd(long long n, int fd)
{
	long long	num;

	num = n;
	if (num < 0)
		ft_putchar_fd('-', fd);
	num = num < 0 ? -num : num;
	small_f(num, fd, n < 0 && (long long)(n - 1) > 0 ? 1 : 0);
}
