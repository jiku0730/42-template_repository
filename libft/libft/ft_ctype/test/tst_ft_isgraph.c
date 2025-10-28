/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isgraph.c                                   :+:      :+:    :+:   */
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

static void	test_graphic_characters(void)
{
	TEST_SECTION("Graphic Characters (33-126)");
	ASSERT_EQ(1, ft_isgraph('!'), "%d");
	ASSERT_EQ(1, ft_isgraph('A'), "%d");
	ASSERT_EQ(1, ft_isgraph('z'), "%d");
	ASSERT_EQ(1, ft_isgraph('0'), "%d");
	ASSERT_EQ(1, ft_isgraph('~'), "%d");
}

static void	test_non_graphic_characters(void)
{
	TEST_SECTION("Non-Graphic Characters");
	ASSERT_EQ(0, ft_isgraph(' '), "%d");
	ASSERT_EQ(0, ft_isgraph('\t'), "%d");
	ASSERT_EQ(0, ft_isgraph('\n'), "%d");
	ASSERT_EQ(0, ft_isgraph(0), "%d");
	ASSERT_EQ(0, ft_isgraph(127), "%d");
}

static void	test_boundary_values(void)
{
	TEST_SECTION("Boundary Values");
	ASSERT_EQ(0, ft_isgraph(32), "%d");
	ASSERT_EQ(1, ft_isgraph(33), "%d");
	ASSERT_EQ(1, ft_isgraph(126), "%d");
	ASSERT_EQ(0, ft_isgraph(127), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isgraph(c) != !!ft_isgraph(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isgraph(c),
				!!ft_isgraph(c));
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
	printf("ft_isgraph Automated Test Suite\n");
	printf("===============================\n\n");
	test_graphic_characters();
	test_non_graphic_characters();
	test_boundary_values();
	test_standard_compatibility();
	TEST_SUMMARY();
}
