
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 21:11:39 by kjikuhar          #+#    #+#              #
#    Updated: 2025/09/30 16:44:58 by kjikuhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------
#> options
#-----------------------------------------------------------------------------
BLACK	:=	\033[30m
RED		:=	\033[31m
GREEN	:=	\033[32m
YELLOW	:=	\033[33m
BLUE	:=	\033[96m
MAGENTA	:=	\033[38;5;206m
CYAN	:=	\033[36m
WHITE	:=	\033[37m
RESET	:=	\033[0m
BOLD	:=	\034[1m
DIM		:=	\033[2m
ITALIC	:=	\033[3m
UNDER	:=	\033[4m
BLINK	:=	\033[5m
REVERSE	:=	\033[7m
HIDDEN	:=	\033[8m
PINK	:=	\033[35m

#-----------------------------------------------------------------------------

#▸ variables

#-----------------------------------------------------------------------------

NAME		:=	project-name

#─ compile config ────────────────────────────────────────────────────────────

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -Iincludes -Ilibft

#─ directory name ────────────────────────────────────────────────────────────

SRCDIR		:=	src
MAND 		:=	mandatory
OBJDIR		:=	obj
LIBFT_DIR	:=	libft
LIBFT_A		:=	$(LIBFT_DIR)/libft.a

#─ sources & objects ─────────────────────────────────────────────────────────

#mandatory sources
SRCS_MAND	:=	src/main.c

#bonus sources

SRCS_BONUS	:=

#object files

OBJS_MAND	:=	$(SRCS_MAND:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS_BONUS	:=	$(SRCS_BONUS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# OBJS	 	:=	$(OBJS_MAND) $(OBJS_BONUS)

#-----------------------------------------------------------------------------

#▸ rules

#-----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_MAND)
	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS)  $(OBJS_MAND) -o $@ $(LIBFT_A)
	@echo "$(YELLOW)$(BOLD)========================================="
	@echo "    You can use My $(NAME)!!"
	@echo "=========================================$(RESET)"

# compile object files

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiled ✅ $(WHITE) $(BOLD) $^ $(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $^

# libft
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# clean targets
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# bonus: $(LIBFT_A) $(OBJS_BONUS)
# 	@cp $(LIBFT_A) $(NAME)
# 	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
# 	@ar rcs $(NAME) $(OBJS_BONUS)
# 	@echo "$(YELLOW)$(BOLD)========================================="
# 	@echo "  You can use My Bonus_$(NAME)!!"
# 	@echo "=========================================$(RESET)"

.PHONY: all clean fclean re bonus
