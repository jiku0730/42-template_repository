/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:00:01 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/13 20:48:25 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

char	*ft_rindex(const char *s, int c)
{
	const char	*last;
	char		target;

	if (s == NULL)
		return (NULL);
	target = (char)c;
	last = NULL;
	while (*s)
	{
		if (*s == target)
			last = s;
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return ((char *)last);
}
