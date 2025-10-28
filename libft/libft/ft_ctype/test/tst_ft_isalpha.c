/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_isalpha.c                                   :+:      :+:    :+:   */
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

static void	test_lowercase_letters(void)
{
	TEST_SECTION("Lowercase Letters");
	ASSERT_EQ(1, ft_isalpha('a'), "%d");
	ASSERT_EQ(1, ft_isalpha('m'), "%d");
	ASSERT_EQ(1, ft_isalpha('z'), "%d");
}

static void	test_uppercase_letters(void)
{
	TEST_SECTION("Uppercase Letters");
	ASSERT_EQ(1, ft_isalpha('A'), "%d");
	ASSERT_EQ(1, ft_isalpha('M'), "%d");
	ASSERT_EQ(1, ft_isalpha('Z'), "%d");
}

static void	test_non_alphabetic(void)
{
	TEST_SECTION("Non-Alphabetic Characters");
	ASSERT_EQ(0, ft_isalpha('0'), "%d");
	ASSERT_EQ(0, ft_isalpha('9'), "%d");
	ASSERT_EQ(0, ft_isalpha(' '), "%d");
	ASSERT_EQ(0, ft_isalpha('!'), "%d");
	ASSERT_EQ(0, ft_isalpha('@'), "%d");
	ASSERT_EQ(0, ft_isalpha('['), "%d");
	ASSERT_EQ(0, ft_isalpha('`'), "%d");
	ASSERT_EQ(0, ft_isalpha('{'), "%d");
}

static void	test_standard_compatibility(void)
{
	int	c;

	TEST_SECTION("Standard Library Compatibility");
	c = 0;
	while (c <= 255)
	{
		if (!!isalpha(c) != !!ft_isalpha(c))
		{
			printf("FAIL at char %d: std=%d, ft=%d\n", c, !!isalpha(c),
				!!ft_isalpha(c));
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
	printf("ft_isalpha Automated Test Suite\n");
	printf("===============================\n\n");
	test_lowercase_letters();
	test_uppercase_letters();
	test_non_alphabetic();
	test_standard_compatibility();
	TEST_SUMMARY();
}
