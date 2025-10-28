/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:56:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/14 12:13:36 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* テスト結果を比較するヘルパー関数 */
void	compare_results(const char *test_name, int ft_result, int std_result)
{
	printf("--- %s %s ---\n", test_name, (ft_result == std_result) ? "✅" : "❌");
	printf("ft_printf返り値: %d\n", ft_result);
	printf("printf返り値: %d\n\n", std_result);
}

int	main(void)
{
	int		ft_ret;
	int		std_ret;
	char	*str;
	void	*ptr;
	void	*null;
	char	*null_str;
	void	*p;

	printf("=====================================\n");
	printf("ft_printf テストプログラム\n");
	printf("=====================================\n\n");
	/* テスト 1: 基本的な文字列 */
	printf("## テスト1: 基本出力\n");
	ft_ret = ft_printf("Hello, world!\n");
	std_ret = printf("Hello, world!\n");
	compare_results("基本文字列", ft_ret, std_ret);
	/* テスト 2: 文字 %c */
	printf("## テスト2: 文字出力 (%%c)\n");
	ft_ret = ft_printf("文字: %c %c %c\n", 'A', '4', '*');
	std_ret = printf("文字: %c %c %c\n", 'A', '4', '*');
	compare_results("複数文字", ft_ret, std_ret);
	/* テスト 3: 特殊文字 */
	printf("## テスト3: 特殊文字出力 (%%c)\n");
	ft_ret = ft_printf("特殊文字: %c %c %c\n", '\t', '\n', 127);
	std_ret = printf("特殊文字: %c %c %c\n", '\t', '\n', 127);
	compare_results("特殊文字", ft_ret, std_ret);
	/* テスト 4: 文字列 %s */
	printf("## テスト4: 文字列出力 (%%s)\n");
	ft_ret = ft_printf("文字列: %s\n", "Hello, 42!");
	std_ret = printf("文字列: %s\n", "Hello, 42!");
	compare_results("基本文字列", ft_ret, std_ret);
	/* テスト 5: 空文字列 */
	printf("## テスト5: 空文字列出力 (%%s)\n");
	ft_ret = ft_printf("空文字列: '%s'\n", "");
	std_ret = printf("空文字列: '%s'\n", "");
	compare_results("空文字列", ft_ret, std_ret);
	/* テスト 6: NULL文字列 */
	printf("## テスト6: NULL文字列出力 (%%s)\n");
	null = NULL;
	null_str = (char *)null;
	ft_ret = ft_printf("NULL文字列: %s\n", (char *)NULL);
	std_ret = printf("NULL文字列: %s\n", (char *)null_str);
	compare_results("NULL文字列", ft_ret, std_ret);
	/* テスト 7: 整数 %d, %i */
	printf("## テスト7: 整数出力 (%%d, %%i)\n");
	ft_ret = ft_printf("正の整数: %d\n", 42);
	std_ret = printf("正の整数: %d\n", 42);
	compare_results("正の整数", ft_ret, std_ret);
	ft_ret = ft_printf("負の整数: %d\n", -42);
	std_ret = printf("負の整数: %d\n", -42);
	compare_results("負の整数", ft_ret, std_ret);
	ft_ret = ft_printf("ゼロ: %d\n", 0);
	std_ret = printf("ゼロ: %d\n", 0);
	compare_results("ゼロ", ft_ret, std_ret);
	ft_ret = ft_printf("INT_MAX: %d\n", INT_MAX);
	std_ret = printf("INT_MAX: %d\n", INT_MAX);
	compare_results("INT_MAX", ft_ret, std_ret);
	ft_ret = ft_printf("INT_MIN: %d\n", INT_MIN);
	std_ret = printf("INT_MIN: %d\n", INT_MIN);
	compare_results("INT_MIN", ft_ret, std_ret);
	/* テスト 8: 符号なし整数 %u */
	printf("## テスト8: 符号なし整数出力 (%%u)\n");
	ft_ret = ft_printf("正の整数: %u\n", 42);
	std_ret = printf("正の整数: %u\n", 42);
	compare_results("正の整数", ft_ret, std_ret);
	ft_ret = ft_printf("大きな整数: %u\n", 4294967295u);
	std_ret = printf("大きな整数: %u\n", 4294967295u);
	compare_results("UINT_MAX", ft_ret, std_ret);
	ft_ret = ft_printf("負の整数: %u\n", -42);
	std_ret = printf("負の整数: %u\n", -42);
	compare_results("負の整数 → 符号なし変換", ft_ret, std_ret);
	/* テスト 9: 16進数 (小文字) %x */
	printf("## テスト9: 16進数出力 (小文字 %%x)\n");
	ft_ret = ft_printf("16進数(小): %x\n", 42);
	std_ret = printf("16進数(小): %x\n", 42);
	compare_results("小さい値", ft_ret, std_ret);
	ft_ret = ft_printf("16進数(小): %x\n", 0xabcdef);
	std_ret = printf("16進数(小): %x\n", 0xabcdef);
	compare_results("大きい値", ft_ret, std_ret);
	ft_ret = ft_printf("16進数(小): %x\n", 0);
	std_ret = printf("16進数(小): %x\n", 0);
	compare_results("ゼロ", ft_ret, std_ret);
	/* テスト 10: 16進数 (大文字) %X */
	printf("## テスト10: 16進数出力 (大文字 %%X)\n");
	ft_ret = ft_printf("16進数(大): %X\n", 42);
	std_ret = printf("16進数(大): %X\n", 42);
	compare_results("小さい値", ft_ret, std_ret);
	ft_ret = ft_printf("16進数(大): %X\n", 0xabcdef);
	std_ret = printf("16進数(大): %X\n", 0xabcdef);
	compare_results("大きい値", ft_ret, std_ret);
	/* テスト 11: ポインタ %p */
	printf("## テスト11: ポインタ出力 (%%p)\n");
	ptr = malloc(1);
	ft_ret = ft_printf("ポインタ: %p\n", ptr);
	std_ret = printf("ポインタ: %p\n", ptr);
	compare_results("有効なポインタ", ft_ret, std_ret);
	free(ptr);
	ft_ret = ft_printf("NULLポインタ: %p\n", NULL);
	std_ret = printf("NULLポインタ: %p\n", NULL);
	compare_results("NULLポインタ", ft_ret, std_ret);
	/* テスト 12: パーセント %% */
	printf("## テスト12: パーセント出力 (%%%%)\n");
	ft_ret = ft_printf("パーセント記号: %%\n");
	std_ret = printf("パーセント記号: %%\n");
	compare_results("パーセント", ft_ret, std_ret);
	/* テスト 13: 複合的なテスト */
	printf("## テスト13: 複合テスト\n");
	ft_ret = ft_printf("複合: %c %s %p %d %i %u %x %X %%\n", 'A', "str", ptr, 42,
			-42, 42, 42, 42);
	std_ret = printf("複合: %c %s %p %d %i %u %x %X %%\n", 'A', "str", ptr, 42,
			-42, 42, 42, 42);
	compare_results("複合出力", ft_ret, std_ret);
	/* テスト 14: 連続したパーセント */
	printf("## テスト14: 連続パーセント出力\n");
	ft_ret = ft_printf("連続%%記号: %%%%%%\n");
	std_ret = printf("連続%%記号: %%%%%%\n");
	compare_results("連続パーセント", ft_ret, std_ret);
	/* テスト 15: エッジケーステスト - 長い文字列 */
	printf("## テスト15: 長い文字列\n");
	str = "This is a very long string that is designed \
	to test the buffer handling capabilities of \
	the printf function and ensure it correctly manages memory and \
	returns the right character count.";
	ft_ret = ft_printf("長い文字列: %s\n", str);
	std_ret = printf("長い文字列: %s\n", str);
	compare_results("長い文字列", ft_ret, std_ret);
	/* テスト 16: 様々な文字組み合わせ */
	printf("## テスト16: 様々な組み合わせ\n");
	ft_ret = ft_printf("Mix %d %s %x %% %c\n", 123, "test", 0xabc, 'Z');
	std_ret = printf("Mix %d %s %x %% %c\n", 123, "test", 0xabc, 'Z');
	compare_results("様々な組み合わせ", ft_ret, std_ret);
	/* テスト 17: %単体 */
	printf("## テスト 17: %%単体\n");
	ft_ret = ft_printf("%");
	// std_ret = printf("%");
	// compare_results("%単体", ft_ret, std_ret);
	compare_results("%単体", ft_ret, -1);
	printf("=====================================\n");
	printf("テスト完了\n");
	printf("=====================================\n");
	printf("=====================================\n");
	printf("ft_printf テストプログラム\n");
	printf("=====================================\n\n");
	/*-----------------------------------------------------------------*/
	/* 1. 文字出力 (%c) : 0 フラグ・幅指定                              */
	/*-----------------------------------------------------------------*/
	printf("## B-1 文字 + 幅 / 0 フラグ\n");
	ft_ret = ft_printf("'%05c' '%-5c'\n", 'A', 'B');
	std_ret = printf("'%05c' '%-5c'\n", 'A', 'B');
	compare_results("%c + flag", ft_ret, std_ret);
	/*-----------------------------------------------------------------*/
	/* 2. 文字列 (%s) : precision・左寄せ                              */
	/*-----------------------------------------------------------------*/
	printf("## B-2 文字列 + 精度 / 左寄せ\n");
	ft_ret = ft_printf("'%-10.5s' '%.3s'\n", "Hello", "World");
	std_ret = printf("'%-10.5s' '%.3s'\n", "Hello", "World");
	compare_results("%s + precision", ft_ret, std_ret);
	/*-----------------------------------------------------------------*/
	/* 3. 整数 (%d / %i) : + / space / 0 / - / precision               */
	/*-----------------------------------------------------------------*/
	printf("## B-3 整数 + 各種フラグ\n");
	ft_ret = ft_printf("'%+08.5d' '% 8.5i' '%-8.3d'\n", 42, 42, -42);
	std_ret = printf("'%+08.5d' '% 8.5i' '%-8.3d'\n", 42, 42, -42);
	compare_results("%d/%i + flags", ft_ret, std_ret);
	/*-----------------------------------------------------------------*/
	/* 4. 符号なし整数 (%u) : 0 フラグ + precision                     */
	/*-----------------------------------------------------------------*/
	printf("## B-4 符号なし整数 + 0 / 精度\n");
	ft_ret = ft_printf("'%010.6u' '%-10u'\n", 300u, 300u);
	std_ret = printf("'%010.6u' '%-10u'\n", 300u, 300u);
	compare_results("%u + flags", ft_ret, std_ret);
	/*-----------------------------------------------------------------*/
	/* 5. 16進 (%x / %X) : # / 0 / - / precision                       */
	/*-----------------------------------------------------------------*/
	printf("## B-5 16進 + #/0/-/precision\n");
	ft_ret = ft_printf("'%#08.4x' '%-#10X'\n", 0x2a, 0x2a);
	std_ret = printf("'%#08.4x' '%-#10X'\n", 0x2a, 0x2a);
	compare_results("%x/%X + flags", ft_ret, std_ret);
	/*-----------------------------------------------------------------*/
	/* 6. ポインタ (%p) : 幅指定・左寄せ                               */
	/*-----------------------------------------------------------------*/
	printf("## B-6 ポインタ + 幅指定\n");
	p = malloc(1);
	ft_ret = ft_printf("'%20p' '%-20p'\n", p, NULL);
	std_ret = printf("'%20p' '%-20p'\n", p, NULL);
	compare_results("%p + width", ft_ret, std_ret);
	free(p);
	/*-----------------------------------------------------------------*/
	/* 7. 複合テスト                                                    */
	/*-----------------------------------------------------------------*/
	printf("## B-7 複合テスト\n");
	ft_ret = ft_printf("Mix: |%#-08x| |%+10.6d| |% 5.3u| |%-10s|\n", 0xbeef,
			-1234, 987u, "end");
	std_ret = printf("Mix: |%#-08x| |%+10.6d| |% 5.3u| |%-10s|\n", 0xbeef,
			-1234, 987u, "end");
	compare_results("複合(Bonus)", ft_ret, std_ret);
	/*-----------------------------------------------------------------*/
	/* 8. 単体 %                                                        */
	/*-----------------------------------------------------------------*/
	printf("## B-8 %% 単体 (エラー処理)\n");
	ft_ret = ft_printf("%"); /* 未定義動作 → 仕様に合わせて -1 を期待 */
	compare_results("単体%%", ft_ret, -1);
	printf("=====================================\n");
	printf("Bonus テスト完了\n");
	printf("=====================================\n");
	return (0);
}

