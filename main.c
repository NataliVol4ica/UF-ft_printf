/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c.:+:      :+:    :+:   */
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
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include <unistd.h>
#include <stddef.h>
#include <float.h>
#include <fenv.h>

int		main(void)
{
	int	ret1, ret2;

	double d = 14574393.4567891011;
	float f = 14574393.4567891011f;
	//float f = 643867256.46327f;
	//fesetround(FE_DOWNWARD);
	printf("%d\n", FLT_ROUNDS);
	ret1 = printf("%f\n", 998.0);
	ret2 = ft_printf("%f\n", 998.0);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	/*
	ret1 = printf("%.2f\n", 999.999);
	ret2 = ft_printf("%.2f\n", 999.999);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	ret1 = printf("%.10f\n", 647832.48754);
	ret2 = ft_printf("%.10f\n", 647832.48754);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	printf("%d\n", FLT_ROUNDS);
	ret1 = printf("%.10f\n", 4739.5948379534);
	ret2 = ft_printf("%.10f\n", 4739.5948379534);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	printf("%d\n", FLT_ROUNDS);
	ret1 = printf("%.100f\n", 95595251023769378662109375545434324354343654765815875645454354354354354354353765987632500349594350236293038847179559525102376937866210937554543432435434365476581587564545435435435435435435376598763250034959435023629303884717955952510237693786621093755454343243543436547658158756454543543543543543543537659876.48);
	ret2 = ft_printf("%.100f\n", 95595251023769378662109375545434324354343654765815875645454354354354354354353765987632500349594350236293038847179559525102376937866210937554543432435434365476581587564545435435435435435435376598763250034959435023629303884717955952510237693786621093755454343243543436547658158756454543543543543543543537659876.48);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/	
	/*
	fesetround(FE_TOWARDZERO);
	printf("%d\n", FLT_ROUNDS);
	ret1 = printf("%.1f\n", 0.45);
	ret2 = ft_printf("%.1f\n", 0.45);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	ret1 = printf("       %.56f\n", 0.325003495943502362930388471795595251023769378662109375);
	ret2 = ft_printf("%.56f\n", 0.325003495943502362930388471795595251023769378662109375);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	ret1 = printf("       %.56f\n", 0.325003495943502362930388471795595251023769378662109376);
	ret2 = ft_printf("%.56f\n", 0.325003495943502362930388471795595251023769378662109376);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	ret1 = printf("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
	printf("\n\n\n\n\n\n");
	ret2 = ft_printf("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	int ret1, ret2;

	ret1 = printf("|%D|\n", -1L);
	ret2 = ft_printf("|%D|\n", -1L);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	unsigned long long n = 123;
	char	*str = "hi_word";
	char	*str2 = "2 string";
	short	t = 7835;
	intmax_t r;
	*/
	/*
	printf("1|%S|\n", L"我是一只猫。");
	printf("2|%S|\n", L"我是一只猫。");
    printf("LC_ALL:   %s\n", setlocale(LC_ALL, NULL));
    printf("LC_CTYPE: %s\n", setlocale(LC_CTYPE, NULL));
    */
	/*
	int r1, r2;
	r1 = ft_printf("[%*d]\n", -10, 999);
	r2 = printf("[%*d]\n", -10, 999);
	printf("Ret1 = %d Ret2 = %d\n", r1, r2);
	*/
	/*
	int r1, r2;
	r1 = printf("|%lp|\n", 42);
	r2 = ft_printf("|%lp|\n", 42);
	printf("Ret1 = %d Ret2 = %d\n", r1, r2);
	*/
	
	/*
	int R[4];
	R[0] = printf("|%S|\n", L"我是一只猫。");
	R[1] = ft_printf("|%S|\n", L"我是一只猫。");
	R[2] = printf("|%S|\n", L"αα");
	R[3] = ft_printf("|%S|\n", L"αα");
	printf("%d %d %d %d\n", R[0], R[1], R[2], R[3]);
	*/
/*
	int R[4];
	
	R[0] = printf("|%C|\n", L'我');
	R[1] = ft_printf("|%C|\n", L'我');
	setlocale(LC_CTYPE, "en_US.UTF-8");
	R[2] = printf("|%C|\n", L'α');
	R[3] = ft_printf("|%C|\n", L'α');
	printf("%d %d %d %d\n", R[0], R[1], R[2], R[3]);
*/
	/*
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("|%4.15S|\n", L"我是一只猫。");
	ft_printf("|%4.15S|\n", L"我是一只猫。");
	printf("|%4.3S|\n", L"αα");
	ft_printf("|%4.3S|\n", L"αα");
	*/
	/*
	//undefined behaviour
	int ret1, ret2;
	setlocale(LC_ALL, "en_US.UTF-8");
	ret1 = printf("%.3S\n", L"αα");
	ret2 = ft_printf("%.3S\n", L"αα");
	printf("Ret1 %d Ret2 %d\n", ret1, ret2);
	*/
	/*
	printf("|%D|\n", LONG_MIN);
	ft_printf("|%D|\n", LONG_MIN);
	*/
	/*
	long l = 4294959296;
	printf("%D\n", l);
	ft_printf("%D\n", l);
	*/
	/*
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("%S\n", L"Привет!");
	ft_printf("%S\n", L"Привет!");
	printf("%C\n", L'α');
	ft_printf("%C\n", L'α');
	printf("%ls\n", L"Привет!");
	ft_printf("%ls\n", L"Привет!");
	printf("%lc\n", L'α');
	ft_printf("%lc\n", L'α');
	*/
	/*
	char c, c2;
	c = 'A' + 128;
	c2 = c & 127;
	printf("|%d & 127 = %d|\n", c, c2);
	printf("sizeof(char) %lu sizeof(wchar_t) %lu\n", sizeof(char), sizeof(wchar_t));
	*/
	/*
	wchar_t k, k1 = 945;
	size_t wn;
	
	k = k1;
	wn = 1;
	print_bits(k);
	while (k1 >>= 1)
		wn++;
	printf("Bits: %zu\n", wn);
	*/
	/*
	setlocale(LC_ALL, "en_US.UTF-8");
    int tr = printf("%C", 945);
    printf("\n%d\n", tr);
    char *strr = ft_strnew(3);
    strr[0] = 206;
    strr[1] = 177;
    printf("|%s|\n", strr);
	//printf("%s\n", );
	*/
	/*
	setlocale(LC_ALL, "en_US.UTF-8");
    printf("{%30S}", L"我是一只猫。");
    */
	/*
	float f1 = -100;
	float f2 = 0;
	printf("%f\n", f1/f2);
	*/
	/*
	ft_printf("|%.0%|\n");
	printf("|%.0%|\n");
	*/
	/*
	printf("L  = %ld\n", INT_MAX);
	printf("H  = %hd\n", INT_MAX);
	printf("LH = %lhd\n", INT_MAX);
	ft_printf("F LH = %lhd\n", INT_MAX);
	printf("HL = %hld\n", INT_MAX);
	ft_printf("F HL = %hld\n", INT_MAX);
	*/
	/*
	float f = 643867256.46327f;
	printf("%.10a\n", f);
	*/
	/*
	double d = 10;
	printf("|%.0e|\n", d);
	*/
	/*
	printf("%hhU\n", 4294967296);
	ft_printf("%hhU\n", 4294967296);
	*/
	//	ft_printf("%U\n", 4294967296);
	/*
	ft_printf("%jd\n", -9223372036854775808);
	printf("%jd\n", -9223372036854775808
	*/
	return (0);
}
