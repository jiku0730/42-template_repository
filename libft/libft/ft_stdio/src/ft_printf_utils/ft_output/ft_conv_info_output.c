/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_info_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:15:57 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

char	*pad_left(char *str, size_t pad_count, char pad_char)
{
	size_t	orig_len;
	size_t	new_len;
	char	*res;

	orig_len = ft_strlen_printf(str);
	new_len = orig_len + pad_count;
	res = malloc(new_len + 1);
	if (!res)
		return (free(str), NULL);
	ft_memset_printf(res, pad_char, pad_count);
	ft_memcpy_printf(res + pad_count, str, orig_len);
	res[new_len] = '\0';
	free(str);
	return (res);
}

char	*pad_right(char *str, size_t pad_count, char pad_char)
{
	size_t	orig_len;
	size_t	new_len;
	char	*res;

	orig_len = ft_strlen_printf(str);
	new_len = orig_len + pad_count;
	res = malloc(new_len + 1);
	if (!res)
		return (free(str), NULL);
	ft_memcpy_printf(res, str, orig_len);
	ft_memset_printf(res + orig_len, pad_char, pad_count);
	res[new_len] = '\0';
	free(str);
	return (res);
}

static void	put_padding(int fd, size_t pad)
{
	char	st_buf[256];
	char	*buf;

	if (pad == 0)
		return ;
	if (pad <= sizeof(st_buf))
	{
		ft_memset_printf(st_buf, ' ', pad);
		write(fd, st_buf, pad);
		return ;
	}
	buf = malloc(sizeof(char) * pad);
	if (!buf)
		return ;
	ft_memset_printf(buf, ' ', pad);
	write(fd, buf, pad);
	free(buf);
}

void	ft_output_field_width(int fd, t_conv_spec *conv_info)
{
	t_flags	*flg;
	size_t	pad;

	flg = conv_info->flags;
	pad = 0;
	if (conv_info->field_width > conv_info->output_length)
		pad = conv_info->field_width - conv_info->output_length;
	if (!flg->minus)
		put_padding(1, pad);
	write(fd, conv_info->output_str, conv_info->output_length);
	if (flg->minus)
		put_padding(1, pad);
	conv_info->output_length += pad;
}

void	conv_info_output(int fd, t_conv_spec *conv_info)
{
	if (conv_info->specifier == 'c')
		ft_output_char(fd, conv_info);
	else if (conv_info->specifier == 's')
		ft_output_str(fd, conv_info);
	else if (conv_info->specifier == 'p')
		ft_output_ptr(fd, conv_info);
	else if (conv_info->specifier == 'd' || conv_info->specifier == 'i')
		ft_output_int(fd, conv_info);
	else if (conv_info->specifier == 'u')
		ft_output_int_u(fd, conv_info);
	else if (conv_info->specifier == 'x')
		ft_output_hex_lower(fd, conv_info);
	else if (conv_info->specifier == 'X')
		ft_output_hex_upper(fd, conv_info);
	else if (conv_info->specifier == '%')
		ft_output_percentage(fd, conv_info);
}
