/*
** parser_utils.c for parser_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Mar 31 11:58:42 2016 Berdrigue BONGOLO BETO
** Last update Wed May 25 02:05:54 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"
#include "parser.h"
#include "mysh.h"

void		free_cmd_data(void *data)
{
  t_cmd		*cmd;
  int		i;

  cmd = data;
  free(cmd->line);
  if (!cmd->is_pipe_line)
    {
      my_free_wordtab(cmd->options);
      i = 0;
      while (cmd->redirect[i].file)
	{
	  free(cmd->redirect[i].file);
	  free(cmd->redirect[i].type);
	  i++;
	}
      free(cmd->redirect);
    }
  free(cmd);
  cmd = NULL;
}

void		free_parser_data(void *data)
{
  t_parser	*parser;

  parser = data;
  free(parser->token);
  free(parser);
  parser = NULL;
}

char		*parser_list_to_str(t_list2 *list)
{
  t_list2	*curr;
  char		*str;
  t_parser	*parser;

  curr = list;
  if (curr == NULL)
    return (NULL);
  while (curr->next != NULL)
    curr = curr->next;
  str = NULL;
  while (curr != NULL)
    {
      parser = ((t_parser *)(curr->data));
      str = concat_two_str(str, parser->token, NULL);
      if (curr->prev != NULL &&
	  parser->token[my_strlen(parser->token) - 1] != ' ')
	str = concat_two_str(str, " ", NULL);
     curr = curr->prev;
    }
  return (str);
}
