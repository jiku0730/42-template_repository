/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:28:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 09:26:36 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// #include <stdio.h>

// #include <string.h>

// int	main(void)
// {
// 	char	str1[8] = "Tokyo";
// 	char	strs[10][20] = {"Hello","World1234567890", "42", "Tokyo", "24",
//			"Kyoto"};

// 	printf("%i\n", ft_strlcpy(str1, strs[1], 0));
// 	printf("%s\n", str1);
// 	printf("%i\n", str_len(strs[1]));

// 	return (0);
// }
