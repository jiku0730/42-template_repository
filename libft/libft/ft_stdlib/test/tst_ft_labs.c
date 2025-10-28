/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_labs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:00:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:00:03 by kei2003730       ###   ########.fr       */
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
	ASSERT_EQ(123456789L, ft_labs(123456789L), "%ld");
	ASSERT_EQ(100L, ft_labs(100L), "%ld");
	ASSERT_EQ(1L, ft_labs(1L), "%ld");
	ASSERT_EQ(LONG_MAX, ft_labs(LONG_MAX), "%ld");
}

static void	test_negative_numbers(void)
{
	TEST_SECTION("Negative Numbers");
	ASSERT_EQ(123456789L, ft_labs(-123456789L), "%ld");
	ASSERT_EQ(100L, ft_labs(-100L), "%ld");
	ASSERT_EQ(1L, ft_labs(-1L), "%ld");
}

static void	test_zero(void)
{
	TEST_SECTION("Zero");
	ASSERT_EQ(0L, ft_labs(0L), "%ld");
}

static void	test_edge_cases(void)
{
	TEST_SECTION("Edge Cases");
	ASSERT_EQ(labs(LONG_MIN), ft_labs(LONG_MIN), "%ld");
	ASSERT_EQ(labs(-1L), ft_labs(-1L), "%ld");
}

int	main(void)
{
	printf("ft_labs Automated Test Suite\n");
	printf("============================\n\n");
	test_positive_numbers();
	test_negative_numbers();
	test_zero();
	test_edge_cases();
	TEST_SUMMARY();
}
