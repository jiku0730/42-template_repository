/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:42:15 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "test_framework.h"
#include <ctype.h>

TEST_INIT();

static void	test_whitespace_characters(void)
{
	TEST_SECTION("Whitespace Characters");
	ASSERT_EQ(1, ft_isspace(' '), "%d");
	ASSERT_EQ(1, ft_isspace('\t'), "%d");
	ASSERT_EQ(1, ft_isspace('\n'), "%d");
	ASSERT_EQ(1, ft_isspace('\r'), "%d");
	ASSERT_EQ(1, ft_isspace('\f'), "%d");
	ASSERT_EQ(1, ft_isspace('\v'), "%d");
}

static void	test_non_whitespace_characters(void)
{
	TEST_SECTION("Non-Whitespace Characters");
	ASSERT_EQ(0, ft_isspace('a'), "%d");
	ASSERT_EQ(0, ft_isspace('Z'), "%d");
	ASSERT_EQ(0, ft_isspace('0'), "%d");
	ASSERT_EQ(0, ft_isspace('!'), "%d");
	ASSERT_EQ(0, ft_isspace('@'), "%d");
}

static void	test_boundary_values(void)
{
	TEST_SECTION("Boundary Values");
	ASSERT_EQ(1, ft_isspace(9), "%d");
	ASSERT_EQ(1, ft_isspace(10), "%d");
	ASSERT_EQ(1, ft_isspace(11), "%d");
	ASSERT_EQ(1, ft_isspace(12), "%d");
	ASSERT_EQ(1, ft_isspace(13), "%d");
	ASSERT_EQ(1, ft_isspace(32), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isspace(c) != !!ft_isspace(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isspace(c),
				!!ft_isspace(c));
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
	printf("ft_isspace Automated Test Suite\n");
	printf("===============================\n\n");
	test_whitespace_characters();
	test_non_whitespace_characters();
	test_boundary_values();
	test_standard_compatibility();
	TEST_SUMMARY();
}
