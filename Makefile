SRCS		= $(addprefix srcs/, algorithms.c \
		  common_utils.c \
		  ft_lists.c \
		  ft_split.c \
		  parsing.c \
		  push.c \
		  push_swap.c \
		  reverse_rotate.c \
		  rotate.c \
		  swap.c)

BONUS_SRCS	= $(addprefix srcs/, checker_bonus.c \
		  common_utils.c \
		  ft_lists.c \
		  ft_split.c \
		  get_next_line_bonus.c \
		  get_next_line_utils_bonus.c \
		  parsing.c \
		  push.c \
		  reverse_rotate.c \
		  rotate.c \
		  swap.c)

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(BONUS_SRCS:.c=.o)

INCS 		= includes/push_swap.h

NAME 		= push_swap

BONUS_NAME	= checker

CC		= gcc

RM		= rm -rf

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		@${CC} $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 165)Compiling \"$(NAME)\": $(shell tput sgr0)"
			@${CC} $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"
			@make -s norminette

bonus:		$(BONUS_NAME)

$(BONUS_NAME): 	$(OBJS_BONUS)
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 165)Compiling \"$(BONUS_NAME)\": $(shell tput sgr0)"
			@${CC} $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"
			@make -s norminette

norminette:
		@if norminette $(SRCS) $(BONUS_SRCS) $(INCS) > /dev/null; then \
			echo "$(shell tput setaf 190)Norminette: $(shell tput setaf 46)[OK]$(shell tput sgr0)"; \
		else \
			echo "$(shell tput setaf 190)Norminette: $(shell tput setaf 196)[KO]$(shell tput sgr0)"; \
		fi
		@sleep 0.2

clean:
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 196)Deleting project's object files: $(shell tput sgr0)"
			@${RM} $(SRCS:.c=.o) $(BONUS_SRCS:.c=.o)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"

fclean:		clean
		@/bin/echo -n "$(shell tput bold)$(shell tput setaf 196)Deleting \"$(NAME)\" and/or \"$(BONUS_NAME)\": $(shell tput sgr0)"
			@${RM} $(NAME) $(BONUS_NAME)
		@echo "$(shell tput bold)$(shell tput setaf 46)[OK]$(shell tput sgr0)"

re:		fclean all

rebonus:	fclean bonus

.PHONY: 	all clean fclean re .c.o bonus rebonus norminette
