/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_atoll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:00:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:12:25 by kei2003730       ###   ########.fr       */
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
	ASSERT_EQ(1234567890123LL, ft_atoll("1234567890123"), "%lld");
	ASSERT_EQ(-9876543210987LL, ft_atoll("-9876543210987"), "%lld");
	ASSERT_EQ(0LL, ft_atoll("0"), "%lld");
	ASSERT_EQ(789LL, ft_atoll("+789"), "%lld");
}

static void	test_whitespace_handling_and_invalid_input(void)
{
	TEST_SECTION("Whitespace Handling");
	ASSERT_EQ(123LL, ft_atoll(" \t\n123"), "%lld");
	ASSERT_EQ(456LL, ft_atoll("  456"), "%lld");
	ASSERT_EQ(-789LL, ft_atoll("  -789"), "%lld");
	TEST_SECTION("Invalid Input");
	ASSERT_EQ(0LL, ft_atoll("abc"), "%lld");
	ASSERT_EQ(0LL, ft_atoll(""), "%lld");
	ASSERT_EQ(123LL, ft_atoll("123abc"), "%lld");
}

static void	test_overflow(void)
{
	TEST_SECTION("Overflow Tests");
	ASSERT_EQ(atoll("9223372036854775807"), ft_atoll("9223372036854775807"),
		"%lld");
	ASSERT_EQ(atoll("-9223372036854775808"), ft_atoll("-9223372036854775808"),
		"%lld");
	ASSERT_EQ(atoll("9223372036854775808"), ft_atoll("9223372036854775808"),
		"%lld");
}

static void	test_edge_cases(void)
{
	TEST_SECTION("Edge Cases");
	ASSERT_EQ(atoll("1"), ft_atoll("1"), "%lld");
	ASSERT_EQ(atoll("-1"), ft_atoll("-1"), "%lld");
	ASSERT_EQ(atoll("2147483647"), ft_atoll("2147483647"), "%lld");
	ASSERT_EQ(atoll("-2147483648"), ft_atoll("-2147483648"), "%lld");
}

int	main(void)
{
	printf("ft_atoll Automated Test Suite\n");
	printf("=============================\n\n");
	test_basic_conversion();
	test_whitespace_handling_and_invalid_input();
	test_overflow();
	test_edge_cases();
	TEST_SUMMARY();
}
