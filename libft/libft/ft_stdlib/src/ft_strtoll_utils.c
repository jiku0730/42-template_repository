/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:46 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 19:32:38 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

int	ft_isspace_utils(const char p)
{
	if (p == ' ' || p == '\t' || p == '\n' || p == '\v' || p == '\f'
		|| p == '\r')
		return (1);
	return (0);
}

int	char_to_digit_utils(const char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 10);
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

char	*handle_base_prefix(char *s, int *base)
{
	if (*base == 0)
	{
		if (*s == '0')
		{
			if (s[1] == 'x' || s[1] == 'X')
			{
				*base = 16;
				s += 2;
			}
			else
			{
				*base = 8;
				s++;
			}
		}
		else
			*base = 10;
	}
	else if (*base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X'))
		s += 2;
	return (s);
}

char	*preprocess_input(const char *nptr, int *negative, int *base)
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
	return (s);
}

int	check_overflow(unsigned long long acc, int digit, int base)
{
	unsigned long long	cutoff;
	unsigned int		cutlim;

	cutoff = (unsigned long long)(LLONG_MAX) / (unsigned long long)base;
	cutlim = (unsigned)(LLONG_MAX) % (unsigned)base;
	if (acc > cutoff || (acc == cutoff && (unsigned)digit > cutlim))
		return (1);
	return (0);
}
