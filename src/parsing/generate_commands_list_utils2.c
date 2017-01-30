/*
** generate_commands_list_utils2.c for generate_commands_list_utils2 in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr 10 14:45:46 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:17:10 2016 fougea_a
*/

#include <stddef.h>
#include "my.h"
#include "parser.h"

t_list2		*goto_next_cmd_in_list(t_list2 *parser_list)
{
  t_list2	*tmp;
  t_parser	*parser;

  tmp = parser_list;
  while (tmp != NULL)
    {
      parser = ((t_parser *)(tmp->data));
      if (parser->type == TOKEN_OPERATOR &&
	  (parser->token[0] == OP_AND[0] ||
	   !my_strcmp(parser->token, OP_DOUBLE_AND) ||
	   !my_strcmp(parser->token, OP_DOUBLE_PIPE)))
	{
	  tmp = tmp->prev;
	  break;
	}
      tmp = tmp->prev;
    }
  return (tmp);
}

void	set_cmd_opertor_flag(t_cmd *cmd, t_list2 *tmp)
{
  t_parser	*parser;

  cmd->cond_separator = SEP_NONE;
  if (tmp != NULL &&
      tmp->next != NULL &&
      (parser = ((t_parser *)(tmp->next->data))))
    {
      if (!my_strcmp(parser->token, OP_DOUBLE_AND))
	cmd->cond_separator = SEP_AND;
      else if (!my_strcmp(parser->token, OP_DOUBLE_PIPE))
	cmd->cond_separator = SEP_OR;
    }
}
