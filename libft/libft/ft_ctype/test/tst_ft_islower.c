/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_islower.c                                   :+:      :+:    :+:   */
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

static void	test_lowercase_letters(void)
{
	TEST_SECTION("Lowercase Letters (a-z)");
	ASSERT_EQ(1, ft_islower('a'), "%d");
	ASSERT_EQ(1, ft_islower('m'), "%d");
	ASSERT_EQ(1, ft_islower('z'), "%d");
}

static void	test_uppercase_letters(void)
{
	TEST_SECTION("Uppercase Letters");
	ASSERT_EQ(0, ft_islower('A'), "%d");
	ASSERT_EQ(0, ft_islower('M'), "%d");
	ASSERT_EQ(0, ft_islower('Z'), "%d");
}

static void	test_non_alphabetic(void)
{
	TEST_SECTION("Non-Alphabetic Characters");
	ASSERT_EQ(0, ft_islower('0'), "%d");
	ASSERT_EQ(0, ft_islower('9'), "%d");
	ASSERT_EQ(0, ft_islower(' '), "%d");
	ASSERT_EQ(0, ft_islower('!'), "%d");
	ASSERT_EQ(0, ft_islower('@'), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!islower(c) != !!ft_islower(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!islower(c),
				!!ft_islower(c));
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
	printf("ft_islower Automated Test Suite\n");
	printf("===============================\n\n");
	test_lowercase_letters();
	test_uppercase_letters();
	test_non_alphabetic();
	test_standard_compatibility();
	TEST_SUMMARY();
}
