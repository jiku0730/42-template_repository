/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isascii.c                                   :+:      :+:    :+:   */
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

static void	test_ascii_range(void)
{
	TEST_SECTION("ASCII Range (0-127)");
	ASSERT_EQ(1, ft_isascii(0), "%d");
	ASSERT_EQ(1, ft_isascii(65), "%d");
	ASSERT_EQ(1, ft_isascii(127), "%d");
	ASSERT_EQ(1, ft_isascii('A'), "%d");
	ASSERT_EQ(1, ft_isascii('z'), "%d");
}

static void	test_non_ascii_range(void)
{
	TEST_SECTION("Non-ASCII Range (128-255)");
	ASSERT_EQ(0, ft_isascii(128), "%d");
	ASSERT_EQ(0, ft_isascii(200), "%d");
	ASSERT_EQ(0, ft_isascii(255), "%d");
}

static void	test_boundary_values(void)
{
	TEST_SECTION("Boundary Values");
	ASSERT_EQ(1, ft_isascii(0), "%d");
	ASSERT_EQ(1, ft_isascii(127), "%d");
	ASSERT_EQ(0, ft_isascii(-1), "%d");
	ASSERT_EQ(0, ft_isascii(128), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = -128;
	while (c <= 255)
	{
		if (!!isascii(c) != !!ft_isascii(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isascii(c),
				!!ft_isascii(c));
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
	printf("ft_isascii Automated Test Suite\n");
	printf("===============================\n\n");
	test_ascii_range();
	test_non_ascii_range();
	test_boundary_values();
	test_standard_compatibility();
	TEST_SUMMARY();
}
