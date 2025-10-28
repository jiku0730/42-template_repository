/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_ispunct.c                                   :+:      :+:    :+:   */
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

static void	test_punctuation_characters(void)
{
	TEST_SECTION("Punctuation Characters");
	ASSERT_EQ(1, ft_ispunct('!'), "%d");
	ASSERT_EQ(1, ft_ispunct('@'), "%d");
	ASSERT_EQ(1, ft_ispunct('#'), "%d");
	ASSERT_EQ(1, ft_ispunct('.'), "%d");
	ASSERT_EQ(1, ft_ispunct(','), "%d");
}

static void	test_alphanumeric_characters(void)
{
	TEST_SECTION("Alphanumeric Characters");
	ASSERT_EQ(0, ft_ispunct('a'), "%d");
	ASSERT_EQ(0, ft_ispunct('Z'), "%d");
	ASSERT_EQ(0, ft_ispunct('0'), "%d");
	ASSERT_EQ(0, ft_ispunct('9'), "%d");
}

static void	test_whitespace_characters(void)
{
	TEST_SECTION("Whitespace Characters");
	ASSERT_EQ(0, ft_ispunct(' '), "%d");
	ASSERT_EQ(0, ft_ispunct('\t'), "%d");
	ASSERT_EQ(0, ft_ispunct('\n'), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!ispunct(c) != !!ft_ispunct(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!ispunct(c),
				!!ft_ispunct(c));
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
	printf("ft_ispunct Automated Test Suite\n");
	printf("===============================\n\n");
	test_punctuation_characters();
	test_alphanumeric_characters();
	test_whitespace_characters();
	test_standard_compatibility();
	TEST_SUMMARY();
}
