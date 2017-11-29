/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:59:28 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/01 16:59:28 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_digits(int value, int base)
{
	long	temp;
	int		ans;

	temp = value;
	temp = temp < 0 ? -temp : temp;
	ans = 0;
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		ans++;
		temp /= base;
	}
	return (ans);
}
