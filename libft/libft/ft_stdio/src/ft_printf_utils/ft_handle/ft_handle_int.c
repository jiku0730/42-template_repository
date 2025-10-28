/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:11:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/* Convert the integer 'n'to a ASCII string */
static int	number_len_(int number)
{
	int	number_len;

	number_len = 1;
	if (number == INT_MIN)
	{
		return (11);
	}
	if (number < 0)
	{
		number *= -1;
		number_len++;
	}
	while (number >= 10)
	{
		number /= 10;
		number_len++;
	}
	return (number_len);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_itoa(int n)
{
	char	*dest_str;
	int		i;

	dest_str = malloc(sizeof(char) * (number_len_(n) + 1));
	if (!dest_str)
		return (NULL);
	if (n == -2147483648)
	{
		return (ft_strcpy(dest_str, "-2147483648"));
	}
	i = number_len_(n) - 1;
	if (n < 0)
	{
		dest_str[0] = '-';
		n *= -1;
	}
	dest_str[i + 1] = '\0';
	while (n >= 10)
	{
		dest_str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	dest_str[i] = n % 10 + '0';
	return (dest_str);
}

void	ft_handle_int(t_conv_spec *conv_info, int num)
{
	char	*str;

	str = ft_itoa(num);
	if (!str)
		return (conv_info->validation = -1, (void)0);
	conv_info->output_str = str;
	conv_info->output_length = ft_strlen_printf(str);
}
