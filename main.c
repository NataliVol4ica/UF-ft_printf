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
#include "../includes/ft_printf_consts.h"
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include <unistd.h>
#include <stddef.h>
#include <float.h>
#include <fenv.h>
#include <math.h>

void	print_str_twos(char *str)
{
	int ret;

	while (*str)
	{
		printf("\t\"");
		ret = printf("%.72s", str);
		str += ret;
		printf("\"");
		if (*str) printf("\n");
	}
}

int		main(void)
{
	fflush(stdout);
	int	ret1, ret2;
	
	char	*s1 = "1";
	char	*s2 = "2";
	for (int i = 1; i < 15001; i++)
	{
		s1 = long_mul(s1, s2);
		if (i == 1 || i == 2 || i == 5 || i == 10 || i == 25 || i == 50 ||
			i == 100 || i == 1000 || i == 2000 || i == 5000 || i == 10000 ||
			i == 15000)
		{
			printf("\t{%d,\n", i);
			print_str_twos(s1);
			printf("}");
			if (i != 15000)
				printf(",");
			printf("\n");
		}
		//printf("\t{%d,\n\t\"%s\"},\n", i, s1);
	}
	/*	
	   printf("|%.4g|\n", 998.099);
	ft_printf("|%.4g|\n", 998.099);
	   printf("|%.4g|\n", 1.0000545);
	ft_printf("|%.4g|\n", 1.0000545);
	   printf("|%.2g|\n", 0.00002055);
	ft_printf("|%.2g|\n", 0.00002055);
	   printf("|%#8.2g|\n", 998.999);
	ft_printf("|%#8.2g|\n", 998.999);
	   printf("|%8.2g|\n", 998.999);
	ft_printf("|%8.2g|\n", 998.999);
	   printf("|%10.g|\n", 0.5);
	ft_printf("|%10.g|\n", 0.5);
	   printf("|%+#.5g|\n", 0.12345);
	ft_printf("|%+#.5g|\n", 0.12345);
	   printf("|% .30000g|\n", -1024.1);
	ft_printf("|% .30000g|\n", -1024.1);
	ft_printf("|%.3g|\n", 0.999643287658734658368543);
	   printf("|%.3g|\n", 0.999643287658734658368543);
	ft_printf("|%#.3g|\n", 0.999643287658734658368543);
	   printf("|%#.3g|\n", 0.999643287658734658368543);
	   printf("|%.3g|\n", 999.0);
	ft_printf("|%.3g|\n", 999.0);
	  fesetround(FE_UPWARD);
	   printf("|%8.3g|\n", 999.999);
	ft_printf("|%8.3g|\n", 999.999);
	   printf("|%10.g|\n", 1024.04445);
	ft_printf("|%10.g|\n", 1024.04445);
	   printf("|% 10.g|\n", 1.0245);
	ft_printf("|% 10.g|\n", 1.0245);

	   printf("|%#g|\n", -256.0);
	ft_printf("|%#g|\n", -256.0);
	   printf("|%10.g|\n", 1.0245);
	ft_printf("|%10.g|\n", 1.0245);
	
	   printf("|%10.g|\n", 0.5);
	ft_printf("|%10.g|\n", 0.5);
	   printf("|%10.g|\n", 0.0);
	ft_printf("|%10.g|\n", 0.0);
	printf("\n");

	printf("|%g|\n", 0.0);
	printf("|%#g|\n", 0.0);
	printf("|%.g|\n", 0.0);
	printf("|%#.g|\n", 0.0);
	printf("|%.1g|\n", 0.0);
	printf("|%#.1g|\n", 0.0);
	printf("|%.5g|\n", 0.0);
	printf("|%#.5g|\n", 0.0);
	printf("\n");

	ft_printf("|%g|\n", 0.0);
	ft_printf("|%#g|\n", 0.0);
	ft_printf("|%.g|\n", 0.0);
	ft_printf("|%#.g|\n", 0.0);
	ft_printf("|%.1g|\n", 0.0);
	ft_printf("|%#.1g|\n", 0.0);
	ft_printf("|%.5g|\n", 0.0);
	ft_printf("|%#.5g|\n", 0.0);

	ret1 =    printf("|%.g|\n", 0.0);
	ret2 = ft_printf("|%.g|\n", 0.0);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	ret1 =    printf("|%#.g|\n", 0.0);
	ret2 = ft_printf("|%#.g|\n", 0.0);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/

	/*ret1 =    printf("|%d|\n", 0);
	ret2 = ft_printf("|%d|\n", 0);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	printf("|%D|\n", LONG_MIN);
	ft_printf("|%D|\n", LONG_MIN);
	float f1 = -100;
	float f2 = 0;
	printf("%f\n", f1/f2);
	ft_printf("|%.0%|\n");
	printf("|%.0%|\n");
	printf("L  = %ld\n", INT_MAX);
	printf("H  = %hd\n", INT_MAX);
	printf("LH = %lhd\n", INT_MAX);
	ft_printf("F LH = %lhd\n", INT_MAX);
	printf("HL = %hld\n", INT_MAX);
	ft_printf("F HL = %hld\n", INT_MAX);
	float f = 643867256.46327f;
	printf("%.10a\n", f);
	*/
	return (0);
}
