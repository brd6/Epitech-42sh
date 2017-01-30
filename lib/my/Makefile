##
## Makefile for libmy in /home/bongol_b/rendu/Piscine_C_workshoplib/lib/my
## 
## Made by berdrigue bongolo-beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Fri Oct 16 01:07:43 2015 berdrigue bongolo-beto
## Last update Fri Jun  3 22:54:13 2016 Berdrigue BONGOLO BETO
##

CC	= 	gcc

RM	= 	rm -f

AR	= 	ar cr

CFLAGS	= 	-I./include

NAME	= 	../libmy.a

SRCS	=	./get_next_line.c \
		./my_add_elem_in_list2_begin.c \
		./my_add_elem_in_list2_end.c \
		./my_add_elem_in_list_begin.c \
		./my_add_elem_in_list_end.c \
		./my_add_list_to_list2.c \
		./my_add_list_to_list.c \
		./my_apply_elm_eq_in_list2.c \
		./my_apply_elm_eq_in_list.c \
		./my_apply_on_list2.c \
		./my_apply_on_list.c \
		./my_apply_on_rev_list2.c \
		./my_find_elm_eq_in_list2.c \
		./my_find_elm_eq_in_list.c \
		./my_find_node_eq_in_list.c \
		./my_free_list2.c \
		./my_free_list.c \
		./my_free_wordtab.c \
		./my_get_char_pos.c \
		./my_getnbr.c \
		./my_itoa.c \
		./my_list2_copy.c \
		./my_list2_rev_copy.c \
		./my_list2_size.c \
		./my_list2_to_wordtab.c \
		./my_list_copy.c \
		./my_list_rev_copy.c \
		./my_list_size.c \
		./my_list_to_wordtab.c \
		./my_nbr_len.c \
		./my_params_in_list2.c \
		./my_params_in_list.c \
		./my_putchar.c \
		./my_puterr.c \
		./my_put_nbr.c \
		./my_putstr.c \
		./my_rev_list2.c \
		./my_rev_list.c \
		./my_rm_all_eq_from_list2.c \
		./my_rm_all_eq_from_list.c \
		./my_rm_elem_in_list2_begin.c \
		./my_rm_elem_in_list2_end.c \
		./my_rm_elem_in_list_end.c \
		./my_rm_el_from_list2.c \
		./my_rm_el_from_list.c \
		./my_show_wordtab.c \
		./my_strcat.c \
		./my_strcmp.c \
		./my_strcpy.c \
		./my_strdup.c \
		./my_str_isalpha.c \
		./my_str_isalphanum.c \
		./my_str_islower.c \
		./my_str_isnum.c \
		./my_str_isupper.c \
		./my_strlen.c \
		./my_strncmp.c \
		./my_strncpy.c \
		./my_str_replace.c \
		./my_str_split.c \
		./my_strstr.c \
		./my_wordtab_count.c \
		./my_wordtab_search.c \
		./my_wordtab_to_str.c \
		./my_wordtab_word_count.c \
		./my_strncat.c \
		./mystrcat.c \
		./my_tabdup.c \
		./my_sort_list.c \

OBJS	= 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	$(CC) -c $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re	: fclean all

.PHONY: clean, re, all, fclean
