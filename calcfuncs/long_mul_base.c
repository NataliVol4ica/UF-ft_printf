/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_mul_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:04:25 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 11:26:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define num_from_char(x) x >= '0' && x <= '9' ? x - '0' : x - 'a' + 10
#define char_from_num(x) x <= 9 ? x + '0' : x - 10 + 'a'

#include <stdio.h>

void	print_ln(t_str *str)
{
	size_t	i;

	i = -1;
	while (++i < str->size)
		printf("%d|", str->str[i]);
	printf("\n");
}

static t_str	*insert_num(t_str *s, char num)
{
	t_str	*ans;
	size_t	i;

	ans = (t_str*)malloc(sizeof(t_str));
	ans->str = ft_strnew(s->size + 1);
	ans->size = s->size + 1;
	i = -1;
	while (++i < s->size)
		ans->str[i] = s->str[i];
	ans->str[s->size] = num;
	//printf("inc str by %d\n", num);
	//print_ln(ans);
	free(s->str);
	free(s);
	return (ans);
}

static t_str	*long_sum(t_str *s1, t_str *s2, size_t base)
{
	t_str	*ans;
	t_str	*s;
	t_str	*p1;
	t_str	*p2;
	int		buf;
	size_t	i;

	//printf("Summing s1len %zu s2len %zu\n", s1->size, s2->size);
	//print_ln(s1);
	//print_ln(s2);
	p1 = s1->size > s2->size ? s1 : s2;
	p2 = p1 == s1 ? s2 : s1;

	ans = (t_str*)malloc(sizeof(t_str));
	ans->str = ft_strnew(p1->size);
	ans->size = p1->size;
	i = -1;
	while (++i < p1->size)
		ans->str[i] = p1->str[i];
//	printf("s1 "); print_ln(ans);

	s = (t_str*)malloc(sizeof(t_str));
	s->str = ft_strnew(p1->size);
	s->size = p1->size;
	i = -1;
	while (++i < p2->size)
		s->str[i] = p2->str[i];

//	printf("s2 "); print_ln(s);

	i = -1;
	buf = 0;
	while (++i < ans->size)
	{
		buf = i < s->size ? ans->str[i] + s->str[i] + buf : ans->str[i] + buf;
		ans->str[i] = buf % base;
		buf = buf / base;
	}
	if (buf != 0)
		ans = insert_num(ans, buf);
	free(s1->str);
	free(s1);
	free(s2->str);
	free(s2);
	free(s->str);
	free(s);
	return (ans);
}

static t_str	*mul_base(t_str *s, int tens)
{
	t_str	*ans;
	size_t	i;

	if (tens <= 0)
		return (s);
	ans = (t_str*)malloc(sizeof(t_str));
	ans->str = ft_strnew(s->size + tens);
	ans->size = s->size + tens;
	i = -1;
	while (++i < s->size)
		ans->str[tens + i] = s->str[i];
	free(s->str);
	free(s);
	return (ans);
}

static t_str	*mul_num(t_str *s, int m, size_t base)
{
	t_str	*ans;
	int		buf;
	size_t	i;

	ans = (t_str*)malloc(sizeof(t_str));
	ans->str = ft_strnew(s->size);
	ans->size = s->size;
	i = -1;
	while (++i < ans->size)
		ans->str[i] = s->str[i];
	//print_ln(ans);
	i = -1;
	buf = 0;
	while (++i < ans->size)
	{
		buf = ans->str[i] * m + buf;
		//printf("buf %d\n", buf);
		ans->str[i] = buf % base;
		buf = buf / base;
	}
	//printf("buf %d\n", buf);
	if (buf != 0)
		ans = insert_num(ans, buf);
	return (ans);
}

char		*long_mul_base(char *ss1, char *ss2, size_t base)
{
	t_str	*s1;
	t_str	*s2;
	t_str	*ans;
	t_str	*temp;
	size_t	i;
	char	c;
	char	*ret;
	
	if (!ss1)
		return (ft_strdup(ss2));
	if (!ss2)
		return (ft_strdup(ss1));
	
	s1 = (t_str*)malloc(sizeof(t_str));
	s2 = (t_str*)malloc(sizeof(t_str));
	ans = (t_str*)malloc(sizeof(t_str));

	s1->str = ft_strrev(ft_strdup(ss1));
	s1->size = ft_strlen(ss1);
	s2->str = ft_strrev(ft_strdup(ss2));
	s2->size = ft_strlen(ss2);

	i = -1;
	while (++i < s1->size)
		s1->str[i] = num_from_char(s1->str[i]);
	i = -1;
	while (++i < s2->size)
		s2->str[i] = num_from_char(s2->str[i]);
//	print_ln(s1);
//	print_ln(s2);
	i = -1;
	ans->str = ft_strnew(0);
	ans->size = 0;
	while (++i < s2->size)
	{
	//	printf("Muling %d\n", s2->str[i]);
	//	print_ln(s1);
		temp = mul_num(s1, s2->str[i], base);
	//	printf("temp1 "); print_ln(temp);
		temp = mul_base(temp, i);
	//	printf("temp2 "); print_ln(temp);
		ans = long_sum(ans, temp, base);
	//	printf("ans "); print_ln(temp);
	}
	i = -1;
	while (++i < ans->size / 2) //rev
	{
		c = ans->str[i];
		ans->str[i] = ans->str[ans->size - i - 1];
		ans->str[ans->size - i - 1] = c;
	}
	free(s1->str);
	free(s2->str);
	i = -1;
	while (++i < ans->size)
		ans->str[i] = char_from_num(ans->str[i]);
	ret = ans->str;
	free(s1);
	free(s2);
	free(ans);
	return (ret);
}
