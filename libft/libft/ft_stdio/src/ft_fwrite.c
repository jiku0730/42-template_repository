/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:32:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 13:40:54 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

/* When memory regions may overlap, you should use memmove instead of memcpy */
static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_str;
	const unsigned char	*src_str;

	if (n == 0 || dest == src)
		return (dest);
	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	while (n--)
		*(dest_str++) = *(src_str++);
	return (dest);
}

ssize_t	my_fwrite(const void *ptr, size_t size, size_t nmemb, file_t *f)
{
	size_t		total;
	const char	*data = ptr;
	ssize_t		written;

	total = size * nmemb;
	written = 0;
	pthread_mutex_lock(&f->lock);
	if (f->pos + total > f->buf_size)
	{
		if (write(f->fd, f->buf, f->pos) < 0)
		{
			f->flags |= 1;
			pthread_mutex_unlock(&f->lock);
			return (-1);
		}
		f->pos = 0;
	}
	ft_memcpy(f->buf + f->pos, data, total);
	f->pos += total;
	written = (ssize_t)nmemb;
	pthread_mutex_unlock(&f->lock);
	return (written);
}
