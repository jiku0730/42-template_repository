/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_info_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:25:15 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
}

t_conv_spec	*conv_info_init(void)
{
	t_conv_spec	*conv_info;

	conv_info = malloc(sizeof(t_conv_spec));
	if (!conv_info)
		return (NULL);
	conv_info->flags = malloc(sizeof(t_flags));
	if (!conv_info->flags)
		return (free(conv_info), NULL);
	ft_init_flags(conv_info->flags);
	conv_info->field_width = 0;
	conv_info->precision = -1;
	conv_info->specifier = '\0';
	conv_info->output_str = NULL;
	conv_info->output_length = 0;
	conv_info->validation = 0;
	return (conv_info);
}
