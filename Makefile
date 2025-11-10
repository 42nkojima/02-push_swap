# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 19:32:33 by nkojima           #+#    #+#              #
#    Updated: 2025/11/10 14:28:20 by nkojima          ###   ########.fr        #
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
CFLAGS = -Wall -Werror -Wextra

# ===============================
#         Directory Paths       #
# ===============================
LIBS_DIR = libs

SRC_DIR = src
OBJ_DIR = obj

# ===============================
#         Source Files          #
# ===============================
SRCS =  main.c \
		entities/stack.c \
		entities/stack_operations.c \
		interfaces/input/input_tokenizer.c \
		interfaces/input/input_validator.c \
		interfaces/input/input_number_parser.c \
		interfaces/input/input_parser.c \
		interfaces/operations/swap_operations.c \
		interfaces/operations/push_operations.c \
		interfaces/operations/rotate_operations.c \
		interfaces/operations/reverse_rotate_operations.c \
		usecases/sort_utils.c \
		usecases/sort_small.c \
		usecases/sort_large.c \
		usecases/solve_push_swap.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ===============================
#            Libraries          #
# ===============================
LIBS_SRCS = ft_isdigit.c \
            ft_memcpy.c \
            ft_putchar_fd.c \
            ft_putnbr_fd.c \
            ft_putstr_fd.c \
            ft_split.c \
            ft_strdup.c \
            ft_strjoin.c \
            ft_strlen.c

LIBS_OBJ_FILES = $(addprefix $(OBJ_DIR)/libs/, $(LIBS_SRCS:.c=.o))

# ===============================
#         Build Rules           #
# ===============================
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBS_OBJ_FILES)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LIBS_OBJ_FILES)
	@echo "$(NAME): $(GREEN)object files were created $(RESET)"
	@echo "$(NAME): $(YELLOW)$(NAME)$(RESET) $(GREEN)was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(LIBS_DIR) -c -o $@ $<
	@echo "$(NAME): $(YELLOW)$@$(RESET) $(GREEN)was created$(RESET)"

$(OBJ_DIR)/$(LIBS_DIR)/%.o: $(LIBS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(LIBS_DIR) -c -o $@ $<
	@echo "$(NAME): $(YELLOW)$@$(RESET) $(GREEN)was created$(RESET)"

# ===============================
#         Clean Rules           #
# ===============================
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(NAME): $(YELLOW)$(OBJ_DIR)$(RESET) $(RED)was deleted$(RESET)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(NAME): $(YELLOW)$(NAME)$(RESET) $(RED)was deleted$(RESET)"; \
	fi

re: fclean all

# ===============================
#         Test Rules            #
# ===============================
test:
	@bash tests/test_input_validation.sh

.PHONY: all clean fclean re test
