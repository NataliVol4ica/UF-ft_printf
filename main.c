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
#include <stdint.h>
#include "../includes/ft_printf_funcs.h"
#include <stdlib.h>

int		main(void)
{
	unsigned long long n = 123;
	char	*str = "hi_word";
	char	*str2 = "2 string";
	short	t;
	intmax_t r;

	t = 7835;
	/*
	printf("% 010d\n", 27);
	ft_printf("% 010d\n", 27);
	printf("%- 010d\n", 27);
	ft_printf("%- 010d\n", 27);
	printf("% 010d\n", -27);
	ft_printf("% 010d\n", -27);
	*/
	ft_printf("|%5%|\n");
	printf("|%5%|\n");
	ft_printf("|%010c|\n", 'r');
	printf("|%010c|\n", 'r');
	ft_printf("|%010s|\n", "r");
	printf("|%010s|\n", "r");
	/*for (int i = 0; i < 13; i++)
		printf("symb[%d] = \'%c\'\n", i, *type_funcs[i].c);
	printf("\n=================\n");*/
	/*ft_printf("%5$ #0+--+00#0  *.*llu\n", 10, 25, (long long)123);
	ft_printf("lalala %%d %%i\n");
	ft_printf("lalala %d\n", -2147483648);
	ft_printf("The string is: \"%s\"\nSecond string is \"%s\"\n", str, str2);
	ft_printf("Number %+d\n", -2147483648);
	printf("Number %D\n", -25);
	ft_printf("Number %D\n", -25);
	ft_printf("Symbol %c\n", 'C');
	//printf("Symbol %C\n", -67);
	//printf("Symbol %c\n", 23);
	//printf("aaaaa %++d bbbb\n", t);
	ft_printf("aaaaa %+ d bbbb\n", t);
	ft_printf("aaaaa % d bbbb\n", t);
	ft_printf("aaaaa %++d bbbb\n", t);*/
	//printf("aaaaa %+6d bbbb\n", t);
	//printf("aaaaa %#*o bbbb %#*x\n", 10, t, 10, t);
	/*ft_printf("aaaaa |%0#*o| bbbb |%0#*x| cccc |%0#*X|\n", 10, t, 9, t, 8, t);
	printf("aaaaa |%0#*o| bbbb |%0#*x| cccc |%0#*X|\n", 10, t, 9, t, 8, t);
	printf("|%020s|\n", "test string");*/
	//printf("% +d\n", 25);
	//printf("uns %U\n", (unsigned int)2147483648);
	/*ft_printf("uns %u\n", (unsigned int)2147483648);*/
	//printf("%O\n", -300);
	//printf("Number %zd\n", -2147483648);
	//printf("%ls\n", (int*)("@"));
	//printf("%d %3$d %d\n", 1, 2, 3, 4);
	/*r = -8000;
	printf("R = %jd\n", r);*/
	//ft_printf("%d", 42);
	/*ft_printf("Kashim a %d histoires à raconter", 1001);
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
	/*ft_printf("%%d 0000042 == |%d|", 34);
	ft_printf("\n");
	ft_printf("%%d 	 == |%d|", 9);
	ft_printf("\n");
	ft_printf("%%d Lydie == |%d|", 503);
	ft_printf("\n");*/
	/*ft_printf("%%-i 42 == %-i\n", 42);
	ft_printf("%%-d 42 == %-d\n", -2147483648);
	ft_printf("%%-i -42 == %-i\n", -42);
	ft_printf("%%-4d 42 == |%-4d|\n", 42);
	ft_printf("%%-5d -42 == |%-5d|\n", -42);
	ft_printf("|%3i|%-3i|\n", 42, 42);
	ft_printf("%%-4i 42 == |%-4i|\n", 42);*/
	//ft_printf("%llu\n", n);
	/*int k;
	ft_printf("LALALALALAL\n%n",&k);
	ft_printf("%d\n", k);
	ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &k);
	printf("%d\n", k);
	ft_printf("%d%n",9, &k);
	ft_printf("%d\n", k);*/
	/*int nn = -47;
	printf("%tn\n", nn);*/
	//printf("111");
	//printf("%d\n", printf("lalala %c\n", 11114645));
	/*printf("%td\n", -5749885937593795);*/
	return (0);
}
