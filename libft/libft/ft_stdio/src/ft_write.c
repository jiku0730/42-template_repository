/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:55:01 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 13:55:10 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <sys/syscall.h>
#include <errno.h>

/* write の再実装 */
ssize_t	ft_write(int fd, const void *buf, size_t count)
{
	long	ret;

	ret = syscall(SYS_write, fd, buf, count);
	if (ret < 0)
	{
		errno = -ret;
		return (-1);
	}
	return (ret);
}
