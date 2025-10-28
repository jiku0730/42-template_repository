/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:42:12 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "test_framework.h"
#include <ctype.h>

TEST_INIT();

static void	test_blank_characters(void)
{
	TEST_SECTION("Blank Characters");
	ASSERT_EQ(1, ft_isblank(' '), "%d");
	ASSERT_EQ(1, ft_isblank('\t'), "%d");
}

static void	test_non_blank_characters(void)
{
	TEST_SECTION("Non-Blank Characters");
	ASSERT_EQ(0, ft_isblank('a'), "%d");
	ASSERT_EQ(0, ft_isblank('0'), "%d");
	ASSERT_EQ(0, ft_isblank('\n'), "%d");
	ASSERT_EQ(0, ft_isblank('\r'), "%d");
	ASSERT_EQ(0, ft_isblank('\v'), "%d");
}

static void	test_other_whitespace(void)
{
	TEST_SECTION("Other Whitespace Characters");
	ASSERT_EQ(0, ft_isblank('\n'), "%d");
	ASSERT_EQ(0, ft_isblank('\r'), "%d");
	ASSERT_EQ(0, ft_isblank('\f'), "%d");
	ASSERT_EQ(0, ft_isblank('\v'), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isblank(c) != !!ft_isblank(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isblank(c),
				!!ft_isblank(c));
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
	printf("ft_isblank Automated Test Suite\n");
	printf("===============================\n\n");
	test_blank_characters();
	test_non_blank_characters();
	test_other_whitespace();
	test_standard_compatibility();
	TEST_SUMMARY();
}
