/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:11:25 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	ft_output_hex_common(int fd, t_conv_spec *ci, const char *prefix)
{
	char	*s;

	s = ci->output_str;
	if (ci->flags->plus || ci->flags->space)
		return (ci->validation = -1, (void)0);
	if (*s == '0' && ci->precision == 0)
	{
		s[0] = '\0';
		ci->output_length = 0;
	}
	if (ci->precision > (int)ci->output_length)
		apply_precision_zeros(ci);
	if (ci->flags->sharp && !(ci->output_length == 1
			&& ci->output_str[0] == '0'))
		put_prefix(ci, prefix);
	if (ci->field_width > ci->output_length)
		apply_field_width(ci);
	write(fd, ci->output_str, ci->output_length);
}

void	ft_output_hex_lower(int fd, t_conv_spec *ci)
{
	ft_output_hex_common(fd, ci, "0x");
}

void	ft_output_hex_upper(int fd, t_conv_spec *ci)
{
	ft_output_hex_common(fd, ci, "0X");
}
