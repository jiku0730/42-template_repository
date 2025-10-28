/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:42:10 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "test_framework.h"
#include <ctype.h>

TEST_INIT();

static void	test_alphabetic_characters(void)
{
	TEST_SECTION("Alphabetic Characters");
	ASSERT_EQ(1, ft_isalnum('a'), "%d");
	ASSERT_EQ(1, ft_isalnum('z'), "%d");
	ASSERT_EQ(1, ft_isalnum('A'), "%d");
	ASSERT_EQ(1, ft_isalnum('Z'), "%d");
	ASSERT_EQ(1, ft_isalnum('m'), "%d");
}

static void	test_numeric_characters(void)
{
	TEST_SECTION("Numeric Characters");
	ASSERT_EQ(1, ft_isalnum('0'), "%d");
	ASSERT_EQ(1, ft_isalnum('5'), "%d");
	ASSERT_EQ(1, ft_isalnum('9'), "%d");
}

static void	test_non_alphanumeric(void)
{
	TEST_SECTION("Non-Alphanumeric Characters");
	ASSERT_EQ(0, ft_isalnum(' '), "%d");
	ASSERT_EQ(0, ft_isalnum('!'), "%d");
	ASSERT_EQ(0, ft_isalnum('@'), "%d");
	ASSERT_EQ(0, ft_isalnum('['), "%d");
	ASSERT_EQ(0, ft_isalnum('`'), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isalnum(c) != !!ft_isalnum(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isalnum(c),
				!!ft_isalnum(c));
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
	printf("ft_isalnum Automated Test Suite\n");
	printf("===============================\n\n");
	test_alphabetic_characters();
	test_numeric_characters();
	test_non_alphanumeric();
	test_standard_compatibility();
	TEST_SUMMARY();
}
