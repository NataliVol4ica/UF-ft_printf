/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:29:09 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:29:10 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	*str = "hi_word";
	char	*str2 = "2 string";

	ft_printf("The string is: \"%s\"\nSecond string is \"%s\"\n", str, str2);
	ft_printf("Number %d\n", -2147483648);
	ft_printf("Number %D\n", -25);
	ft_printf("Symbol %c\n", 'C');
	return (0);
}
