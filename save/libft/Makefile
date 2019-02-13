# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpayen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:09:19 by fpayen            #+#    #+#              #
#    Updated: 2019/01/12 16:04:46 by fpayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp\
	  ft_memalloc ft_memdel ft_memswap \
	  ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
	  ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_strnlen\
	  ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi\
	  ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit\
	  ft_strndup ft_strrcpy ft_strrdup ft_strccat ft_strclen\
	  get_next_line\
	  ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper\
	  ft_tolower\
	  ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd\
	  ft_putendl_fd ft_putnbr_fd ft_putarr\
	  ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_lstlen\
	  ft_lstend ft_lstappend ft_lstpull_content ft_lstpull_size\
	  ft_atoi ft_itoa ft_abs ft_itoa_base ft_intcmp\

SRCDIR = srcs/
OBJDIR = obj/
INCDIR = includes/

OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(SRC)))

RED = \033[0;31m
LRED = \033[1;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
LBLUE = \033[1;34m
NOCOLOUR = \033[0m

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
	@target=$(notdir $(basename $@)); \
		[[ $${#target} -lt 11 ]] \
		&& echo "\t$(LBLUE)Compiling $$target...\t\t$(GREEN)\xE2\x9C\x94$(NOCOLOUR)" \
		|| echo "\t$(LBLUE)Compiling $$target...\t$(GREEN)\xE2\x9C\x94$(NOCOLOUR)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\t$(YELLOW)[$(GREEN)libft compiled and ready$(YELLOW)]$(NOCOLOUR)"

clean:
	@/bin/rm -rf $(OBJ) $(OBJDIR)
	@echo "\t$(RED)Removing object files... $(LBLUE)[$(LRED)Complete$(LBLUE)]$(NOCOLOUR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t$(RED)Removing library file... $(LBLUE)[$(LRED)Complete$(LBLUE)]$(NOCOLOUR)"

re: fclean all

.PHONY: all clean fclean re
