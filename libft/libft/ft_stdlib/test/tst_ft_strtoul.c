/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_strtoul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:32:04 by kei2003730       ###   ########.fr       */
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
	ASSERT_EQ(123UL, ft_strtoul("123", NULL, 10), "%lu");
	ASSERT_EQ(456UL, ft_strtoul("456", NULL, 10), "%lu");
	ASSERT_EQ(789UL, ft_strtoul("+789", NULL, 10), "%lu");
	ASSERT_EQ(0UL, ft_strtoul("0", NULL, 10), "%lu");
	TEST_SECTION("Different Base Conversion");
	ASSERT_EQ(5UL, ft_strtoul("101", NULL, 2), "%lu");
	ASSERT_EQ(511UL, ft_strtoul("777", NULL, 8), "%lu");
	ASSERT_EQ(255UL, ft_strtoul("ff", NULL, 16), "%lu");
	ASSERT_EQ(255UL, ft_strtoul("FF", NULL, 16), "%lu");
	ASSERT_EQ(291UL, ft_strtoul("0x123", NULL, 16), "%lu");
}

static void	test_auto_base_detection_endptr_and_whitespace_and_error_cases(void)
{
	char			*endptr;
	unsigned long	result;

	TEST_SECTION("Auto Base Detection (base=0)");
	ASSERT_EQ(123UL, ft_strtoul("123", NULL, 0), "%lu");
	ASSERT_EQ(83UL, ft_strtoul("0123", NULL, 0), "%lu");
	ASSERT_EQ(291UL, ft_strtoul("0x123", NULL, 0), "%lu");
	ASSERT_EQ(291UL, ft_strtoul("0X123", NULL, 0), "%lu");
	TEST_SECTION("End Pointer Tests");
	result = ft_strtoul("123abc", &endptr, 10);
	ASSERT_EQ(123UL, result, "%lu");
	ASSERT_STR_EQ("abc", endptr);
	result = ft_strtoul("", &endptr, 10);
	ASSERT_EQ(0UL, result, "%lu");
	ASSERT_STR_EQ("", endptr);
	TEST_SECTION("Whitespace Handling");
	ASSERT_EQ(123UL, ft_strtoul("  +123", NULL, 10), "%lu");
	TEST_SECTION("Error Cases");
	result = ft_strtoul("123", &endptr, 1);
	ASSERT_EQ(0UL, result, "%lu");
	result = ft_strtoul("123", &endptr, 37);
	ASSERT_EQ(0UL, result, "%lu");
	result = ft_strtoul("abc", &endptr, 10);
	ASSERT_EQ(0UL, result, "%lu");
	ASSERT_STR_EQ("abc", endptr);
}

static void	test_overflow_and_negative_numbers(void)
{
	unsigned long	result1;
	unsigned long	result2;
	unsigned long	std_result1;
	unsigned long	std_result2;
	char			ulong_max_str[32];

	TEST_SECTION("Overflow Tests");
	sprintf(ulong_max_str, "%lu", ULONG_MAX);
	ASSERT_EQ(ULONG_MAX, ft_strtoul(ulong_max_str, NULL, 10), "%lu");
	ASSERT_EQ(strtoul("99999999999999999999", NULL, 10),
		ft_strtoul("99999999999999999999", NULL, 10), "%lu");
	ASSERT_EQ(18446744073709551615UL, ft_strtoul("18446744073709551615", NULL,
			10), "%lu");
	ASSERT_EQ(ULONG_MAX, ft_strtoul("18446744073709551616", NULL, 10), "%lu");
	TEST_SECTION("Negative Numbers (Should Overflow)");
	result1 = ft_strtoul("-1", NULL, 10);
	result2 = ft_strtoul("-123", NULL, 10);
	std_result1 = strtoul("-1", NULL, 10);
	std_result2 = strtoul("-123", NULL, 10);
	ASSERT_EQ(std_result1, result1, "%lu");
	ASSERT_EQ(std_result2, result2, "%lu");
}

static void	test_large_numbers_and_mixed_content(void)
{
	char			*endptr;
	unsigned long	result;

	TEST_SECTION("Large Numbers");
	ASSERT_EQ(1000000UL, ft_strtoul("1000000", NULL, 10), "%lu");
	ASSERT_EQ(999999999UL, ft_strtoul("999999999", NULL, 10), "%lu");
	ASSERT_EQ(0xFFFFFFFFUL, ft_strtoul("ffffffff", NULL, 16), "%lu");
	ASSERT_EQ(0xFFFFFFFFUL, ft_strtoul("FFFFFFFF", NULL, 16), "%lu");
	TEST_SECTION("Mixed Content");
	result = ft_strtoul("123xyz", &endptr, 10);
	ASSERT_EQ(123UL, result, "%lu");
	ASSERT_STR_EQ("xyz", endptr);
	result = ft_strtoul("0x123ghi", &endptr, 16);
	ASSERT_EQ(291UL, result, "%lu");
	ASSERT_STR_EQ("ghi", endptr);
	result = ft_strtoul("777abc", &endptr, 8);
	ASSERT_EQ(511UL, result, "%lu");
	ASSERT_STR_EQ("abc", endptr);
}

int	main(void)
{
	printf("ft_strtoul Automated Test Suite\n");
	printf("===============================\n\n");
	test_basic_conversion_and_base_conversion();
	test_auto_base_detection_endptr_and_whitespace_and_error_cases();
	test_overflow_and_negative_numbers();
	test_large_numbers_and_mixed_content();
	TEST_SUMMARY();
}
