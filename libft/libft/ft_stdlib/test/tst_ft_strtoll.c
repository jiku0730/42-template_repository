/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_strtoll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:00:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:14:40 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

TEST_INIT();

static void	test_basic_conversion(void)
{
	TEST_SECTION("Basic Conversion");
	ASSERT_EQ(123LL, ft_strtoll("123", NULL, 10), "%lld");
	ASSERT_EQ(-456LL, ft_strtoll("-456", NULL, 10), "%lld");
	ASSERT_EQ(789LL, ft_strtoll("+789", NULL, 10), "%lld");
	ASSERT_EQ(0LL, ft_strtoll("0", NULL, 10), "%lld");
}

static void	test_different_bases_auto_base_detection(void)
{
	TEST_SECTION("Different Bases");
	ASSERT_EQ(5LL, ft_strtoll("101", NULL, 2), "%lld");
	ASSERT_EQ(511LL, ft_strtoll("777", NULL, 8), "%lld");
	ASSERT_EQ(255LL, ft_strtoll("ff", NULL, 16), "%lld");
	ASSERT_EQ(255LL, ft_strtoll("FF", NULL, 16), "%lld");
	TEST_SECTION("Auto Base Detection");
	ASSERT_EQ(123LL, ft_strtoll("123", NULL, 0), "%lld");
	ASSERT_EQ(83LL, ft_strtoll("0123", NULL, 0), "%lld");
	ASSERT_EQ(291LL, ft_strtoll("0x123", NULL, 0), "%lld");
}

static void	test_endptr_and_whitespace(void)
{
	char		*endptr;
	long long	result;

	TEST_SECTION("End Pointer Tests");
	result = ft_strtoll("987654321xyz", &endptr, 10);
	ASSERT_EQ(987654321LL, result, "%lld");
	ASSERT_STR_EQ("xyz", endptr);
	result = ft_strtoll("  456def", &endptr, 10);
	ASSERT_EQ(456LL, result, "%lld");
	ASSERT_STR_EQ("def", endptr);
	TEST_SECTION("Whitespace Handling");
	ASSERT_EQ(123LL, ft_strtoll(" \t123", NULL, 10), "%lld");
	ASSERT_EQ(456LL, ft_strtoll("  456", NULL, 10), "%lld");
	ASSERT_EQ(-789LL, ft_strtoll("  -789", NULL, 10), "%lld");
}

static void	test_overflow(void)
{
	long long	ft_result1;
	long long	ft_result2;
	long long	std_result1;
	long long	std_result2;

	TEST_SECTION("Overflow Tests");
	std_result1 = strtoll("9223372036854775807", NULL, 10);
	ft_result1 = ft_strtoll("9223372036854775807", NULL, 10);
	ASSERT_EQ(std_result1, ft_result1, "%lld");
	std_result2 = strtoll("9223372036854775808", NULL, 10);
	ft_result2 = ft_strtoll("9223372036854775808", NULL, 10);
	ASSERT_EQ(std_result2, ft_result2, "%lld");
}

int	main(void)
{
	printf("ft_strtoll Automated Test Suite\n");
	printf("===============================\n\n");
	test_basic_conversion();
	test_different_bases_auto_base_detection();
	test_endptr_and_whitespace();
	test_overflow();
	TEST_SUMMARY();
}
