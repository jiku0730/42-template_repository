/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:31:10 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 09:31:16 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*original_dst;

	if (dst == NULL || src == NULL)
		return (dst);
	original_dst = dst;
	while (*dst)
		dst++;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (original_dst);
}
