# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpayen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 13:46:21 by fpayen            #+#    #+#              #
#    Updated: 2019/01/23 15:22:10 by fpayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a

SRC = main\
	  parsing\
	  parsing_checks\
	  char_to_bit\
	  biggest_square\
	  bit_to_char\
	  mask_manipulation\
	  arr_misc\
	  fuck_the_norm\
	  optimal_solution

SRCDIR = srcs/
OBJDIR = obj/
INCDIR = includes/

OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(SRC)))

RED = \033[0;31m
LRED = \033[1;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
LBLUE = \033[1;34m
CYAN = \033[0;36m
NOCOLOUR = \033[0m

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(DEPS)
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)
	@target=$(notdir $(basename $@)); \
		[[ $${#target} -lt 11 ]] \
		&& echo "\t$(CYAN)Compiling $$target...\t\t$(GREEN)\xE2\x9C\x94$(NOCOLOUR)" \
		|| echo "\t$(CYAN)Compiling $$target...\t$(GREEN)\xE2\x9C\x94$(NOCOLOUR)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	@cd libft && $(MAKE) all
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\n\t$(YELLOW)[$(GREEN)fillit compiled$(YELLOW)]$(NOCOLOUR)"

clean:
	@/bin/rm -rf $(OBJ) $(OBJDIR)
	@cd libft && $(MAKE) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t$(RED)Cleaning fillit binary... $(LBLUE)[$(LRED)Complete$(LBLUE)]$(NOCOLOUR)"
	@cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
