/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolosov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:23:23 by nkolosov          #+#    #+#             */
/*   Updated: 2017/11/29 14:23:23 by nkolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_consts.h"
#include "libft.h"
#include "limits.h"

static char	*get_int_str(long double *num, size_t *stepen_dvoiki)
{
	uintmax_t	ts;
	char		*str;
	size_t		i;

	str = ft_strnew(100);
	*stepen_dvoiki = 0;
	while (*num > ULLONG_MAX)
	{
		*num /= 2.0;
		*stepen_dvoiki = *stepen_dvoiki + 1;
	}
	ts = (uintmax_t)*num;
	*num -= ts;
	i = 0;
	if (ts == 0)
		str[i++] = '0';
	else
		while (ts > 0)
		{
			str[i++] = ts % 2 + '0';
			ts /= 2;
		}
	rev_str(str, &str[i - 1]);
	return (str);
}

static char	*get_frac_str(long double num_frac)
{
	static t_str	*str;
	size_t			i;

	str = str ? str : init_t_str(1000);
	str->size = 0;
	i = -1;
	while (++i < 1001 && num_frac > 0.0)
	{
		num_frac *= 2.0;
		str->str[str->size++] = num_frac >= 1.0 ? '1' : '0';
		if (num_frac >= 1.0)
			num_frac -= 1.0;
	}
	str->str[str->size] = '\0';
	return (str->str);
}

char		hex_from_dec(char *buf, _Bool is_cap)
{
	size_t	num;
	char	c;

	num = (buf[3] - '0') + (buf[2] - '0') * 2 +
			(buf[1] - '0') * 4 + (buf[0] - '0') * 8;
	if (num < 10)
		c = num + '0';
	else
	{
		num -= 10;
		if (is_cap)
			c = num + 'A';
		else
			c = num + 'a';
	}
	return (c);
}

void		float_to_binary(t_float *f, long double num, _Bool is_cap)
{
	char	*s1;
	char	*s2;
	size_t	two_pow;
	size_t	i;
	size_t	j;
	size_t	slen;
	char	buf[4];
	char	c;

	s1 = get_int_str(&num, &two_pow);
	s2 = get_frac_str(num);
	slen = ft_strlen(s1);
	if (slen == 1 && s1[0] == '0')
	{
		i = -1;
		while (s2[++i])
			if (s2[i] != '0')
			{
				f->expon = i;
				break ;
			}
		if (!s2[i])
		{
			f->size = 1;
			f->num[0] = '0';
			f->expon = 0;
			return ;
		}
	}
	else
		f->expon = slen + two_pow - 1;
	f->size = 0;
	f->num[f->size++] = s1[0];
	i = 1;
	while (i + 3 < slen)
	{
		buf[0] = s1[i];
		buf[1] = s1[i + 1];
		buf[2] = s1[i + 2];
		buf[3] = s1[i + 3];
		f->num[f->size++] = hex_from_dec(buf, is_cap);
		i += 4;
	}
	if (f->size != 0)
	{
		j = 0;
		while (i < slen)
			buf[j++] = s1[i++];
		i = 0;
		slen = ft_strlen(s2);
		while (j < 4 && i < slen)
			buf[j++] = s2[i++];
		f->num[f->size++] = hex_from_dec(buf, is_cap);
	}
	while (i + 3 < slen)
	{
		buf[0] = s2[i];
		buf[1] = s2[i + 1];
		buf[2] = s2[i + 2];
		buf[3] = s2[i + 3];
		c = hex_from_dec(buf, is_cap);
		if (!(c == '0' && f->size == 0))
			f->num[f->size++] = c;
		i += 4;
	}
	j = 0;
	while (i < slen)
		buf[j++] = s1[i++];
	while (j > 0 && j < 4)
		buf[j++] = '0';
	f->num[f->size++] = hex_from_dec(buf, is_cap);
}


void		print_a_exp(t_params *p, int expon, char c)
{
	size_t			savelen_exp;

	print_symbol(p, c);
	print_symbol(p, expon < 0 ? '-' : '+');
	expon = expon < 0 ? -expon : expon;
	if (expon == 0)
		print_str(p, "0", 1);
	else
	{
		savelen_exp = p->toprint->len;
		while (expon > 0)
		{
			print_symbol(p, '0' + expon % 10);
			expon /= 10;
		}
		rev_str(&p->toprint->str[savelen_exp],
			&p->toprint->str[p->toprint->len - 1]);
	}
}

void		type_aba(va_list *ap, t_params *p, char *c, _Bool is_cap)
{
	long double		num;
	size_t			i;
	static t_float	*f = NULL;

	num = get_float_num(ap, p, is_cap);
	if (num < 0.0)
		return ;
	f = !f ? init_t_float(FLOAT_A_STR_MAX_SIZE) : f;
	float_to_binary(f, num, is_cap);
	while (f->num[f->size - 1] == '0' && f->size > 1)
		f->size--;
	p->precision = p->precision == -1 && f->num[0] != '0' ? f->size : p->precision;
	//printf("precision %d\n", p->precision);
	//while (f->num[f->size - 1] == '0' && f->size > 1)
	//	f->size--;
	f->point = 1;

	p->pref_len = p->isnegative || p->flags->plus || p->flags->space ? 1 : 0;
	print_sign_pref(p);
	print_symbol(p, '0');
	print_symbol(p, c[0]);
	print_symbol(p, f->num[0]);
	p->precision -= f->num[0] == '0' ? 0 : 1;
	if (f->size > 1 || p->precision > 0 || p->flags->hash)
		print_symbol(p, '.');
	i = 0;
	//printf("%zu %zu %d\n", i + 1, f->size, p->precision);
	while (++i < f->size && p->precision-- > 0)
		print_symbol(p, f->num[i]);
	while (p->precision-- > 0)
		print_symbol(p, '0');
	print_a_exp(p, f->expon, c[1]);
	float_flags(p);
}
