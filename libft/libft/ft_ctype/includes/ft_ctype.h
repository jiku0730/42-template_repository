/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:13:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/13 19:13:02 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

#include <stddef.h>
typedef unsigned short ft_ctype_mask_t;
/*─── ビット定義 ─────────────────────────────────────────*/
enum {
    FT_IS_UPPER  = 1u<<0,
    FT_IS_LOWER  = 1u<<1,
    FT_IS_ALPHA  = 1u<<2,
    FT_IS_DIGIT  = 1u<<3,
    FT_IS_XDIGIT = 1u<<4,
    FT_IS_SPACE  = 1u<<5,
    FT_IS_PRINT  = 1u<<6,
    FT_IS_GRAPH  = 1u<<7,
    FT_IS_BLANK  = 1u<<8,  /* ' ' or '\t' */
    FT_IS_CNTRL  = 1u<<9,
    FT_IS_PUNCT  = 1u<<10,
    FT_IS_ALNUM  = 1u<<11
};

/*─── テーブル本体 ─────────────────────────────────────────*/
/* C99 designated initializer, + GCC 拡張の範囲指定が使えます */
static const ft_ctype_mask_t ft_ctype_table[256] = {
    /* 0–31,127 は制御文字 */
    [0 ... 8]   = FT_IS_CNTRL,
    [14 ... 31]   = FT_IS_CNTRL,
    [127]        = FT_IS_CNTRL,

    /* 空白類 */
    [' ']        = FT_IS_SPACE|FT_IS_BLANK|FT_IS_PRINT,
    ['\t']       = FT_IS_SPACE|FT_IS_BLANK|FT_IS_CNTRL,
    ['\n']       = FT_IS_SPACE|FT_IS_CNTRL,
    ['\r']       = FT_IS_SPACE|FT_IS_CNTRL,
    ['\v']       = FT_IS_SPACE|FT_IS_CNTRL,
    ['\f']       = FT_IS_SPACE|FT_IS_CNTRL,

    /* 数字 */
    ['0' ... '9'] = FT_IS_DIGIT|FT_IS_XDIGIT|FT_IS_ALNUM|FT_IS_PRINT|FT_IS_GRAPH,

    /* 大文字 */
    ['A' ... 'F'] = FT_IS_UPPER|FT_IS_ALPHA|FT_IS_XDIGIT|FT_IS_ALNUM|FT_IS_PRINT|FT_IS_GRAPH,
    ['G' ... 'Z'] = FT_IS_UPPER|FT_IS_ALPHA|          FT_IS_ALNUM|FT_IS_PRINT|FT_IS_GRAPH,

    /* 小文字 */
    ['a' ... 'f'] = FT_IS_LOWER|FT_IS_ALPHA|FT_IS_XDIGIT|FT_IS_ALNUM|FT_IS_PRINT|FT_IS_GRAPH,
    ['g' ... 'z'] = FT_IS_LOWER|FT_IS_ALPHA|          FT_IS_ALNUM|FT_IS_PRINT|FT_IS_GRAPH,

    /* 句読点 (graph && !alnum) */
    [33 ... 47]   = FT_IS_PUNCT|FT_IS_PRINT|FT_IS_GRAPH,
    [58 ... 64]   = FT_IS_PUNCT|FT_IS_PRINT|FT_IS_GRAPH,
    [91 ... 96]   = FT_IS_PUNCT|FT_IS_PRINT|FT_IS_GRAPH,
    [123 ... 126] = FT_IS_PUNCT|FT_IS_PRINT|FT_IS_GRAPH,

    /* その他、未指定のインデックスは 0 (= 全て false) */
};

/*─── 関数宣言 ─────────────────────────────────────────*/
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int ft_isascii(int c);
int	ft_iscntrl(int c);
int	ft_isdigit(int c);
int	ft_islower(int c);
int	ft_isgraph(int c);
int	ft_isprint(int c);
int	ft_ispunct(int c);
int	ft_isspace(int c);
int	ft_isupper(int c);
int	ft_isxdigit(int c);
int	ft_isblank(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_isgraph(int c);
int	ft_ispunct(int c);
int ft_tolower(int c);
int ft_toupper(int c);
#endif