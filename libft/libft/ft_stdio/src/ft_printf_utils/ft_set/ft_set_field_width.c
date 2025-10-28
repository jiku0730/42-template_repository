/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_field_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:18:21 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static size_t	ft_atoi_adr(char **str)
{
	size_t	rtv_num;

	rtv_num = 0;
	while (ft_isdigit(**str))
	{
		rtv_num = rtv_num * 10 + **str - '0';
		(*str)++;
	}
	return (rtv_num);
}

void	set_field_width(char **str, t_conv_spec *conv_info)
{
	conv_info->field_width = ft_atoi_adr(str);
}
