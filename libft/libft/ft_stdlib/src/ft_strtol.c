/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:10:27 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 20:12:08 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long long	result;

	result = ft_strtoll(nptr, endptr, base);
	if (result > LONG_MAX)
	{
		return (LONG_MAX);
	}
	if (result < LONG_MIN)
	{
		return (LONG_MIN);
	}
	return ((long)result);
}
