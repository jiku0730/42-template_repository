/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:33:31 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_output_signed_common(int fd, t_conv_spec *ci, char *sign_char)
{
	char	*s;

	s = ci->output_str;
	if (*s == '0' && ci->precision == 0)
	{
		s[0] = '\0';
		ci->output_length = 0;
	}
	if (ci->precision > (ssize_t)ci->output_length)
		apply_precision_zeros(ci);
	if (*sign_char)
		put_prefix(ci, sign_char);
	if (ci->field_width > ci->output_length)
		apply_field_width(ci);
	write(fd, ci->output_str, ci->output_length);
}

void	ft_output_int(int fd, t_conv_spec *ci)
{
	char	sign_char[2];
	char	*tmp;

	sign_char[0] = '\0';
	sign_char[1] = '\0';
	if (ci->flags->sharp)
		return (ci->validation = -1, (void)0);
	if (ci->output_str[0] == '-')
	{
		sign_char[0] = '-';
		tmp = ci->output_str;
		ci->output_str = ft_strdup_printf(tmp + 1);
		free(tmp);
		ci->output_length = ft_strlen_printf(ci->output_str);
	}
	else if (ci->flags->plus)
		sign_char[0] = '+';
	else if (ci->flags->space)
		sign_char[0] = ' ';
	ft_output_signed_common(fd, ci, sign_char);
}

void	ft_output_int_u(int fd, t_conv_spec *ci)
{
	ft_output_signed_common(fd, ci, "\0");
}
