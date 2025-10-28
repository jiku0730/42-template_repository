/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:18:13 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_output_str(int fd, t_conv_spec *conv_info)
{
	t_flags	*flags;

	flags = conv_info->flags;
	if (flags->sharp == 1)
		return (conv_info->validation = -1, (void)0);
	ft_output_field_width(fd, conv_info);
}
