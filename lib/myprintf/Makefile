##
## Makefile for tek in /home/fougea_a/rendu/IA/dante/lib
## 
## Made by fougea_a
## Login   <fougea_a@epitech.net>
## 
## Started on  Mon May  2 16:34:32 2016 fougea_a
## Last update Tue May 17 15:22:41 2016 fougea_a
##

NAME =		../libmyprintf.a

CFLAGS =	-W -Wall -Wextra -Werror


################### SOURCES #####################

SRC =		myprintf.c			\
		myprintf_flags.c		\
		myprintf_utils1.c		\
		myprintf_utils2.c		\
		flag_bases.c			\
		flag_chars.c			\
		flag_numbers.c			\
		flag_tabs.c			\

OBJ =		$(SRC:.c=.o)

CC =		gcc


################## DISPLAY #####################

ECHO =		echo

RESET =		"\033[0m"

BLACK =		"\033[30m"
RED =		"\033[31m"
GREEN =		"\033[32m"
YELLOW =	"\033[33m"
BLUE =		"\033[34m"
PINK =		"\033[35m"
CYAN =		"\033[36m"
WHITE =		"\033[37m"

BOLD =		"\033[1m"
UNDERLINE =	"\033[4m"

ARROW_L =	"<----------------"
ARROW_R =	"---------------->"


################## RULES #####################

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(ECHO) $(GREEN)$(ARROW_R)$(RESET)\
			$(CYAN)$(BOLD)" Making "$(NAME)" "$(RESET)\
			$(GREEN)$(ARROW_L)$(RESET)
		ar rc $(NAME) $(OBJ)
		@$(ECHO) $(CYAN)$(ARROW_R)$(RESET)\
			$(GREEN)$(BOLD)" Terminated "$(RESET)\
			$(CYAN)$(ARROW_L)$(RESET)

clean:
		@$(ECHO) $(PINK)$(ARROW_R)$(RESET)\
			$(RED)$(BOLD)" Cleaning "$(NAME)" "$(RESET)\
			$(PINK)$(ARROW_L)$(RESET)
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
