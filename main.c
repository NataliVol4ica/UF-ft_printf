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
	printf("Number %D\n", -25);
	ft_printf("Number %D\n", -25);
	ft_printf("Symbol %c\n", 'C');
	printf("Symbol %C\n", -67);
	/*ft_printf("%d", 42);
	ft_printf("Kashim a %d histoires à raconter", 1001);
	ft_printf("Il fait au moins %d", -8000);
	ft_printf("\n");
	ft_printf("%d", 0);
	ft_printf("%d", 0);
	ft_printf("%d", 2147483647);
	ft_printf("%d", -2147483648);
	ft_printf("%d", 2147483647);
	ft_printf("%d", -2147483648);
	ft_printf("%%d 0000042 == |%d|", 34);
	ft_printf("\n");
	ft_printf("%%d 	 == |%d|", 9);
	ft_printf("\n");
	ft_printf("%%d Lydie == |%d|", 503);
	ft_printf("\n");*/
	return (0);
}