// #include "ft_stdio.h"
// #include <limits.h>
// #include <stdio.h>

// static void	cmp(const char *fmt, long long n)
// {
// 	int r1, r2;
// 	printf("fmt: \"%s\", arg: %lld\n", fmt, n);
// 	r1 = ft_printf("|");
// 	r1 += ft_printf(fmt, n);
// 	r1 += ft_printf("|\n");
// 	r2 = printf(">");
// 	r2 += printf(fmt, n);
// 	r2 += printf("<\n");
// 	printf("ft:%2d  std:%2d  %s\n\n", r1, r2, (r1 == r2) ? "✅" : "❌");
// }

// int	main(void)
// {
// 	puts("\n=== 0 / + / space flag regression test ===\n");
// 	/* ① “0” + width + 負数 ----------------------------------------- */
// 	cmp("%04d", -14);
// 	cmp("%05d", -15);
// 	cmp("%06d", -16);
// 	/* ② “0” + width + 正数 + “+” flag ------------------------------ */
// 	cmp("%+04d", 14);
// 	cmp("%+06d", 155);
// 	/* ③ “0” + width + 正数 + “space” flag -------------------------- */
// 	cmp("% 04d", 14);
// 	cmp("% 06d", 155);
// 	/* ④ 同じ組み合わせで %i も ------------------------------------- */
// 	cmp("%+05i", -42);
// 	cmp("% 07i", LONG_MIN);
// 	/* ⑤ field width だけ / precision 付きでの確認 ------------------ */
// 	cmp("%8.5d", -42);
// 	cmp("%08.5d", -42); /* ‘0’ は precision があると無効になる   */
// 	return (0);
// }
