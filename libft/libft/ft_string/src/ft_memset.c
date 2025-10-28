/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:36:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 09:25:12 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* Undefined if s == NULL && n > 0. */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*uc_dst;

	if (!n)
		return (s);
	uc_dst = (unsigned char *)s;
	while (n--)
		*uc_dst++ = (unsigned char)c;
	return (s);
}

// #include <string.h>
// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	char str[50] = "Hello World 42 Tokyo!";
// 	printf("First string：%s\n", str);

// 	ft_memset(str + 2, '-', 2);
// 	memset(str + 4, '*', 2);
// 	printf("%s\n", str);
// 	return (0);
// }
