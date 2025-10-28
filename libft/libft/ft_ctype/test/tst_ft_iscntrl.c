/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_iscntrl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:42:13 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "test_framework.h"
#include <ctype.h>

TEST_INIT();

static void	test_control_characters(void)
{
	TEST_SECTION("Control Characters (0-31, 127)");
	ASSERT_EQ(1, ft_iscntrl(0), "%d");
	ASSERT_EQ(1, ft_iscntrl(9), "%d");
	ASSERT_EQ(1, ft_iscntrl(10), "%d");
	ASSERT_EQ(1, ft_iscntrl(31), "%d");
	ASSERT_EQ(1, ft_iscntrl(127), "%d");
}

static void	test_non_control_characters(void)
{
	TEST_SECTION("Non-Control Characters");
	ASSERT_EQ(0, ft_iscntrl(' '), "%d");
	ASSERT_EQ(0, ft_iscntrl('A'), "%d");
	ASSERT_EQ(0, ft_iscntrl('z'), "%d");
	ASSERT_EQ(0, ft_iscntrl('0'), "%d");
	ASSERT_EQ(0, ft_iscntrl('~'), "%d");
}

static void	test_boundary_values(void)
{
	TEST_SECTION("Boundary Values");
	ASSERT_EQ(1, ft_iscntrl(0), "%d");
	ASSERT_EQ(1, ft_iscntrl(31), "%d");
	ASSERT_EQ(0, ft_iscntrl(32), "%d");
	ASSERT_EQ(0, ft_iscntrl(126), "%d");
	ASSERT_EQ(1, ft_iscntrl(127), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!iscntrl(c) != !!ft_iscntrl(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!iscntrl(c),
				!!ft_iscntrl(c));
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
	printf("ft_iscntrl Automated Test Suite\n");
	printf("===============================\n\n");
	test_control_characters();
	test_non_control_characters();
	test_boundary_values();
	test_standard_compatibility();
	TEST_SUMMARY();
}
