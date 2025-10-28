/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:25:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:15:59 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include <errno.h>
#include <limits.h>

static int	validate_base_ull(int base, char **endptr, const char *nptr)
{
	if (base < 0 || base == 1 || base > 36)
	{
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	return (1);
}

static int	handle_empty_string_ull(const char *s, char **endptr,
		const char *nptr)
{
	if (*s == '\0')
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	return (1);
}

static int	convert_digits_ull(const char **s, int base,
		unsigned long long *acc)
{
	unsigned long long	cutoff;
	unsigned int		cutlim;
	const char			*start;
	int					overflow;
	int					digit;

	cutoff = ULLONG_MAX / (unsigned long long)base;
	cutlim = ULLONG_MAX % (unsigned)base;
	*acc = 0;
	start = *s;
	overflow = 0;
	digit = char_to_digit_utils(**s);
	while (digit >= 0 && digit < base)
	{
		if (*acc > cutoff || (*acc == cutoff && (unsigned int)digit > cutlim))
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

static const char	*preprocess_input_ull(const char *nptr, int *negative,
		int *base)
{
	char	*s;

	s = (char *)nptr;
	*negative = 0;
	while (ft_isspace_utils(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*negative = 1;
		s++;
	}
	s = handle_base_prefix(s, base);
	return ((const char *)s);
}

unsigned long long	ft_strtoull(const char *nptr, char **endptr, int base)
{
	const char			*s;
	int					negative;
	unsigned long long	acc;
	int					overflow;

	if (!validate_base_ull(base, endptr, nptr))
		return (0);
	s = preprocess_input_ull(nptr, &negative, &base);
	if (!handle_empty_string_ull(s, endptr, nptr))
		return (0);
	overflow = convert_digits_ull(&s, base, &acc);
	if (overflow == -1)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	if (endptr)
		*endptr = (char *)s;
	if (negative)
		return ((unsigned long long)(-(long long)acc));
	if (overflow)
		return (ULLONG_MAX);
	return (acc);
}
