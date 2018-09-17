/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utf8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 08:55:26 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:04:11 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

/*
** To utf-8 format; raw, no checks, can get bigger
** than the standard 4 bytes; will fail should
** wchar_t be more than
** (CHAR_BIT - 1) * (CHAR_BIT - 2) bits large.
*/

int				utf8_seq(
	wchar_t val,
	int char_lim,
	char *put)
{
	int						sz;
	unsigned char			c;
	unsigned char			cs[CHAR_BIT];
	unsigned char *const	pc = cs + CHAR_HBIT;

	sz = 0;
	if (val & ~((wchar_t)((c = val) & ~ASCII_MASK)))
	{
		while (val && sz < CHAR_HBIT)
		{
			pc[-sz++] = UTF8_10X | (val & ~UTF8_BMASK);
			val >>= UTF8_BITS;
		}
		c = pc[-(sz - 1)];
		if (my_flog2(c & ~UTF8_10X) + sz + 2 > CHAR_BIT)
			c = ~0 << (CHAR_BIT - (sz + 1));
		else
			c |= ~0 << (CHAR_BIT - sz--);
	}
	pc[-sz++] = c;
	if ((sz = sz <= char_lim ? sz : 0))
		ft_memcpy(put, pc - sz + 1, sz);
	return (sz);
}

int				utf8_trueseq(
	wchar_t val,
	char *put)
{
	return (utf8_seq(val, UTF8_MAX_CHARS, put));
}

size_t			utf8_strtoseq(
	wchar_t *str,
	char *put,
	size_t len)
{
	char *const	lim = put + len - UTF8_MAX_CHARS;
	char *const	save = put;

	if (!(str && *str))
		return (0);
	while (*str && put < lim)
		put += utf8_trueseq(*str++, put);
	return (put - save);
}
