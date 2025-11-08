# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 19:32:33 by nkojima           #+#    #+#              #
#    Updated: 2025/11/08 17:06:38 by nkojima          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===============================
#             Color             #
# ===============================
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

# ===============================
#            Settings           #
# ===============================
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -O2

# ===============================
#         Directory Paths       #
# ===============================
LIB_DIR = lib
LIBFT_PATH = $(LIB_DIR)/libft
PRINTF_PATH = $(LIB_DIR)/ft_printf

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# ===============================
#         Source Files          #
# ===============================
SRCS = main.c
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ===============================
#            Libraries          #
# ===============================
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/ft_printf.a

# ===============================
#         Build Rules           #
# ===============================
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf
	@echo "$(NAME): $(GREEN)object files were created $(RESET)"
	@echo "$(NAME): $(YELLOW)$(NAME)$(RESET) $(GREEN)was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT) $(PRINTF)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(PRINTF_PATH)/include -c -o $@ $<
	@echo "$(NAME): $(YELLOW)$@$(RESET) $(GREEN)was created$(RESET)"

# ===============================
#       Library Dependencies    #
# ===============================
$(LIBFT): | $(LIBFT_PATH)
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(NAME): $(YELLOW)$(LIBFT)$(RESET) $(GREEN)was created$(RESET)"

$(LIBFT_PATH):
	@git clone git@github.com:42nkojima/00-libft.git $(LIBFT_PATH)
	@echo "$(NAME): $(YELLOW)$(LIBFT_PATH)$(RESET) $(GREEN)was cloned$(RESET)"

$(PRINTF): | $(PRINTF_PATH)
	@$(MAKE) -C $(PRINTF_PATH)
	@echo "$(NAME): $(YELLOW)$(PRINTF)$(RESET) $(GREEN)was created$(RESET)"

$(PRINTF_PATH):
	@git clone git@github.com:42nkojima/01-ft_printf.git $(PRINTF_PATH)
	@echo "$(NAME): $(YELLOW)$(PRINTF_PATH)$(RESET) $(GREEN)was cloned$(RESET)"

# ===============================
#         Clean Rules           #
# ===============================
clean:
	@if [ -d $(LIBFT_PATH) ]; then $(MAKE) -C $(LIBFT_PATH) clean; fi
	@if [ -d $(PRINTF_PATH) ]; then $(MAKE) -C $(PRINTF_PATH) clean; fi
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(NAME): $(YELLOW)$(OBJ_DIR)$(RESET) $(RED)was deleted$(RESET)"; \
	fi

fclean: clean
	@if [ -d $(LIBFT_PATH) ]; then $(MAKE) -C $(LIBFT_PATH) fclean; fi
	@if [ -d $(PRINTF_PATH) ]; then $(MAKE) -C $(PRINTF_PATH) fclean; fi
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(NAME): $(YELLOW)$(NAME)$(RESET) $(RED)was deleted$(RESET)"; \
	fi

# Include libraries in clean
distclean: fclean
	@if [ -d $(LIBFT_PATH) ]; then \
		rm -rf $(LIBFT_PATH); \
		echo "$(NAME): $(YELLOW)$(LIBFT_PATH)$(RESET) $(RED)was deleted$(RESET)"; \
	fi
	@if [ -d $(PRINTF_PATH) ]; then \
		rm -rf $(PRINTF_PATH); \
		echo "$(NAME): $(YELLOW)$(PRINTF_PATH)$(RESET) $(RED)was deleted$(RESET)"; \
	fi

re: fclean all

# ===============================
#         Test Rules            #
# ===============================
test: test-input test-operations test-sorting

test-input: $(NAME)
	@bash tests/test_input_validation.sh

test-operations: $(NAME)
	@bash tests/test_operations.sh

test-sorting: $(NAME)
	@bash tests/test_sorting.sh

.PHONY: all clean fclean re distclean test test-input test-operations test-sorting
