/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:11:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/* Convert the unsigned integer 'n'to a ASCII string */
static size_t	count_hex_digit(unsigned long long ull_num)
{
	size_t	count;

	count = 1;
	while (ull_num >= 16)
	{
		ull_num /= 16;
		count++;
	}
	return (count);
}

static char	*ft_ptoa(void *ptr)
{
	char				*rtv_str;
	unsigned long long	casted_ptr;
	size_t				i;

	if (!ptr)
		return (ft_strdup_printf("(nil)"));
	casted_ptr = (unsigned long long)ptr;
	i = count_hex_digit(casted_ptr);
	rtv_str = malloc(sizeof(char) * (2 + i + 1));
	if (!rtv_str)
		return (NULL);
	rtv_str[0] = '0';
	rtv_str[1] = 'x';
	while (i--)
	{
		rtv_str[2 + i] = "0123456789abcdef"[casted_ptr % 16];
		casted_ptr /= 16;
	}
	rtv_str[2 + count_hex_digit((unsigned long long)ptr)] = '\0';
	return (rtv_str);
}

void	ft_handle_ptr(t_conv_spec *conv_info, void *ptr)
{
	char	*converted_ptr;

	converted_ptr = ft_ptoa(ptr);
	if (!converted_ptr)
		return (conv_info->validation = -1, (void)0);
	conv_info->output_str = converted_ptr;
	conv_info->output_length = ft_strlen_printf(converted_ptr);
}
