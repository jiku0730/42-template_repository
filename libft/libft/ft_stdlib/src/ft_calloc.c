/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:26:53 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 17:00:07 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (s == NULL)
		return ;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total_size;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > __SIZE_MAX__ / size)
		return (NULL);
	total_size = count * size;
	p = malloc(total_size);
	if (!p)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int		*p;
// 	char	*str[10];

// 	p = (int *)ft_calloc(10, sizeof(int));
// 	for (size_t i = 0; i < 10; i++)
// 	{
// 		printf("%d\n", p[i]);
// 	}
// 	printf("\n");
// 	str = (char **)ft_calloc(10, sizeof(char *));
// 	for (size_t i = 0; i < 10; i++)
// 	{
// 		str[i] = "0123456789";
// 		printf("%s\n", str[i]);
// 	}
// 	free(p);
// 	free(str);
// 	return (0);
// }
// // % gcc -fsanitize=address -g ft_calloc.c ft_bzero.c -o test_calloc
// // gcc -g ft_calloc.c ft_bzero.c -o test_calloc_valgrind  # ASanなしでコンパイル
// // valgrind --leak-check=full --track-origins=yes ./test_calloc_valgrind
// gcc -Wall -Wextra -Werror -Wpedantic -Wconversion -Wshadow -Wundef
// -Wcast-align -Wwrite-strings -Wformat=2
// -g ft_calloc.c ft_bzero.c -o test_calloc_debug
