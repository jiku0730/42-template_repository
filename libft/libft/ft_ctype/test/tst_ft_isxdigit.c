/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isxdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:45:08 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "test_framework.h"
#include <ctype.h>

TEST_INIT();

static void	test_decimal_digits(void)
{
	TEST_SECTION("Decimal Digits (0-9)");
	ASSERT_EQ(1, ft_isxdigit('0'), "%d");
	ASSERT_EQ(1, ft_isxdigit('5'), "%d");
	ASSERT_EQ(1, ft_isxdigit('9'), "%d");
}

static void	test_hex_letters_lowercase_and_uppercase(void)
{
	TEST_SECTION("Hex Letters Lowercase (a-f)");
	ASSERT_EQ(1, ft_isxdigit('a'), "%d");
	ASSERT_EQ(1, ft_isxdigit('c'), "%d");
	ASSERT_EQ(1, ft_isxdigit('f'), "%d");
	TEST_SECTION("Hex Letters Uppercase (A-F)");
	ASSERT_EQ(1, ft_isxdigit('A'), "%d");
	ASSERT_EQ(1, ft_isxdigit('C'), "%d");
	ASSERT_EQ(1, ft_isxdigit('F'), "%d");
}

static void	test_non_hex_characters(void)
{
	TEST_SECTION("Non-Hexadecimal Characters");
	ASSERT_EQ(0, ft_isxdigit('g'), "%d");
	ASSERT_EQ(0, ft_isxdigit('G'), "%d");
	ASSERT_EQ(0, ft_isxdigit('z'), "%d");
	ASSERT_EQ(0, ft_isxdigit('Z'), "%d");
	ASSERT_EQ(0, ft_isxdigit(' '), "%d");
	ASSERT_EQ(0, ft_isxdigit('!'), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isxdigit(c) != !!ft_isxdigit(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isxdigit(c),
				!!ft_isxdigit(c));
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
	printf("ft_isxdigit Automated Test Suite\n");
	printf("================================\n\n");
	test_decimal_digits();
	test_hex_letters_lowercase_and_uppercase();
	test_non_hex_characters();
	test_standard_compatibility();
	TEST_SUMMARY();
}
