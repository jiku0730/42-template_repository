/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 16:59:23 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <limits.h>
#include <stdlib.h>

TEST_INIT();

static void	test_basic_conversion(void)
{
	TEST_SECTION("Basic Conversion");
	ASSERT_EQ(123, ft_atoi("123"), "%d");
	ASSERT_EQ(456, ft_atoi("456"), "%d");
	ASSERT_EQ(-789, ft_atoi("-789"), "%d");
	ASSERT_EQ(0, ft_atoi("0"), "%d");
}

static void	test_whitespace_and_sign_handling(void)
{
	TEST_SECTION("Whitespace Handling");
	ASSERT_EQ(123, ft_atoi(" \t\n123"), "%d");
	ASSERT_EQ(456, ft_atoi("  456"), "%d");
	ASSERT_EQ(-789, ft_atoi("  -789"), "%d");
	TEST_SECTION("Sign Handling");
	ASSERT_EQ(123, ft_atoi("+123"), "%d");
	ASSERT_EQ(-456, ft_atoi("-456"), "%d");
	ASSERT_EQ(789, ft_atoi("789"), "%d");
}

static void	test_invalid_input(void)
{
	TEST_SECTION("Invalid Input");
	ASSERT_EQ(0, ft_atoi("abc"), "%d");
	ASSERT_EQ(0, ft_atoi(""), "%d");
	ASSERT_EQ(123, ft_atoi("123abc"), "%d");
}

static void	test_overflow(void)
{
	TEST_SECTION("Overflow Tests");
	ASSERT_EQ(atoi("2147483647"), ft_atoi("2147483647"), "%d");
	ASSERT_EQ(atoi("-2147483648"), ft_atoi("-2147483648"), "%d");
	ASSERT_EQ(atoi("2147483648"), ft_atoi("2147483648"), "%d");
}

int	main(void)
{
	printf("ft_atoi Automated Test Suite\n");
	printf("============================\n\n");
	test_basic_conversion();
	test_whitespace_and_sign_handling();
	test_invalid_input();
	test_overflow();
	TEST_SUMMARY();
}
