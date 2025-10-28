/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:13:57 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

TEST_INIT();

static void	test_positive_numbers(void)
{
	char	*result;

	TEST_SECTION("Positive Numbers");
	result = ft_itoa(123);
	ASSERT_STR_EQ("123", result);
	free(result);
	result = ft_itoa(456);
	ASSERT_STR_EQ("456", result);
	free(result);
	result = ft_itoa(1);
	ASSERT_STR_EQ("1", result);
	free(result);
}

static void	test_negative_numbers_and_zero(void)
{
	char	*result;

	TEST_SECTION("Negative Numbers");
	result = ft_itoa(-123);
	ASSERT_STR_EQ("-123", result);
	free(result);
	result = ft_itoa(-456);
	ASSERT_STR_EQ("-456", result);
	free(result);
	result = ft_itoa(-1);
	ASSERT_STR_EQ("-1", result);
	free(result);
	TEST_SECTION("Zero");
	result = ft_itoa(0);
	ASSERT_STR_EQ("0", result);
	free(result);
}

static void	test_edge_cases(void)
{
	char	*result;

	TEST_SECTION("Edge Cases");
	result = ft_itoa(INT_MAX);
	ASSERT_STR_EQ("2147483647", result);
	free(result);
	result = ft_itoa(INT_MIN);
	ASSERT_STR_EQ("-2147483648", result);
	free(result);
}

static void	test_memory_allocation(void)
{
	char	*result;

	TEST_SECTION("Memory Allocation");
	result = ft_itoa(123);
	ASSERT_NOT_NULL(result);
	free(result);
}

int	main(void)
{
	printf("ft_itoa Automated Test Suite\n");
	printf("============================\n\n");
	test_positive_numbers();
	test_negative_numbers_and_zero();
	test_edge_cases();
	test_memory_allocation();
	TEST_SUMMARY();
}
