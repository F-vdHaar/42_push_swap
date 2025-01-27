# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 22:07:42 by fvon-der          #+#    #+#              #
#    Updated: 2025/01/11 19:08:17 by fvon-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project names
NAME		= push_swap
BONUS		= checker

# Compiler and flags
CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror
MAKE		= make

# Colors
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
CYAN		= \033[1;36m
RESET		= \033[0m

# Directories
OBJ_DIR		= obj/push_swap
OBJ_BONUS_DIR = obj/checker
SRC_DIR		= src/push_swap
SRC_BONUS_DIR = src/checker
LIBFT_DIR	= lib/libft
GNL_DIR		= lib/gnl
PRINTF_DIR = lib/ft_printf
INCLUDE_DIR = include

# Include paths for libraries and headers
INCLUDE		= -I$(INCLUDE_DIR)  -I$(PRINTF_DIR)/include -I$(LIBFT_DIR)/include -I$(GNL_DIR)/include
LIBRARIES	= -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(GNL_DIR) -lftprintf -lft -lgnl

# Source and Object files
SRC			= $(SRC_DIR)/main.c \
			$(SRC_DIR)/input.c \
			$(SRC_DIR)/list_validation.c \
			$(SRC_DIR)/list_utils.c \
			$(SRC_DIR)/list_utils_add.c \
			$(SRC_DIR)/utils_error.c \
			$(SRC_DIR)/calc_steps.c \
			$(SRC_DIR)/calc_steps_add.c \
			$(SRC_DIR)/finder.c \
			$(SRC_DIR)/libft_add.c \
			$(SRC_DIR)/operations.c \
			$(SRC_DIR)/operations_add.c \
			$(SRC_DIR)/operations_add_2.c \
			$(SRC_DIR)/rotate_type.c \
			$(SRC_DIR)/rotation_func.c \
			$(SRC_DIR)/sorter.c \
			$(SRC_DIR)/sorter_add.c
			

SRC_BONUS	= $(SRC_BONUS_DIR)/checker.c
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS	= $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
# Exclude push_swap main.o from bonus object files
ADD_OBJS	= $(filter-out $(OBJ_DIR)/main.o, $(OBJ))


# Leak checking
LEAKS 		= valgrind
LEAKS_FILE	= valgrind-out.txt
LF 			= --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(LEAKS_FILE) ./$(NAME) 69 6 3 89 67  -7 9 


# Targets
all: | $(OBJ_DIR) $(NAME)
bonus: | $(OBJ_BONUS_DIR) $(OBJ_DIR) $(BONUS)
# Debug target
debug: CFLAGS += -g
debug: re

# Ensure directories exist
$(OBJ_DIR):
	@echo "Creating directory: $(OBJ_DIR)"
	@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@echo "Creating directory: $(OBJ_BONUS_DIR)"
	@mkdir -p $(OBJ_BONUS_DIR)


# Ensure libs are built if they doesn't exist
$(LIBFT_DIR)/libft.a:
	@echo "$(CYAN)Checking for libft library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a: $(LIBFT_DIR)/libft.a
	@echo "$(CYAN)Checking for ft_printf library...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)
	
$(GNL_DIR)/libgnl.a:
	@echo "$(CYAN)Checking for GNL library...$(RESET)"
	@$(MAKE) -C $(GNL_DIR)


# Build object files for main project
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(LIBFT_DIR)/libft.a $(GNL_OBJ_DIR) $(PRINTF_DIR)/libftprintf.a
	@echo "$(YELLOW)$(NAME): Compiling $< into $@...$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

# Build object files for bonus
$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR) $(LIBFT_DIR)/libft.a $(GNL_OBJ_DIR) $(PRINTF_DIR)/libftprintf.a
	@echo "$(YELLOW)$(BONUS): Compiling $< into $@...$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

# Build the main executable
$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a 
	@echo "Linking $(NAME) with $(LIBRARIES)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDE) $(LIBRARIES)
	@echo "$(NAME) built successfully."

# Build the bonus executable
$(BONUS): $(OBJ_BONUS) $(ADD_OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(GNL_OBJS) 
	@echo "Linking $(BONUS) with $(LIBFT_DIR)/libft.a and other object files"
	@$(CC) $(FLAGS) $(ADD_OBJS) $(OBJ_BONUS) $(GNL_OBJS) -o $(BONUS) $(INCLUDE) $(LIBRARIES)
	@echo "$(BONUS) built successfully."

leaks:
	@$(MAKE) debug
	@$(LEAKS) $(LF)
	@echo "$(GREEN)Leaks log : $(LEAKS_FILE) $(RESET)\n\n"

cleanleaks:
	$(RM) $(LEAKS_FILE)
	@echo "$(GREEN)Leaks log file deleted.$(RESET)\n\n"
	
# Clean object files
clean:
	@echo "Cleaning object files..."
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(OBJ_BONUS_DIR)
	@echo "Object files cleaned."

# Clean all files
fclean: clean
	@echo "Cleaning executables and libraries..."
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(GNL_DIR)
	@echo "All files cleaned."

# Rebuild everything
re: fclean all
	@echo "Rebuilding everything..."

.PHONY: all clean fclean re bonus debug leaks cleanleaks
