/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 16:56:44 by kei2003730       ###   ########.fr       */
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
	ASSERT_EQ(5, ft_abs(5), "%d");
	ASSERT_EQ(100, ft_abs(100), "%d");
	ASSERT_EQ(1, ft_abs(1), "%d");
	ASSERT_EQ(INT_MAX, ft_abs(INT_MAX), "%d");
}

static void	test_negative_numbers(void)
{
	TEST_SECTION("Negative Numbers");
	ASSERT_EQ(5, ft_abs(-5), "%d");
	ASSERT_EQ(100, ft_abs(-100), "%d");
	ASSERT_EQ(1, ft_abs(-1), "%d");
}

static void	test_zero(void)
{
	TEST_SECTION("Zero");
	ASSERT_EQ(0, ft_abs(0), "%d");
}

static void	test_edge_cases(void)
{
	TEST_SECTION("Edge Cases");
	ASSERT_EQ(abs(INT_MIN), ft_abs(INT_MIN), "%d");
	ASSERT_EQ(abs(-1), ft_abs(-1), "%d");
}

int	main(void)
{
	printf("ft_abs Automated Test Suite\n");
	printf("===========================\n\n");
	test_positive_numbers();
	test_negative_numbers();
	test_zero();
	test_edge_cases();
	TEST_SUMMARY();
}
