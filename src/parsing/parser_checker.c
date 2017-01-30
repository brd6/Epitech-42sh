/*
** parser_checker.c for parser_checker in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 03:48:59 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:20:51 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"

static int	is_operator(char *str)
{
  return (!my_strcmp(str, OP_PIPE) ||
	  !my_strcmp(str, OP_AND) ||
	  !my_strcmp(str, OP_R_REDIRECT) ||
	  !my_strcmp(str, OP_RR_REDIRECT) ||
	  !my_strcmp(str, OP_L_REDIRECT) ||
	  !my_strcmp(str, OP_LL_REDIRECT) ||
	  !my_strcmp(str, OP_DOUBLE_AND) ||
	  !my_strcmp(str, OP_DOUBLE_PIPE));
}

static int	check_op_pipe(t_list2 *list, char *str)
{
  t_list2	*tmp;
  t_parser	*prev_token;

  (void)(str);
  tmp = list;
  while (tmp != NULL)
    {
      prev_token = ((t_parser *)(tmp->data));
      if (prev_token->type == TOKEN_OPERATOR &&
	  prev_token->token[0] == OP_R_REDIRECT[0] && tmp->next == NULL)
	return (my_puterr(ERROR_4), 0);
      tmp = tmp->next;
    }
  return (1);
}

int		check_str_operator(t_list2 *list, char *str)
{
  t_parser	*prev_token;

  prev_token = NULL;
  if (list != NULL)
    prev_token = ((t_parser *)(list->data));
  if (!is_operator(str))
    return (my_puterr(ERROR_1), 0);
  if (prev_token != NULL)
    {
      if (str[0] != OP_SIMPLE_AND[0] &&
	  my_get_char_pos(&OPS[2], str[0]) != -1 &&
	  prev_token->type == TOKEN_OPERATOR &&
	  my_get_char_pos(OPS, str[0]) != -1)
        return (my_puterr(ERROR_2), 0);
      if (prev_token->type == TOKEN_OPERATOR &&
	  my_get_char_pos(&OPS[1], str[0]) != -1)
        return (my_puterr(ERROR_1), 0);
      if (str[0] == OP_PIPE[0] && !check_op_pipe(list, str))
	return (0);
    }
  return (1);
}
