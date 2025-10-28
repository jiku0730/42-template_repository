/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:25:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

void	set_specifier(char **str, t_conv_spec *conv_info)
{
	if (is_specifier(**str))
	{
		if (**str == 'c')
			conv_info->specifier = 'c';
		if (**str == 's')
			conv_info->specifier = 's';
		if (**str == 'p')
			conv_info->specifier = 'p';
		if (**str == 'd')
			conv_info->specifier = 'd';
		if (**str == 'i')
			conv_info->specifier = 'i';
		if (**str == 'u')
			conv_info->specifier = 'u';
		if (**str == 'x')
			conv_info->specifier = 'x';
		if (**str == 'X')
			conv_info->specifier = 'X';
		if (**str == '%')
			conv_info->specifier = '%';
		(*str)++;
	}
}
