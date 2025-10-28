/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:01:15 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/14 13:54:58 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#define _GNU_SOURCE
#include <unistd.h>

int	ft_fgetc(FILE *stream)
{
	unsigned char	c;

	ssize_t bytes_read;
	bytes_read = fread(&c, 1, 1, stream);
	if (bytes_read == 1)
		return (c);
	return (EOF);
}
