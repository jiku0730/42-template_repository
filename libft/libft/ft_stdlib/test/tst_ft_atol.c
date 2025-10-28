/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_atol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:00:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:01:28 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <limits.h>
#include <stdlib.h>

TEST_INIT();

static void	test_basic_conversion(void)
{
	TEST_SECTION("Basic Conversion");
	ASSERT_EQ(123456L, ft_atol("123456"), "%ld");
	ASSERT_EQ(-654321L, ft_atol("-654321"), "%ld");
	ASSERT_EQ(0L, ft_atol("0"), "%ld");
	ASSERT_EQ(789L, ft_atol("+789"), "%ld");
}

static void	test_whitespace_hundling_and_invalid_input(void)
{
	TEST_SECTION("Whitespace Handling");
	ASSERT_EQ(123L, ft_atol(" \t\n123"), "%ld");
	ASSERT_EQ(456L, ft_atol("  456"), "%ld");
	ASSERT_EQ(-789L, ft_atol("  -789"), "%ld");
	TEST_SECTION("Invalid Input");
	ASSERT_EQ(0L, ft_atol("abc"), "%ld");
	ASSERT_EQ(0L, ft_atol(""), "%ld");
	ASSERT_EQ(123L, ft_atol("123abc"), "%ld");
}

static void	test_overflow(void)
{
	TEST_SECTION("Overflow Tests");
	ASSERT_EQ(atol("9223372036854775807"), ft_atol("9223372036854775807"),
		"%ld");
	ASSERT_EQ(atol("-9223372036854775808"), ft_atol("-9223372036854775808"),
		"%ld");
	ASSERT_EQ(atol("9223372036854775808"), ft_atol("9223372036854775808"),
		"%ld");
}

static void	test_edge_cases(void)
{
	TEST_SECTION("Edge Cases");
	ASSERT_EQ(atol("1"), ft_atol("1"), "%ld");
	ASSERT_EQ(atol("-1"), ft_atol("-1"), "%ld");
	ASSERT_EQ(atol("2147483647"), ft_atol("2147483647"), "%ld");
	ASSERT_EQ(atol("-2147483648"), ft_atol("-2147483648"), "%ld");
}

int	main(void)
{
	printf("ft_atol Automated Test Suite\n");
	printf("============================\n\n");
	test_basic_conversion();
	test_whitespace_hundling_and_invalid_input();
	test_overflow();
	test_edge_cases();
	TEST_SUMMARY();
}
