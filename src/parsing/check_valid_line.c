/*
** check_valid_line.c for check_valid_line in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 01:17:35 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:17:02 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"
#include "mysh.h"

static int	last_redirection_null_n_pipe(t_list2 *list)
{
  t_parser	*parser;

  parser = (t_parser *)(list->data);
  if (parser->type == TOKEN_OPERATOR)
    {
      if (my_get_char_pos(&OPS[2], parser->token[0]) != -1)
	{
	  if (!my_strcmp(parser->token, OP_DOUBLE_AND))
	    return (my_puterr(ERROR_1), 0);
	  else
	    return (my_puterr(ERROR_2), 0);
	}
      else if (list->next != NULL)
	{
	  parser = (t_parser *)(list->next->data);
	  if (my_get_char_pos(&OPS[2], parser->token[0]) != -1)
	    return (my_puterr(ERROR_2), 0);
	}
      parser = (t_parser *)(list->data);
      if (!my_strcmp(parser->token, OP_PIPE))
	return (my_puterr(ERROR_1), 0);
    }
  return (1);
}

static int	last_redirection_after_cmd(t_list2 *list)
{
  t_parser	*parser;

  if (list->next != NULL)
    {
      parser = (t_parser *)(list->data);
      if (((parser->type == TOKEN_COMMAND || parser->type == TOKEN_OPTION) &&
	   (parser = (t_parser *)(list->next->data)) != NULL &&
	   parser->type == TOKEN_OPERATOR &&
	   my_get_char_pos(&OPS[2], parser->token[0]) != -1) &&
	  list->next->next == NULL)
	return (my_puterr(ERROR_1), 0);
    }
  return (1);
}

static int	check_last_cmd_error(t_list2 *list)
{
  if (list != NULL &&
      (!last_redirection_null_n_pipe(list) ||
       !last_redirection_after_cmd(list)))
    return (0);
  return (1);
}

static void	delete_unless_operator_at_end(t_list2 **list)
{
  t_parser	*parser;

  parser = (t_parser *)((*list)->data);
  if (parser->token[0] == OP_AND[0])
    my_rm_elem_in_list2_begin(list);
}

t_list		*check_valid_line(char *line)
{
  t_list2	*list;

  if ((my_strlen(line) > MAX_CMD_LEN) ||
      !(line = alias_replacing(line)) ||
      ((list = parsing_line(line)) == NULL))
    return (NULL);
  delete_unless_operator_at_end(&list);
  if (!check_last_cmd_error(list))
    return (NULL);
  return (generate_commands_list(list));
}
