/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:36:15 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/13 20:39:11 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <stddef.h>

/* BSD string functions */
int		ft_bcmp(const void *s1, const void *s2, size_t n);
void	ft_bcopy(const void *src, void *dst, size_t n);
void	ft_bzero(void *s, size_t n);

/* Bit manipulation */
int		ft_ffs(int i);

/* String search functions (legacy) */
char	*ft_index(const char *s, int c);
char	*ft_rindex(const char *s, int c);

/* Case-insensitive string comparison */
int		ft_strcasecmp(const char *s1, const char *s2);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);

#endif

