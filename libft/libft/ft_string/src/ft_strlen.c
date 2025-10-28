/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:06:53 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 09:26:47 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (s[length])
		length++;
	return (length);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *strs[] = {"Hello World 42 Tokyo!", "1234567890",
// 					"abcdefghijklmnopqrstuvwxyz"};
// 	for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
// 	{
// 		printf("%10s : %zu\n", strs[i], ft_strlen((const char *)strs[i]));
// 	}
// 	return (0);
// }
