/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:11:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/* Convert the unsigned integer 'n'to a ASCII string */
static size_t	count_digit(unsigned int number)
{
	size_t	count;

	count = 1;
	while (number >= 10)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*dest_str;
	size_t	rtv_length;

	if (n == 0)
		return (ft_strdup_printf("0"));
	rtv_length = count_digit(n);
	dest_str = malloc(sizeof(char) * (rtv_length + 1));
	if (!dest_str)
		return (NULL);
	dest_str[rtv_length] = '\0';
	while (n != 0)
	{
		rtv_length--;
		dest_str[rtv_length] = n % 10 + '0';
		n /= 10;
	}
	return (dest_str);
}

void	ft_handle_int_u(t_conv_spec *conv_info, unsigned int u_num)
{
	char	*str;

	str = ft_uitoa(u_num);
	if (!str)
		return (conv_info->validation = -1, (void)0);
	conv_info->output_str = str;
	conv_info->output_length = ft_strlen_printf(str);
}
