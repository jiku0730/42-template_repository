/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:37:20 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 12:38:32 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*original_dst;

	if (dst == NULL || src == NULL)
		return (NULL);
	original_dst = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (original_dst);
}

static char	*ft_strcat(char *dst, const char *src)
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

char	*ft_strjoin_printf(char const *s1, char const *s2)
{
	char	*dest;
	size_t	sum_len;

	if (!s1 || !s2)
		return (NULL);
	sum_len = ft_strlen_printf(s1) + ft_strlen_printf(s2);
	dest = malloc(sizeof(char) * (sum_len + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
