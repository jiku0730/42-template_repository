/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:59:56 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 16:45:55 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/syscall.h>
# include <errno.h>
# include "ft_printf_utils.h"

typedef struct
{
	int				fd;			// 実際の write() に使う FD
	char			*buf;		// 出力バッファ
	size_t			buf_size;	// バッファ容量
	size_t			pos;		// buf 中の現在位置
	int 			flags;		// EOF/ERR やバッファモード
	pthread_mutex_t	lock;		// 排他制御用ミューテックス
}			file_t;

int		ft_getchar(void);
int		ft_getc(FILE *stream);
int		ft_fgetc(FILE *stream);
int		ft_putc(int c, FILE *stream);
int		ft_puts(const char *s, FILE *stream);
int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list *ap);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list *ap);
ssize_t	my_fwrite(const void *ptr, size_t size, size_t nmemb, file_t *f);
void	ft_putchar(char c);
int		my_fflush(file_t *f);
ssize_t	ft_read(int fd, void *buf, size_t count);
ssize_t	ft_write(int fd, const void *buf, size_t count);

#endif
