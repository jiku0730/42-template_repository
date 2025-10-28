/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:11:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static size_t	count_base_digit(unsigned long long ull_num, const char *base)
{
	size_t	count;
	size_t	base_len;

	count = 1;
	base_len = ft_strlen_printf(base);
	while (ull_num >= base_len)
	{
		ull_num /= base_len;
		count++;
	}
	return (count);
}

/* Convert the unsigned long long 'num'to a ASCII string */
static char	*ft_unsigned_lltoa_base(unsigned long long num, const char *base)
{
	char	*rtv_str;
	size_t	base_len;
	size_t	index;

	if (num == 0)
		return (ft_strdup_printf("0"));
	base_len = ft_strlen_printf(base);
	if (base_len < 1)
		return (NULL);
	index = count_base_digit(num, base);
	rtv_str = malloc(sizeof(char) * (index + 1));
	if (!rtv_str)
		return (NULL);
	rtv_str[index] = '\0';
	while (num != 0)
	{
		index--;
		rtv_str[index] = base[num % base_len];
		num /= base_len;
	}
	return (rtv_str);
}

void	ft_handle_hex_lower(t_conv_spec *conv_info, unsigned int u_num)
{
	char		*converted_u_num;
	const char	*base;

	base = "0123456789abcdef";
	converted_u_num = ft_unsigned_lltoa_base((unsigned long long)u_num, base);
	if (!converted_u_num)
		return (conv_info->validation = -1, (void)0);
	conv_info->output_str = converted_u_num;
	conv_info->output_length = ft_strlen_printf(converted_u_num);
}

void	ft_handle_hex_upper(t_conv_spec *conv_info, unsigned int u_num)
{
	char		*converted_u_num;
	const char	*base;

	base = "0123456789ABCDEF";
	converted_u_num = ft_unsigned_lltoa_base((unsigned long long)u_num, base);
	if (!converted_u_num)
		return (conv_info->validation = -1, (void)0);
	conv_info->output_str = converted_u_num;
	conv_info->output_length = ft_strlen_printf(converted_u_num);
}
// #include <stdio.h>

// int main(void)
// {
// 	char	*ptr = malloc(1);
// 	printf("%s", ft_ptoa(ptr));
// 	return (0);
// }
