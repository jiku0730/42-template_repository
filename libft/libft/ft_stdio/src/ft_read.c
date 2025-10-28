/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:53:05 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 13:54:47 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <sys/syscall.h>
#include <errno.h>

/* reimplimentation of read function */
ssize_t	ft_read(int fd, void *buf, size_t count)
{
	long	ret;

	ret = syscall(SYS_read, fd, buf, count);
	if (ret < 0)
	{
		errno = -ret;
		return (-1);
	}
	return (ret);
}

