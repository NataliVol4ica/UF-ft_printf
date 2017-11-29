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
#include <stdlib.h>

void		ft_putnbr_fd(long num, int fd)
{
	char	*str;
	long	n;
	char	dig;
	t_list	*l;
	int		is_min;

	l = NULL;
	is_min = num < 0 && ((long)(num - 1)) > 0 ? 1 : 0;
	n = num < 0 ? -num : num;
	while (n != 0)
	{
		dig = n % 10 + '0';
		if (is_min && !l)
			dig++;
		n /= 10;
		ft_lstpushback(&l, ft_lstnew((void*)&dig, sizeof(dig)));
	}
	dig = '-';
	if (num < 0)
		ft_lstpushback(&l, ft_lstnew((void*)&dig, sizeof(dig)));
	str = ft_list_to_string(l);
	ft_putstr_fd(ft_strrev(str), fd);
	free(str);
	ft_lstdel(&l, NULL);
}
