/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:12:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 11:56:43 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	is_flag(char c)
{
	return (c == '#' || c == ' ' || c == '+' || c == '-' || c == '0');
}

void	set_flags(char **str, t_flags *flags)
{
	while (is_flag(**str))
	{
		if (**str == '-')
			flags->minus = 1;
		if (**str == '0')
			flags->zero = 1;
		if (**str == '#')
			flags->sharp = 1;
		if (**str == ' ')
			flags->space = 1;
		if (**str == '+')
			flags->plus = 1;
		(*str)++;
	}
}
