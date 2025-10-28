/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:11:21 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_handle_str(t_conv_spec *ci, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (ci->precision >= 0 && ci->precision < (ssize_t)ft_strlen_printf(str))
		ci->output_str = ft_substr_printf(str, 0, ci->precision);
	else
		ci->output_str = ft_strdup_printf(str);
	if (!ci->output_str)
		return (ci->validation = -1, (void)0);
	ci->output_length = ft_strlen_printf(ci->output_str);
}
