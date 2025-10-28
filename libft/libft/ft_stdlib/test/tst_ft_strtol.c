/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_strtol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:14:26 by kei2003730       ###   ########.fr       */
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
	ASSERT_EQ(123L, ft_strtol("123", NULL, 10), "%ld");
	ASSERT_EQ(-456L, ft_strtol("-456", NULL, 10), "%ld");
	ASSERT_EQ(789L, ft_strtol("+789", NULL, 10), "%ld");
	ASSERT_EQ(0L, ft_strtol("0", NULL, 10), "%ld");
}

static void	test_different_bases_and_auto_base_detection(void)
{
	TEST_SECTION("Different Bases");
	ASSERT_EQ(5L, ft_strtol("101", NULL, 2), "%ld");
	ASSERT_EQ(511L, ft_strtol("777", NULL, 8), "%ld");
	ASSERT_EQ(255L, ft_strtol("ff", NULL, 16), "%ld");
	ASSERT_EQ(255L, ft_strtol("FF", NULL, 16), "%ld");
	TEST_SECTION("Auto Base Detection");
	ASSERT_EQ(123L, ft_strtol("123", NULL, 0), "%ld");
	ASSERT_EQ(83L, ft_strtol("0123", NULL, 0), "%ld");
	ASSERT_EQ(291L, ft_strtol("0x123", NULL, 0), "%ld");
}

static void	test_endptr(void)
{
	char	*endptr;
	long	result;

	TEST_SECTION("End Pointer Tests");
	result = ft_strtol("123abc", &endptr, 10);
	ASSERT_EQ(123L, result, "%ld");
	ASSERT_STR_EQ("abc", endptr);
	result = ft_strtol("  456def", &endptr, 10);
	ASSERT_EQ(456L, result, "%ld");
	ASSERT_STR_EQ("def", endptr);
}

static void	test_overflow(void)
{
	long	ft_result1;
	long	ft_result2;
	long	std_result1;
	long	std_result2;

	TEST_SECTION("Overflow Tests");
	std_result1 = strtol("9223372036854775807", NULL, 10);
	ft_result1 = ft_strtol("9223372036854775807", NULL, 10);
	ASSERT_EQ(std_result1, ft_result1, "%ld");
	std_result2 = strtol("9223372036854775808", NULL, 10);
	ft_result2 = ft_strtol("9223372036854775808", NULL, 10);
	ASSERT_EQ(std_result2, ft_result2, "%ld");
}

int	main(void)
{
	printf("ft_strtol Automated Test Suite\n");
	printf("==============================\n\n");
	test_basic_conversion();
	test_different_bases_and_auto_base_detection();
	test_endptr();
	test_overflow();
	TEST_SUMMARY();
}
