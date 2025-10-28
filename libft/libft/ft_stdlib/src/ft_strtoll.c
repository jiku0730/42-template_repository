/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:30:50 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 19:51:55 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>

int	convert_digits(const char **s, int base, unsigned long long *acc)
{
	const char	*start;
	int			overflow;
	int			digit;

	*acc = 0;
	start = *s;
	overflow = 0;
	digit = char_to_digit_utils(**s);
	while (digit >= 0 && digit < base)
	{
		if (check_overflow(*acc, digit, base))
			overflow = 1;
		else
			*acc = *acc * base + digit;
		(*s)++;
		digit = char_to_digit_utils(**s);
	}
	if (*s == start)
		return (-1);
	return (overflow);
}

static int	validate_base(int base, char **endptr, const char *nptr)
{
	if (base < 0 || base == 1 || base > 36)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	return (1);
}

static int	handle_empty_string(const char *s, char **endptr, const char *nptr)
{
	if (*s == '\0')
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	return (1);
}

long long	finalize_result(unsigned long long acc, int negative, int overflow)
{
	if (overflow)
	{
		if (negative)
			return (LLONG_MIN);
		return (LLONG_MAX);
	}
	if (negative)
		return (-(long long)acc);
	return ((long long)acc);
}

long long	ft_strtoll(const char *nptr, char **endptr, int base)
{
	const char			*s;
	int					negative;
	unsigned long long	acc;
	int					overflow;

	if (!validate_base(base, endptr, nptr))
		return (0);
	s = preprocess_input(nptr, &negative, &base);
	if (!handle_empty_string(s, endptr, nptr))
		return (0);
	overflow = convert_digits(&s, base, &acc);
	if (overflow == -1)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	if (endptr)
		*endptr = (char *)s;
	return (finalize_result(acc, negative, overflow));
}
