##
## Makefile for 42sh in /home/bongol_b/Epitech-rendu/PSU_2015_42sh
## 
## Made by Berdrigue BONGOLO BETO
## Login   <bongol_b@epitech.net>
## 
## Started on  Thu May  5 16:44:09 2016 Berdrigue BONGOLO BETO
## Last update Fri Jun 10 13:32:47 2016 bruel
##

CC =		gcc -g3

RM =		rm -f

NAME =		42sh

##
## Flags ################################################################
##
CFLAGS =	-W -Wall
CFLAGS +=	-I./include/ -I./lib/my/include/ -I./lib/myprintf
LDFLAGS +=	-L./lib -lmy -L./lib/myprintf -lmyprintf

##
## Sources ##############################################################
##
SRC_PATH =	src/
P_PARSING =	$(SRC_PATH)parsing/
P_BUILTINS =	$(SRC_PATH)builtins/
P_ECHO =	$(P_BUILTINS)echo/
P_EXEC =	$(SRC_PATH)exec/

SRCS	= 	$(SRC_PATH)main.c					\
		$(SRC_PATH)free_mysh.c					\
		$(SRC_PATH)signal_handler.c				\
		$(SRC_PATH)utils.c					\
		$(SRC_PATH)list_utils.c					\
		$(SRC_PATH)list_utils2.c				\
		$(SRC_PATH)env_util.c					\
		$(SRC_PATH)env_util2.c					\
		$(SRC_PATH)extract_env_key.c				\
		$(SRC_PATH)extract_escaped_sequence.c			\
		$(SRC_PATH)get_globs.c					\
		$(SRC_PATH)my_heredoc.c					\
		$(SRC_PATH)epur_str.c					\
		$(SRC_PATH)prompt_display.c				\
		$(SRC_PATH)read_config_file.c				\
		$(SRC_PATH)alias_replacing.c				\
		$(SRC_PATH)tilde_replacing.c				\
		$(SRC_PATH)read_42sh_file.c				\
		$(SRC_PATH)variables_list_utils.c			\
		\
		 $(P_PARSING)check_valid_line.c				\
		 $(P_PARSING)check_valid_line_utils.c			\
		 $(P_PARSING)parser_checker.c				\
		 $(P_PARSING)parser_checker2.c				\
		 $(P_PARSING)parser_utils.c				\
		 $(P_PARSING)generate_commands_list.c			\
		 $(P_PARSING)generate_commands_list_utils.c		\
		 $(P_PARSING)generate_commands_list_utils2.c		\
		 \
		 $(P_BUILTINS)init_builtins.c				\
		 $(P_BUILTINS)builtin_exit.c				\
		 $(P_BUILTINS)builtin_cd.c				\
		 $(P_BUILTINS)builtin_env.c				\
		 $(P_BUILTINS)builtin_setenv.c				\
		 $(P_BUILTINS)builtin_unsetenv.c			\
		 $(P_BUILTINS)builtin_alias.c				\
		 $(P_BUILTINS)builtin_unalias.c				\
		 $(P_BUILTINS)echo/builtin_echo.c			\
		 $(P_BUILTINS)builtin_set.c				\
		 $(P_BUILTINS)builtin_unset.c				\
		 \
		  $(P_ECHO)print_special_char.c				\
		  $(P_ECHO)transcript_env_variables.c			\
		 \
		 $(P_EXEC)exec_multi_cmd.c				\
		 $(P_EXEC)exec_multi_pipes.c				\
		 $(P_EXEC)exec_multi_pipes_util.c			\
		 $(P_EXEC)exec_simple_cmd.c				\
		 $(P_EXEC)exec_utils.c					\
		 $(P_EXEC)fork_action.c					\
		 $(P_EXEC)redirect_cmd.c				\
		 $(P_EXEC)get_bin_path.c				\
		 $(P_EXEC)exec_builtins.c

##
## Compilations #########################################################
##
OBJS =		$(SRCS:.c=.o)

all:		libmy libmyprintf $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

libmy:
		$(MAKE) -C lib/my

libmyprintf:
		$(MAKE) -C lib/myprintf


##
## Cleaning #############################################################
##
clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C lib/my
		$(MAKE) clean -C lib/myprintf

fclean:		clean
		$(RM) $(NAME)
		$(MAKE) fclean -C lib/my
		$(MAKE) fclean -C lib/myprintf

##
## ######################################################################
##
re:		fclean all

.PHONY:		all libmy libmyprintf clean fclean re
