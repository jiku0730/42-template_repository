/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isprint.c                                   :+:      :+:    :+:   */
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

static void	test_printable_characters(void)
{
	TEST_SECTION("Printable Characters (32-126)");
	ASSERT_EQ(1, ft_isprint(' '), "%d");
	ASSERT_EQ(1, ft_isprint('A'), "%d");
	ASSERT_EQ(1, ft_isprint('z'), "%d");
	ASSERT_EQ(1, ft_isprint('0'), "%d");
	ASSERT_EQ(1, ft_isprint('~'), "%d");
}

static void	test_non_printable_characters(void)
{
	TEST_SECTION("Non-Printable Characters");
	ASSERT_EQ(0, ft_isprint(0), "%d");
	ASSERT_EQ(0, ft_isprint(9), "%d");
	ASSERT_EQ(0, ft_isprint(10), "%d");
	ASSERT_EQ(0, ft_isprint(31), "%d");
	ASSERT_EQ(0, ft_isprint(127), "%d");
}

static void	test_boundary_values(void)
{
	TEST_SECTION("Boundary Values");
	ASSERT_EQ(0, ft_isprint(31), "%d");
	ASSERT_EQ(1, ft_isprint(32), "%d");
	ASSERT_EQ(1, ft_isprint(126), "%d");
	ASSERT_EQ(0, ft_isprint(127), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isprint(c) != !!ft_isprint(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isprint(c),
				!!ft_isprint(c));
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
	printf("ft_isprint Automated Test Suite\n");
	printf("===============================\n\n");
	test_printable_characters();
	test_non_printable_characters();
	test_boundary_values();
	test_standard_compatibility();
	TEST_SUMMARY();
}
