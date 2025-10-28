/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:34:39 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 12:34:40 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

static int	cleanup_conv_info(t_conv_spec *conv_info)
{
	if (!conv_info)
		return (-1);
	if (conv_info)
	{
		free(conv_info->output_str);
		free(conv_info->flags);
		free(conv_info);
	}
	return (-1);
}

static int	conversion_information(int fd, const char **format, va_list *args)
{
	t_conv_spec	*conv_info;
	int			rtv;

	(*format)++;
	conv_info = conv_info_init();
	if (!conv_info)
		return (-1);
	conv_info_set((char **)format, conv_info);
	if (conv_info->validation == -1)
		return (cleanup_conv_info(conv_info));
	conv_info_handle(conv_info, *args);
	if (conv_info->validation == -1)
		return (cleanup_conv_info(conv_info));
	conv_info_output(fd, conv_info);
	if (conv_info->validation == -1)
		return (cleanup_conv_info(conv_info));
	rtv = conv_info->output_length;
	cleanup_conv_info(conv_info);
	return (rtv);
}

int	ft_vdprintf(int fd, const char *format, va_list *ap)
{
	ssize_t	rtv_str_length;
	ssize_t	tmp;

	if (!format)
		return (-1);
	rtv_str_length = 0;
	while (*format)
	{
		if (*format != '%')
		{
			tmp = write(fd, format++, 1);
			if (tmp == -1)
				return (va_end(*ap), -1);
		}
		else if (*format == '%')
		{
			tmp = conversion_information(fd, &format, ap);
			if (tmp == -1)
				return (va_end(*ap), -1);
		}
		rtv_str_length += tmp;
	}
	return (va_end(*ap), (int)rtv_str_length);
}
