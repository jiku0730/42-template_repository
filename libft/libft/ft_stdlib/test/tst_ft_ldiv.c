/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_ldiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:00:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 16:47:27 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <stdlib.h>

TEST_INIT();

static void	test_basic_division(void)
{
	ldiv_t		std_result;
	ft_ldiv_t	ft_result;

	TEST_SECTION("Basic Division");
	std_result = ldiv(100L, 7L);
	ft_result = ft_ldiv(100L, 7L);
	ASSERT_EQ(std_result.quot, ft_result.quot, "%ld");
	ASSERT_EQ(std_result.rem, ft_result.rem, "%ld");
	std_result = ldiv(200L, 8L);
	ft_result = ft_ldiv(200L, 8L);
	ASSERT_EQ(std_result.quot, ft_result.quot, "%ld");
	ASSERT_EQ(std_result.rem, ft_result.rem, "%ld");
}

static void	test_negative_division(void)
{
	ldiv_t		std_result;
	ft_ldiv_t	ft_result;

	TEST_SECTION("Negative Division");
	std_result = ldiv(-100L, 7L);
	ft_result = ft_ldiv(-100L, 7L);
	ASSERT_EQ(std_result.quot, ft_result.quot, "%ld");
	ASSERT_EQ(std_result.rem, ft_result.rem, "%ld");
	std_result = ldiv(100L, -7L);
	ft_result = ft_ldiv(100L, -7L);
	ASSERT_EQ(std_result.quot, ft_result.quot, "%ld");
	ASSERT_EQ(std_result.rem, ft_result.rem, "%ld");
}

static void	test_zero_dividend(void)
{
	ldiv_t		std_result;
	ft_ldiv_t	ft_result;

	TEST_SECTION("Zero Dividend");
	std_result = ldiv(0L, 5L);
	ft_result = ft_ldiv(0L, 5L);
	ASSERT_EQ(std_result.quot, ft_result.quot, "%ld");
	ASSERT_EQ(std_result.rem, ft_result.rem, "%ld");
}

static void	test_large_numbers(void)
{
	ldiv_t		std_result;
	ft_ldiv_t	ft_result;

	TEST_SECTION("Large Numbers");
	std_result = ldiv(123456789L, 123L);
	ft_result = ft_ldiv(123456789L, 123L);
	ASSERT_EQ(std_result.quot, ft_result.quot, "%ld");
	ASSERT_EQ(std_result.rem, ft_result.rem, "%ld");
}

int	main(void)
{
	printf("ft_ldiv Automated Test Suite\n");
	printf("============================\n\n");
	test_basic_division();
	test_negative_division();
	test_zero_dividend();
	test_large_numbers();
	TEST_SUMMARY();
}
