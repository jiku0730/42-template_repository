/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:57:28 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 09:26:57 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			s_length;
	char			*rtv_str;

	if (!s || !f)
		return (NULL);
	index = 0;
	s_length = ft_strlen(s);
	rtv_str = malloc(sizeof(char) * (s_length + 1));
	if (!rtv_str)
		return (NULL);
	while (s[index])
	{
		rtv_str[index] = (*f)(index, s[index]);
		index++;
	}
	rtv_str[index] = '\0';
	return (rtv_str);
}

// #include <stdio.h>

// char	convert_to_upper(unsigned int index, char c)
// {
// 	(void)index;
// 	if ('a' <= c && c <= 'z')
// 		return (c - 'a' + 'A');
// 	return (c);
// }

// int main(void)
// {
// 	char *str = "42Tokyo";
// 	printf("%zu\n", ft_strlen_(str));

// 	char *convert_str = ft_strmapi(str, convert_to_upper);
// 	printf("%s\n", convert_str);
// 	free(convert_str);
// 	return (0);
// }
