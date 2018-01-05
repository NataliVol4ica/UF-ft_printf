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
	fesetround(FE_UPWARD);
//	size_t	i;

	char *s1 = "1";
	char *s2 = "2";
	char *s3;
	
	printf("%s\n", long_mul("1048576", "1048576"));	
	/*
	for (int i = 1; i < 15001; i++)
	{
		s3 = long_mul_base(s1, s2, 16);
		if (i > 1)
			free (s1);
		s1 = s3;
		if (i == 1 || i == 2 || i == 5 || i == 10 || i == 25 || i == 50 ||
			i == 100 || i == 1000 || i == 2000 || i == 5000 || i == 10000 || i == 15000)
			printf("\t{%d, \"%s\"},\n", i, s1);

	}
	*/
	/*
	for (int i = 1; i < 15001; i++)
	{
		s1 = long_mul_base(s1, s2, 16);
		//if (i > 1)
		//	free (s1);
		//s1 = s3;
		printf("\t{%d, \"%s\"},\n", i, s1);
	}
	
	//printf("%s\n", long_mul_base("8", "2", 16));
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
