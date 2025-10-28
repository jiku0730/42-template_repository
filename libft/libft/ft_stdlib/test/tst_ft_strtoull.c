/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_strtoull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:15:13 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

TEST_INIT();

static void	test_basic_conversion_and_base_conversion(void)
{
	TEST_SECTION("Basic Decimal Conversion");
	ASSERT_EQ(123ULL, ft_strtoull("123", NULL, 10), "%llu");
	ASSERT_EQ(456ULL, ft_strtoull("456", NULL, 10), "%llu");
	ASSERT_EQ(789ULL, ft_strtoull("+789", NULL, 10), "%llu");
	ASSERT_EQ(0ULL, ft_strtoull("0", NULL, 10), "%llu");
	TEST_SECTION("Different Base Conversion");
	ASSERT_EQ(5ULL, ft_strtoull("101", NULL, 2), "%llu");
	ASSERT_EQ(511ULL, ft_strtoull("777", NULL, 8), "%llu");
	ASSERT_EQ(255ULL, ft_strtoull("ff", NULL, 16), "%llu");
	ASSERT_EQ(255ULL, ft_strtoull("FF", NULL, 16), "%llu");
	ASSERT_EQ(291ULL, ft_strtoull("0x123", NULL, 16), "%llu");
}

static void	test_test_auto_base_detection_endptr(void)
{
	char				*endptr;
	unsigned long long	result;

	TEST_SECTION("Auto Base Detection (base=0)");
	ASSERT_EQ(123ULL, ft_strtoull("123", NULL, 0), "%llu");
	ASSERT_EQ(83ULL, ft_strtoull("0123", NULL, 0), "%llu");
	ASSERT_EQ(291ULL, ft_strtoull("0x123", NULL, 0), "%llu");
	ASSERT_EQ(291ULL, ft_strtoull("0X123", NULL, 0), "%llu");
	TEST_SECTION("End Pointer Tests");
	result = ft_strtoull("123abc", &endptr, 10);
	ASSERT_EQ(123ULL, result, "%llu");
	ASSERT_STR_EQ("abc", endptr);
	result = ft_strtoull("  456def", &endptr, 10);
	ASSERT_EQ(456ULL, result, "%llu");
	ASSERT_STR_EQ("def", endptr);
	result = ft_strtoull("", &endptr, 10);
	ASSERT_EQ(0ULL, result, "%llu");
	ASSERT_STR_EQ("", endptr);
}

static void	test_whitespace_and_error_cases(void)
{
	char				*endptr;
	unsigned long long	result;

	TEST_SECTION("Whitespace Handling");
	ASSERT_EQ(123ULL, ft_strtoull(" \t123", NULL, 10), "%llu");
	ASSERT_EQ(456ULL, ft_strtoull("  456", NULL, 10), "%llu");
	ASSERT_EQ(123ULL, ft_strtoull("  +123", NULL, 10), "%llu");
	TEST_SECTION("Error Cases");
	result = ft_strtoull("123", &endptr, 1);
	ASSERT_EQ(0ULL, result, "%llu");
	result = ft_strtoull("123", &endptr, 37);
	ASSERT_EQ(0ULL, result, "%llu");
	result = ft_strtoull("abc", &endptr, 10);
	ASSERT_EQ(0ULL, result, "%llu");
	ASSERT_STR_EQ("abc", endptr);
}

static void	test_overflow_and_negative_numbers(void)
{
	unsigned long long	result1;
	unsigned long long	result2;
	unsigned long long	std_result1;
	unsigned long long	std_result2;

	TEST_SECTION("Overflow Tests");
	ASSERT_EQ(ULLONG_MAX, ft_strtoull("18446744073709551615", NULL, 10),
		"%llu");
	ASSERT_EQ(ULLONG_MAX, ft_strtoull("18446744073709551616", NULL, 10),
		"%llu");
	ASSERT_EQ(ULLONG_MAX, ft_strtoull("99999999999999999999", NULL, 10),
		"%llu");
	TEST_SECTION("Negative Numbers (Should Overflow)");
	result1 = ft_strtoull("-1", NULL, 10);
	result2 = ft_strtoull("-123", NULL, 10);
	std_result1 = strtoull("-1", NULL, 10);
	std_result2 = strtoull("-123", NULL, 10);
	ASSERT_EQ(std_result1, result1, "%llu");
	ASSERT_EQ(std_result2, result2, "%llu");
}

int	main(void)
{
	printf("ft_strtoull Automated Test Suite\n");
	printf("================================\n\n");
	test_basic_conversion_and_base_conversion();
	test_test_auto_base_detection_endptr();
	test_whitespace_and_error_cases();
	test_overflow_and_negative_numbers();
	TEST_SUMMARY();
}
