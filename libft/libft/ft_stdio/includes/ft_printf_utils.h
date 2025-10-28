/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:44:24 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 12:23:06 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FD_PRINTF_UTILS_H
# define FD_PRINTF_UTILS_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	ssize_t	minus;
	ssize_t	zero;
	ssize_t	sharp;
	ssize_t	space;
	ssize_t	plus;
}			t_flags;

typedef struct s_conv_spec
{
	t_flags	*flags;
	size_t	field_width;
	ssize_t	precision;
	char	specifier;
	ssize_t	validation;
	size_t	output_length;
	char	*output_str;
}			t_conv_spec;

t_conv_spec	*conv_info_init(void);

/* ft_set */
void		conv_info_set(char **str, t_conv_spec *conv_info);
void		set_flags(char **str, t_flags *flags);
void		set_field_width(char **str, t_conv_spec *conv_info);
void		set_precision(char **str, t_conv_spec *conv_info);
void		set_specifier(char **str, t_conv_spec *conv_info);

/* ft_handle */
void		conv_info_handle(t_conv_spec *conv_info, va_list args);
void		ft_handle_char(t_conv_spec *conv_info, int c);
void		ft_handle_str(t_conv_spec *conv_info, char *str);
void		ft_handle_ptr(t_conv_spec *conv_info, void *ptr);
void		ft_handle_int(t_conv_spec *conv_info, int num);
void		ft_handle_int_u(t_conv_spec *conv_info, unsigned int u_num);
void		ft_handle_hex_lower(t_conv_spec *conv_info, unsigned int u_num);
void		ft_handle_hex_upper(t_conv_spec *conv_info, unsigned int u_num);
void		ft_handle_percentage(t_conv_spec *conv_info);

char		*pad_left(char *str, size_t pad_count, char pad_char);
char		*pad_right(char *str, size_t pad_count, char pad_char);
void		ft_output_field_width(int fd, t_conv_spec *conv_info);
void		put_prefix(t_conv_spec *conv_info, const char *prefix);
void		apply_precision_zeros(t_conv_spec *conv_info);
void		apply_field_width(t_conv_spec *ci);
/* ft_output */
void		conv_info_output(int fd, t_conv_spec *conv_info);
void		ft_output_char(int fd, t_conv_spec *conv_info);
void		ft_output_str(int fd, t_conv_spec *conv_info);
void		ft_output_ptr(int fd, t_conv_spec *conv_info);
void		ft_output_int(int fd, t_conv_spec *conv_info);
void		ft_output_int_u(int fd, t_conv_spec *conv_info);
void		ft_output_hex_lower(int fd, t_conv_spec *conv_info);
void		ft_output_hex_upper(int fd, t_conv_spec *conv_info);
void		ft_output_percentage(int fd, t_conv_spec *conv_info);

/* ft_utils */
size_t		ft_strlen_printf(const char *s);
char		*ft_strdup_printf(const char *s1);
char		*ft_substr_printf(char const *s, unsigned int start, size_t len);
void		*ft_memcpy_printf(void *dst, const void *src, size_t n);
void		*ft_memset_printf(void *b, int c, size_t len);
char		*ft_strjoin_printf(char const *s1, char const *s2);

#endif
