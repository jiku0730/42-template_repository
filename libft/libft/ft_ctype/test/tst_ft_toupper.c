/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_toupper.c                                   :+:      :+:    :+:   */
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

static void	test_lowercase_conversion(void)
{
	TEST_SECTION("Lowercase to Uppercase Conversion");
	ASSERT_EQ('A', ft_toupper('a'), "%c");
	ASSERT_EQ('Z', ft_toupper('z'), "%c");
	ASSERT_EQ('M', ft_toupper('m'), "%c");
	ASSERT_EQ('B', ft_toupper('b'), "%c");
	ASSERT_EQ('Y', ft_toupper('y'), "%c");
}

static void	test_already_uppercase(void)
{
	TEST_SECTION("Already Uppercase Characters");
	ASSERT_EQ('A', ft_toupper('A'), "%c");
	ASSERT_EQ('Z', ft_toupper('Z'), "%c");
	ASSERT_EQ('M', ft_toupper('M'), "%c");
}

static void	test_non_alphabetic(void)
{
	TEST_SECTION("Non-Alphabetic Characters");
	ASSERT_EQ('0', ft_toupper('0'), "%c");
	ASSERT_EQ('9', ft_toupper('9'), "%c");
	ASSERT_EQ(' ', ft_toupper(' '), "%c");
	ASSERT_EQ('!', ft_toupper('!'), "%c");
	ASSERT_EQ('@', ft_toupper('@'), "%c");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (toupper(c) != ft_toupper(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, toupper(c),
				ft_toupper(c));
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
	printf("ft_toupper Automated Test Suite\n");
	printf("===============================\n\n");
	test_lowercase_conversion();
	test_already_uppercase();
	test_non_alphabetic();
	test_standard_compatibility();
	TEST_SUMMARY();
}
