/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:32:42 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	put_prefix(t_conv_spec *conv_info, const char *prefix)
{
	char	*old;

	old = conv_info->output_str;
	conv_info->output_str = ft_strjoin_printf(prefix, old);
	free(old);
	conv_info->output_length += ft_strlen_printf(prefix);
}

void	apply_precision_zeros(t_conv_spec *conv_info)
{
	size_t	pad;

	pad = conv_info->precision - conv_info->output_length;
	conv_info->output_str = pad_left(conv_info->output_str, pad, '0');
	conv_info->output_length += pad;
}

static ssize_t	prefix_zero_body(t_conv_spec *ci, size_t pad)
{
	char	*old;
	char	*new;
	size_t	pre;

	old = ci->output_str;
	pre = 0;
	if (old[0] == '-' || old[0] == '+' || old[0] == ' ')
		pre = 1;
	else if (old[0] == '0' && (old[1] == 'x' || old[1] == 'X'))
		pre = 2;
	if (pre == 0)
		return (0);
	new = malloc(ci->output_length + pad + 1);
	if (!new)
		return (-1);
	ft_memcpy_printf(new, old, pre);
	ft_memset_printf(new + pre, '0', pad);
	ft_memcpy_printf(new + pre + pad, old + pre, ci->output_length - pre);
	new[ci->output_length + pad] = '\0';
	free(old);
	ci->output_str = new;
	ci->output_length += pad;
	return (1);
}

void	apply_field_width(t_conv_spec *ci)
{
	size_t	pad;
	ssize_t	ret;

	if (ci->field_width <= ci->output_length)
		return ;
	pad = ci->field_width - ci->output_length;
	if (!ci->flags->minus && ci->flags->zero && ci->precision == -1)
	{
		ret = prefix_zero_body(ci, pad);
		if (ret == -1)
			return (ci->validation = -1, (void)0);
		else if (ret == 1)
			return ;
		ci->output_str = pad_left(ci->output_str, pad, '0');
		ci->output_length += pad;
		return ;
	}
	else if (ci->flags->minus)
		ci->output_str = pad_right(ci->output_str, pad, ' ');
	else if (ci->flags->zero && ci->precision == -1)
		ci->output_str = pad_left(ci->output_str, pad, '0');
	else
		ci->output_str = pad_left(ci->output_str, pad, ' ');
	ci->output_length += pad;
}
