/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_framework.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:04:22 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/16 16:18:06 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FRAMEWORK_H
# define TEST_FRAMEWORK_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

extern int g_test_count;
extern int g_pass_count;

/* 色付きの出力用マクロ */
# define COLOR_GREEN "\033[32m"
# define COLOR_RED "\033[31m"
# define COLOR_BLUE "\033[34m"
# define COLOR_RESET "\033[0m"

/* テストセクション開始 */
# define TEST_SECTION(name) \
    do { \
        printf(COLOR_BLUE "=== " name " ===" COLOR_RESET "\n"); \
    } while(0)

/* 基本アサーション */
# define ASSERT_EQ(expected, actual, fmt) \
    do { \
        g_test_count++; \
        if ((expected) == (actual)) { \
            g_pass_count++; \
            printf(COLOR_GREEN "✓ PASS: " COLOR_RESET #expected " == " #actual "\n"); \
        } else { \
            printf(COLOR_RED "✗ FAIL: " COLOR_RESET #expected " == " #actual "\n"); \
            printf("  Expected: " fmt "\n", expected); \
            printf("  Actual:   " fmt "\n", actual); \
        } \
    } while(0)

/* 文字列比較 */
# define ASSERT_STR_EQ(expected, actual) \
    do { \
        g_test_count++; \
        const char *exp_str = (expected) ? (expected) : "NULL"; \
        const char *act_str = (actual) ? (actual) : "NULL"; \
        if (strcmp(exp_str, act_str) == 0) { \
            g_pass_count++; \
            printf(COLOR_GREEN "✓ PASS: " COLOR_RESET "strings match\n"); \
        } else { \
            printf(COLOR_RED "✗ FAIL: " COLOR_RESET "string mismatch\n"); \
            printf("  Expected: \"%s\"\n", exp_str); \
            printf("  Actual:   \"%s\"\n", act_str); \
        } \
    } while(0)

/* ポインタ比較 */
# define ASSERT_PTR_EQ(expected, actual) \
    do { \
        g_test_count++; \
        if ((expected) == (actual)) { \
            g_pass_count++; \
            printf(COLOR_GREEN "✓ PASS: " COLOR_RESET "pointers match\n"); \
        } else { \
            printf(COLOR_RED "✗ FAIL: " COLOR_RESET "pointer mismatch\n"); \
            printf("  Expected: %p\n", (void*)(expected)); \
            printf("  Actual:   %p\n", (void*)(actual)); \
        } \
    } while(0)

/* NULLチェック */
# define ASSERT_NULL(ptr) \
    do { \
        g_test_count++; \
        if ((ptr) == NULL) { \
            g_pass_count++; \
            printf(COLOR_GREEN "✓ PASS: " COLOR_RESET #ptr " is NULL\n"); \
        } else { \
            printf(COLOR_RED "✗ FAIL: " COLOR_RESET #ptr " is not NULL (%p)\n", (void*)(ptr)); \
        } \
    } while(0)

# define ASSERT_NOT_NULL(ptr) \
    do { \
        g_test_count++; \
        if ((ptr) != NULL) { \
            g_pass_count++; \
            printf(COLOR_GREEN "✓ PASS: " COLOR_RESET #ptr " is not NULL\n"); \
        } else { \
            printf(COLOR_RED "✗ FAIL: " COLOR_RESET #ptr " is NULL\n"); \
        } \
    } while(0)

/* テスト結果表示とプログラム終了 */
# define TEST_SUMMARY() \
    do { \
        printf("\n" COLOR_BLUE "=== Test Summary ===" COLOR_RESET "\n"); \
        printf("Passed: %s%d%s/%d tests (%.1f%%)\n", \
               (g_pass_count == g_test_count) ? COLOR_GREEN : COLOR_RED, \
               g_pass_count, COLOR_RESET, g_test_count, \
               g_test_count ? (double)g_pass_count / g_test_count * 100 : 0); \
        return (g_pass_count == g_test_count) ? 0 : 1; \
    } while(0)

/* グローバル変数の初期化 */
# define TEST_INIT() \
    int g_test_count = 0; \
    int g_pass_count = 0;

#endif
