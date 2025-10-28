/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_ft_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 17:13:08 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "test_framework.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

TEST_INIT();

static void	test_basic_allocation(void)
{
	void	*ptr;
	int		*int_ptr;
	int		i;

	TEST_SECTION("Basic Allocation");
	ptr = ft_calloc(10, sizeof(int));
	ASSERT_NOT_NULL(ptr);
	int_ptr = (int *)ptr;
	i = 0;
	while (i < 10)
	{
		ASSERT_EQ(0, int_ptr[i], "%d");
		i++;
	}
	free(ptr);
}

static void	test_zero_allocation(void)
{
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;

	TEST_SECTION("Zero Allocation");
	ptr1 = ft_calloc(0, sizeof(int));
	ptr2 = ft_calloc(10, 0);
	ptr3 = ft_calloc(0, 0);
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	if (ptr3)
		free(ptr3);
}

static void	test_large_allocation(void)
{
	void	*ptr;
	char	*char_ptr;
	int		i;

	TEST_SECTION("Large Allocation");
	ptr = ft_calloc(1000, sizeof(char));
	ASSERT_NOT_NULL(ptr);
	char_ptr = (char *)ptr;
	i = 0;
	while (i < 1000)
	{
		ASSERT_EQ(0, char_ptr[i], "%d");
		i++;
	}
	free(ptr);
}

static void	test_overflow_protection(void)
{
	void	*ptr;

	TEST_SECTION("Overflow Protection");
	ptr = ft_calloc(SIZE_MAX, 2);
	ASSERT_NULL(ptr);
	ptr = ft_calloc(SIZE_MAX / 2 + 1, 2);
	ASSERT_NULL(ptr);
}

int	main(void)
{
	printf("ft_calloc Automated Test Suite\n");
	printf("==============================\n\n");
	test_basic_allocation();
	test_zero_allocation();
	test_large_allocation();
	test_overflow_protection();
	TEST_SUMMARY();
}
