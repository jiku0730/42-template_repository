/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:45:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_output_percentage(int fd, t_conv_spec *ci)
{
	size_t	pad;
	char	*s;

	if (ci->flags->sharp || ci->flags->space || ci->flags->plus
		|| ci->precision != -1)
		return (ci->validation = -1, (void)0);
	s = ci->output_str;
	if (ci->field_width > 1)
	{
		pad = ci->field_width - 1;
		if (ci->flags->minus)
			s = pad_right(s, pad, ' ');
		else if (ci->flags->zero)
			s = pad_left(s, pad, '0');
		else
			s = pad_left(s, pad, ' ');
		ci->output_str = s;
		ci->output_length = ft_strlen_printf(s);
	}
	write(fd, s, ci->output_length);
}
