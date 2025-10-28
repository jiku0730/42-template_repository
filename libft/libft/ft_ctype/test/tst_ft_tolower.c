/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_tolower.c                                   :+:      :+:    :+:   */
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

static void	test_uppercase_conversion(void)
{
	TEST_SECTION("Uppercase to Lowercase Conversion");
	ASSERT_EQ('a', ft_tolower('A'), "%c");
	ASSERT_EQ('z', ft_tolower('Z'), "%c");
	ASSERT_EQ('m', ft_tolower('M'), "%c");
	ASSERT_EQ('b', ft_tolower('B'), "%c");
	ASSERT_EQ('y', ft_tolower('Y'), "%c");
}

static void	test_already_lowercase(void)
{
	TEST_SECTION("Already Lowercase Characters");
	ASSERT_EQ('a', ft_tolower('a'), "%c");
	ASSERT_EQ('z', ft_tolower('z'), "%c");
	ASSERT_EQ('m', ft_tolower('m'), "%c");
}

static void	test_non_alphabetic(void)
{
	TEST_SECTION("Non-Alphabetic Characters");
	ASSERT_EQ('0', ft_tolower('0'), "%c");
	ASSERT_EQ('9', ft_tolower('9'), "%c");
	ASSERT_EQ(' ', ft_tolower(' '), "%c");
	ASSERT_EQ('!', ft_tolower('!'), "%c");
	ASSERT_EQ('@', ft_tolower('@'), "%c");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (tolower(c) != ft_tolower(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, tolower(c),
				ft_tolower(c));
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
	printf("ft_tolower Automated Test Suite\n");
	printf("===============================\n\n");
	test_uppercase_conversion();
	test_already_lowercase();
	test_non_alphabetic();
	test_standard_compatibility();
	TEST_SUMMARY();
}
