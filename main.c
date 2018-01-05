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

int		main(void)
{
	int	ret1, ret2;

/*	   printf("|%.4g|\n", 0.0000245);
	ft_printf("|%.4g|\n", 0.0000245);
	   printf("|%.1g|\n", -0.0);
	ft_printf("|%.1g|\n", -0.0);*/
	   printf("|%g|\n", -0.0);
	ft_printf("|%g|\n", -0.0);
/*	   printf("|%.4g|\n", 200.245245);
	ft_printf("|%.4g|\n", 200.245245);
	   printf("|%.4g|\n", 999.999);
	ft_printf("|%.4g|\n", 999.999);
	   printf("|%.2g|\n", 988.2);
	ft_printf("|%.2g|\n", 988.2);
	   printf("|%.3g|\n", 999.0);
	ft_printf("|%.3g|\n", 999.0);
	   printf("|%.4g|\n", 998.099);
	ft_printf("|%.4g|\n", 998.099);
	   printf("|%.2g|\n", 988.099);
	ft_printf("|%.2g|\n", 988.099);
	   printf("|%.3g|\n", 9998.999);
	ft_printf("|%.3g|\n", 9998.999);
	   printf("|%.3g|\n", 0.999643287658734658368543);
	ft_printf("|%.3g|\n", 0.999643287658734658368543);*/
	/*
	for (int i = 1; i < 15001; i++)
	{
		s1 = long_mul_base(s1, s2, 16);
		//if (i > 1)
		//	free (s1);
		//s1 = s3;
		printf("\t{%d, \"%s\"},\n", i, s1);
	}
	*/
	/*
	ret1 =    printf("|%d|\n", 0);
	ret2 = ft_printf("|%d|\n", 0);
	printf("Ret1 = %d Ret2 = %d\n", ret1, ret2);
	*/
	/*
	printf("|%D|\n", LONG_MIN);
	ft_printf("|%D|\n", LONG_MIN);
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
	return (0);
}
