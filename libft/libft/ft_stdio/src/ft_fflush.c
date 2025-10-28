/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:37:38 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 13:37:53 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	my_fflush(file_t *f)
{
	pthread_mutex_lock(&f->lock);
	if (f->pos > 0)
	{
		if (write(f->fd, f->buf, f->pos) < 0)
		{
			f->flags |= 1;
			pthread_mutex_unlock(&f->lock);
			return (-1);
		}
		f->pos = 0;
	}
	pthread_mutex_unlock(&f->lock);
	return (0);
}
