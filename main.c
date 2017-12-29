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

/*void		print_params(t_params *p)
{
	printf("\n=======\n");
 	printf("n = %zu\n", p->n);
 	printf("Flags = %d%d%d%d%d\n", p->flags->space, p->flags->hash,
	p->flags->plus, p->flags->minus, p->flags->zero);
 	printf("Width = %zu\n", p->width);
 	printf("Precision = %zu\n", p->precision);
 	printf("Length = %u\n", p->length);
 	p->output->str[p->output->len] = '\0';
 	p->prefix->str[p->prefix->len] = '\0';
 	printf("Prefix \"%s\" of len %zu\n", p->prefix->str, p->prefix->len);
 	printf("Output \"%s\" of len %zu\n", p->output->str, p->output->len);
 	printf("fi\n");
}*/

int		main(void)
{
	int	ret1, ret2;

	ret1 = printf("|%5$5.4D|", 0, -25, 25, 24, -24);
	ret2 = ft_printf("|%5$5.4D|", 0, -25, 25, 24, -24);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	
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
	ft_printf("|%03.2d|\n", 0);
	printf("|%03.2d|\n", 0);
	ft_printf("|%07.5o|\n", 0);
	printf("|%07.5o|\n", 0);
	*/
	/*
	ft_printf("|%.0d|\n", 0);
	printf("|%.0d|\n", 0);
	ft_printf("|%#.o %#.0o|\n", 0, 0);
	printf("|%#.o %#.0o|\n", 0, 0);
	ft_printf("|%#.x %#.0x|\n", 1, 1);
	printf("|%#.x %#.0x|\n", 1, 1);
	ft_printf("|%#.x %#.1x|\n", 1, 1);
	printf("|%#.x %#.1x|\n", 1, 1);
	ft_printf("|%#.x %#.0x|\n", 0, 0);
	printf("|%#.x %#.0x|\n", 0, 0);
	ft_printf("|%#.x %#.1x|\n", 0, 0);
	printf("|%#.x %#.1x|\n", 0, 0);
	*/
	/*
	ft_printf("|%010x|\n", 542);
	printf("|%010x|\n", 542);
	*/
	/*
	ft_printf("%-5.10o\n", 2500);
	printf("%-5.10o\n", 2500);
	*/
	/*
	float f1 = -100;
	float f2 = 0;
	printf("%f\n", f1/f2);
	*/
	/*
	ft_printf("|%.2x|\n", 5427);
	printf("|%.2x|\n", 5427);
	*/
	/*
	ft_printf("|%.0%|\n");
	printf("|%.0%|\n");
	*/
	/*
	printf("|%.10d|\n", -42);
	ft_printf("|%.10d|\n", -42);
	printf("|%-15.10d|\n", -42);
	ft_printf("|%-15.10d|\n", -42);
	printf("|%- 15.10d|\n", 42);
	ft_printf("|%- 15.10d|\n", 42);
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
	printf("|% h|\n");
	ft_printf("|% h|\n");
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
	struct lconv *loc;
	setlocale(LC_ALL, "en_US.UTF-8");
	loc = localeconv();
	printf("Thousands Separator: \"%s\"\n", loc->thousands_sep);
	printf("Thousands Separator: \"%d\"\n", loc->thousands_sep[0]);
	printf("%'d\n", 1123456789);
	*/
	/*
	printf("%#x\n", 0);
	ft_printf("%#x\n", 0);
	*/
	/*
	char	*str3 = "some str";
	printf("%p\n", str3);
	ft_printf("%p\n", str3);
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
	/*
	ft_printf("%+d\n", 0);
	printf("%+d\n", 0);
	*/
	/*
	printf("|%5%|\n");
	ft_printf("|%5%|\n");
	*/
	/*
	printf("% 010d\n", 27);
	ft_printf("% 010d\n", 27);
	printf("%- 010d\n", 27);
	ft_printf("%- 010d\n", 27);
	printf("% 010d\n", -27);
	ft_printf("% 010d\n", -27);
	*/
	/*
	ft_printf("|%5%|\n");
	printf("|%5%|\n");
	ft_printf("|%010c|\n", 'r');
	printf("|%010c|\n", 'r');
	ft_printf("|%010s|\n", "r");
	printf("|%010s|\n", "r");
	*/
	/*
	for (int i = 0; i < 13; i++)
		printf("symb[%d] = \'%c\'\n", i, *type_funcs[i].c);
	printf("\n=================\n");
	*/
	/*
	ft_printf("%5$ #0+--+00#0  *.*llu\n", 10, 25, (long long)123);
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
	ft_printf("aaaaa %++d bbbb\n", t);
	*/
	//printf("aaaaa %+6d bbbb\n", t);
	//printf("aaaaa %#*o bbbb %#*x\n", 10, t, 10, t);
	/*
	ft_printf("aaaaa |%0#*o| bbbb |%0#*x| cccc |%0#*X|\n", 10, t, 9, t, 8, t);
	printf("aaaaa |%0#*o| bbbb |%0#*x| cccc |%0#*X|\n", 10, t, 9, t, 8, t);
	printf("|%020s|\n", "test string");
	*/
	//printf("% +d\n", 25);
	//printf("uns %U\n", (unsigned int)2147483648);
	/*
	ft_printf("uns %u\n", (unsigned int)2147483648);*/
	//printf("%O\n", -300);
	//printf("Number %zd\n", -2147483648);
	//printf("%ls\n", (int*)("@"));
	//printf("%d %3$d %d\n", 1, 2, 3, 4);
	/*
	r = -8000;
	printf("R = %jd\n", r);
	*/
	//ft_printf("%d", 42);

	//ft_printf("LALALA %d lololo \n", 1024);

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
	
	/*
	ft_printf("%%d 0000042 == |%d|", 34);
	ft_printf("\n");
	ft_printf("%%d 	 == |%d|", 9);
	ft_printf("\n");
	ft_printf("%%d Lydie == |%d|", 503);
	ft_printf("\n");
	*/
	/*
	ft_printf("%%-i 42 == %-i\n", 42);
	ft_printf("%%-d 42 == %-d\n", -2147483648);
	ft_printf("%%-i -42 == %-i\n", -42);
	ft_printf("%%-4d 42 == |%-4d|\n", 42);
	ft_printf("%%-5d -42 == |%-5d|\n", -42);
	ft_printf("|%3i|%-3i|\n", 42, 42);
	ft_printf("%%-4i 42 == |%-4i|\n", 42);
	*/
	//ft_printf("%llu\n", n);
	/*
	int k;
	ft_printf("LALALALALAL\n%n",&k);
	ft_printf("%d\n", k);
	ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &k);
	printf("%d\n", k);
	ft_printf("%d%n",9, &k);
	ft_printf("%d\n", k);
	*/
	/*
	int nn = -47;
	printf("%tn\n", nn);
	*/
	//printf("111");
	//printf("%d\n", printf("lalala %c\n", 11114645));
	/*printf("%td\n", -5749885937593795);*/
		/*ft_printf("%00d", -42);                       
	ft_printf("%5d", 42);                         
	ft_printf("%05d", 42);                        
	ft_printf("%0+5d", 42);                       
	ft_printf("%5d", -42);                        
	ft_printf("%05d", -42);                       
	ft_printf("%0+5d", -42);                      
	ft_printf("%-5d", 42);                        
	ft_printf("%-05d", 42);                       
	ft_printf("%-5d", -42);                       
	ft_printf("%-05d", -42);                      
	ft_printf("%hd", 32767);                      
	ft_printf("%hd", -32768);                  	
	ft_printf("%hd", 32768);                      
	ft_printf("%hd", -32769);                 	
	ft_printf("%hhd", 127);                       
	ft_printf("%hhd", 128);                       
	ft_printf("%hhd", -128);                      
	ft_printf("%hhd", -129);                      
	ft_printf("%ld", 2147483647);                 
	ft_printf("%ld", -2147483648);                
	ft_printf("%ld", 2147483648);                 
	ft_printf("%ld", -2147483649);                
	ft_printf("%lld", 9223372036854775807);       
	ft_printf("%lld", -9223372036854775808);      
	ft_printf("%jd", 9223372036854775807);        
	ft_printf("%jd", -9223372036854775808);       
	ft_printf("%zd", 4294967295);                 
	ft_printf("%zd", 4294967296);                 
	ft_printf("%zd", -0);                         
	ft_printf("%zd", -1);                         
	ft_printf("%d", 1);                           
	ft_printf("%d %d", 1, -2);                    
	ft_printf("%d %d %d", 1, -2, 33);             
	ft_printf("%d %d %d %d", 1, -2, 33, 42);      
	ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
	ft_printf("%4.15d", 42);                      
	ft_printf("%.2d", 4242);                      
	ft_printf("%.10d", 4242);                     
	ft_printf("%10.5d", 4242);                    
	ft_printf("%-10.5d", 4242);                   
	ft_printf("% 10.5d", 4242);                   
	ft_printf("%+10.5d", 4242);                   
	ft_printf("%-+10.5d", 4242);                  
	ft_printf("%03.2d", 0);                       
	ft_printf("%03.2d", 1);                       
	ft_printf("%03.2d", -1);                      
	ft_printf("@moulitest: %.10d", -42);         
	ft_printf("@moulitest: %.d %.0d", 42, 43);    
	ft_printf("@moulitest: %.d %.0d", 0, 0);      
	ft_printf("@moulitest: %5.d %5.0d", 0, 0); 
	*/
	/*
	ft_printf("\n%x", 42);
	ft_printf("\n%X", 42);
	ft_printf("\n%x", 0);
	ft_printf("\n%X", 0);
	ft_printf("\n%x", -42);
	ft_printf("\n%X", -42);
	ft_printf("\n%x", 4294967296);              
	ft_printf("\n%X", 4294967296);           
	ft_printf("\n%x", 42);               
	ft_printf("\n%10x", 42);           
	ft_printf("\n%-10x", 42);                
	ft_printf("\n%lx", 4294967296);           
	ft_printf("\n%llX", 4294967296);           
	ft_printf("\n%hx", 4294967296);             
	ft_printf("\n%hhX", 4294967296);       
	ft_printf("\n%jx", 4294967295);        
	ft_printf("\n%jx", 4294967296);           
	ft_printf("\n%jx", -4294967296);         
	ft_printf("\n%jx", -4294967297);            
	ft_printf("\n%llx", 9223372036854775807L);     
	ft_printf("\n%llx", 9223372036854775808L);
	ft_printf("\n%010x", 542);                   
	ft_printf("\n%-15x", 542);                   
	ft_printf("\n%2x", 542);                    
	ft_printf("\n%.2x", 5427);                    
	ft_printf("\n%5.2x", 5427);                    
	ft_printf("\n%#x", 42);                       
	ft_printf("\n%#llx", 9223372036854775807L);   
	ft_printf("\n%#x", 0);                        
	ft_printf("\n%#x", 42);                     
	ft_printf("\n%#X", 42);                        
	ft_printf("\n%#8x", 42);                     
	ft_printf("\n%#08x", 42);
	ft_printf("\n%#-08x", 42);                  
	ft_printf("\n@moulitest: %#.x %#.0x", 0, 0);    
	ft_printf("\n@moulitest: %.x %.0x", 0, 0);  
	ft_printf("\n@moulitest: %5.x %5.0x", 0, 0); 
	*/
	return (0);
}
