/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:59:43 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 21:01:31 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base)
{
	unsigned long	result;

	result = ft_strtoull(nptr, endptr, base);
	if (result > ULONG_MAX)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (ULONG_MAX);
	}
	return (result);
}
