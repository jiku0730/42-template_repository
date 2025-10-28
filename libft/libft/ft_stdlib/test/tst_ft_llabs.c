/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_llabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:00:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:00:09 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <limits.h>
#include <stdlib.h>

TEST_INIT();

static void	test_positive_numbers(void)
{
	TEST_SECTION("Positive Numbers");
	ASSERT_EQ(123456789012345LL, ft_llabs(123456789012345LL), "%lld");
	ASSERT_EQ(100LL, ft_llabs(100LL), "%lld");
	ASSERT_EQ(1LL, ft_llabs(1LL), "%lld");
	ASSERT_EQ(LLONG_MAX, ft_llabs(LLONG_MAX), "%lld");
}

static void	test_negative_numbers(void)
{
	TEST_SECTION("Negative Numbers");
	ASSERT_EQ(123456789012345LL, ft_llabs(-123456789012345LL), "%lld");
	ASSERT_EQ(100LL, ft_llabs(-100LL), "%lld");
	ASSERT_EQ(1LL, ft_llabs(-1LL), "%lld");
}

static void	test_zero(void)
{
	TEST_SECTION("Zero");
	ASSERT_EQ(0LL, ft_llabs(0LL), "%lld");
}

static void	test_edge_cases(void)
{
	TEST_SECTION("Edge Cases");
	ASSERT_EQ(llabs(LLONG_MIN), ft_llabs(LLONG_MIN), "%lld");
	ASSERT_EQ(llabs(-1LL), ft_llabs(-1LL), "%lld");
}

int	main(void)
{
	printf("ft_llabs Automated Test Suite\n");
	printf("=============================\n\n");
	test_positive_numbers();
	test_negative_numbers();
	test_zero();
	test_edge_cases();
	TEST_SUMMARY();
}
