/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:53:07 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:19:25 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
	int	quot;
	int	rem;
}	ft_div_t;

typedef struct
{
	long	quot;
	long	rem;
}	ft_ldiv_t;

typedef struct
{
	long long	quot;
	long long	rem;
}	ft_lldiv_t;

int			ft_abs(int i);
long		ft_labs(long i);
long long	ft_llabs(long long i);

ft_div_t	ft_div(int numer, int denom);
ft_ldiv_t	ft_ldiv(long numer, long denom);
ft_lldiv_t	ft_lldiv(long long numer, long long denom);

int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
long long	ft_atoll(const char *nptr);
char		*ft_itoa(int n);
long		ft_strtol(const char *nptr, char **endptr, int base);
long long	ft_strtoll(const char *nptr, char **endptr, int base);
unsigned long	ft_strtoul(const char *nptr, char **endptr, int base);
unsigned long long	ft_strtoull(const char *nptr, char **endptr, int base);

void		*ft_calloc(size_t count, size_t size);

/* ft_strtoll_utils.c */
int			ft_isspace_utils(char c);
int			char_to_digit_utils(char c);
int			check_overflow(unsigned long long acc, int digit, int base);
char		*handle_base_prefix(char *s, int *base);
char		*preprocess_input(const char *nptr, int *negative, int *base);
int			convert_digits(const char **s, int base,
									unsigned long long *acc);
long long	finalize_result(unsigned long long acc, int negative,
					int overflow);
#endif
