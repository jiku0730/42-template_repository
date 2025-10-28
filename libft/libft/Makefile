# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:00:02 by kjikuhar          #+#    #+#              #
#    Updated: 2025/08/08 18:38:05 by kjikuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	libft.a

# サブライブラリ
CTYPE_LIB	=	ft_ctype/ctype.a
STRINGS_LIB	=	ft_strings/strings.a
STRING_LIB	=	ft_string/ft_string.a
STDIO_LIB	=	ft_stdio/ft_stdio.a
STDLIB_LIB	=	ft_stdlib/ft_stdlib.a
LIST_LIB	=	ft_list/ft_list.a

# 将来追加予定の個別ファイル（コメントアウト）
# SRCS	=	conversion/ft_atoi.c \
#			conversion/ft_itoa.c \
#			...

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

# サブライブラリのビルド
$(CTYPE_LIB):
	@echo "$(CYAN)$(BOLD)Building ctype library...$(RESET)"
	@$(MAKE) -C ft_ctype

$(STRINGS_LIB):
	@echo "$(CYAN)$(BOLD)Building strings library...$(RESET)"
	@$(MAKE) -C ft_strings

$(STRING_LIB):
	@echo "$(CYAN)$(BOLD)Building string library...$(RESET)"
	@$(MAKE) -C ft_string

$(STDIO_LIB):
	@echo "$(CYAN)$(BOLD)Building stdio library...$(RESET)"
	@$(MAKE) -C ft_stdio

$(STDLIB_LIB):
	@echo "$(CYAN)$(BOLD)Building stdio library...$(RESET)"
	@$(MAKE) -C ft_stdlib

$(LIST_LIB):
	@echo "$(CYAN)$(BOLD)Building stdio library...$(RESET)"
	@$(MAKE) -C ft_list

# メインライブラリの作成（サブライブラリのみ）
$(NAME):	$(CTYPE_LIB) $(STRINGS_LIB) $(STRING_LIB) $(STDIO_LIB) $(STDLIB_LIB) $(LIST_LIB)
			@echo "$(MAGENTA)$(BOLD)Creating unified libft.a...$(RESET)"
			@cp $(CTYPE_LIB) $(NAME)
			@ar x $(STRINGS_LIB)
			@ar rcs $(NAME) *.o
			@$(RM) *.o
			@ar x $(STRING_LIB)
			@ar rcs $(NAME) *.o
			@$(RM) *.o
			@ar x $(STDIO_LIB)
			@ar rcs $(NAME) *.o
			@$(RM) *.o
			@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
			@echo "$(YELLOW)$(BOLD)========================================="
			@echo "        You can use My $(NAME)!!"
			@echo "        (Including ctype + strings + string + stdio)"
			@echo "=========================================$(RESET)"

# =========================================
#         You can use My libft.a!!
# =========================================

%.o: %.c
	@echo "Compiled ✅ $(CYAN) $(BOLD) $^ $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
			@$(MAKE) -C ft_ctype clean
			@$(MAKE) -C ft_strings clean
			@$(MAKE) -C ft_string clean
			@$(MAKE) -C ft_stdio clean
			@$(MAKE) -C ft_stdlib clean
			@$(MAKE) -C ft_list clean

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) -C ft_ctype fclean
			@$(MAKE) -C ft_strings fclean
			@$(MAKE) -C ft_string fclean
			@$(MAKE) -C ft_stdio fclean
			@$(MAKE) -C ft_stdlib fclean
			@$(MAKE) -C ft_list fclean

re:			fclean all

test:
	$(MAKE) -C ft_ctype test
	$(MAKE) -C ft_strings test
	$(MAKE) -C ft_string test
	$(MAKE) -C ft_stdio test
	$(MAKE) -C ft_stdlib test

.PHONY:		all clean fclean re test

# カラーコード
BLACK	:=	\033[30m
RED		:=	\033[31m
GREEN	:=	\033[32m
YELLOW	:=	\033[33m
BLUE	:=	\033[96m
MAGENTA	:=	\033[38;5;206m
CYAN	:=	\033[36m
WHITE	:=	\033[37m
RESET	:=	\033[0m
BOLD	:=	\033[1m
