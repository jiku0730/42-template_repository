/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:22:54 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 09:27:10 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* Compare two strings up to n characters */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *str[] = {"Hello World 42 Tokyo!", "0123456789",
// 		"abcdefghijklmnopqrstuvwxyz", "01234556789"};
// 	printf("%i\n", ft_strncmp((const char *)str[1], (const char *)str[3], 7));
// 	printf("%i\n", ft_strncmp((const char *)str[1], (const char *)str[3], 7));
// 	printf("%i\n", ft_strncmp((const char *)str[1], (const char *)str[3], 7));
// 	printf("%i\n", ft_strncmp((const char *)str[1], (const char *)str[3], 7));
// 	printf("%i\n", ft_strncmp((const char *)str[1], (const char *)str[3], 7));

// 	return (0);
// }
