/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:42:11 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "test_framework.h"
#include <ctype.h>

TEST_INIT();

static void	test_digit_characters(void)
{
	TEST_SECTION("Digit Characters (0-9)");
	ASSERT_EQ(1, ft_isdigit('0'), "%d");
	ASSERT_EQ(1, ft_isdigit('1'), "%d");
	ASSERT_EQ(1, ft_isdigit('5'), "%d");
	ASSERT_EQ(1, ft_isdigit('9'), "%d");
}

static void	test_non_digit_characters(void)
{
	TEST_SECTION("Non-Digit Characters");
	ASSERT_EQ(0, ft_isdigit('a'), "%d");
	ASSERT_EQ(0, ft_isdigit('Z'), "%d");
	ASSERT_EQ(0, ft_isdigit(' '), "%d");
	ASSERT_EQ(0, ft_isdigit('!'), "%d");
	ASSERT_EQ(0, ft_isdigit('/'), "%d");
	ASSERT_EQ(0, ft_isdigit(':'), "%d");
}

static void	test_boundary_values(void)
{
	TEST_SECTION("Boundary Values");
	ASSERT_EQ(0, ft_isdigit('0' - 1), "%d");
	ASSERT_EQ(1, ft_isdigit('0'), "%d");
	ASSERT_EQ(1, ft_isdigit('9'), "%d");
	ASSERT_EQ(0, ft_isdigit('9' + 1), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isdigit(c) != !!ft_isdigit(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isdigit(c),
				!!ft_isdigit(c));
			g_test_count++;
		}
		else
		{
			g_test_count++;
			g_pass_count++;
		}
		c++;
	}
}

int	main(void)
{
	printf("ft_isdigit Automated Test Suite\n");
	printf("===============================\n\n");
	test_digit_characters();
	test_non_digit_characters();
	test_boundary_values();
	test_standard_compatibility();
	TEST_SUMMARY();
}
