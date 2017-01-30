/*
** generate_commands_list_utils.c for generate_commands_list_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr 10 13:14:27 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 22:32:41 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my.h"
#include "myprintf.h"
#include "mysh.h"
#include "parser.h"

char		*extract_command(char *line)
{
  char		*cmd;
  int		i;
  int		j;

  if ((cmd = malloc(sizeof(*cmd) * (my_strlen(line) + 1))) == NULL)
    return (myeprintf(ERR_MALLOC), NULL);
  i = 0;
  j = 0;
  while (line && line[i])
    {
      if ((line[i] == '"' || line[i] == '\'') &&
	  (i == 0 || line[i - 1] != '\\'))
	i++;
      else
	cmd[j++] = line[i++];
    }
  cmd[j] = 0;
  return (cmd);
}

int		generate_cmd_check_ambiguous_redi(int j,
						  t_cmd **cmd,
						  t_list **list,
						  int *is_redir_err)
{
  (*cmd)->command = (*cmd)->options[0];
  (*cmd)->redirect[j].file = NULL;
  if (j > 1 && !my_strcmp((*cmd)->redirect[0].type, (*cmd)->redirect[1].type))
    {
      if ((*cmd)->redirect[1].type[0] == OP_R_REDIRECT[0])
	my_puterr(ERROR_4);
      else
	my_puterr(ERROR_5);
      *list = NULL;
      *is_redir_err = 1;
      return (0);
    }
  return (1);
}

void		generate_cmd_token_operator(t_list2 **tmp,
					    t_cmd **cmd,
					    int i,
					    int *j)
{
  t_parser	*parser;

  parser = ((t_parser *)((*tmp)->data));
  (*cmd)->redirect[*j].type = my_strdup(parser->token);
  parser = ((t_parser *)((*tmp)->prev->data));
  (*cmd)->redirect[*j].is_at_begin = (*j == 0 && i == 0);
  (*cmd)->redirect[(*j)++].file = my_strdup(parser->token);
  *tmp = (*tmp)->prev;
}

/*
** Count a type of command in the list
** @parser_list : a doubled linked list containing the tokens and their type
** return : number of type (+ 1 for option type)
*/
int		count_command_type(t_list2 *parser_list,
				   int type,
				   char *ops)
{
  int		i;
  t_list2	*tmp;
  t_parser	*parser;

  i = 0;
  tmp = parser_list;
  while (tmp != NULL)
    {
      parser = ((t_parser *)(tmp->data));
      if (parser != NULL &&
	  parser->type == TOKEN_OPERATOR &&
	  (parser->token[0] == OP_AND[0] ||
	   !my_strcmp(parser->token, OP_DOUBLE_AND) ||
	   !my_strcmp(parser->token, OP_DOUBLE_PIPE)))
	break;
      if (parser->type == type ||
	  (ops != NULL &&
	   type == TOKEN_UNKNOWN &&
	   my_get_char_pos(ops, parser->token[0]) != -1))
	i++;
      tmp = tmp->prev;
    }
  return ((type == TOKEN_OPTION) ? i + 1 : i);
}
