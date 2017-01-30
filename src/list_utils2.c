/*
** list_utils2.c for list_utils2 in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri May 20 22:51:53 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:17:54 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "myprintf.h"
#include "parser.h"
#include "mysh.h"

int		alias_key_exist(t_list *alias, char *key)
{
  char		*tmp;

  if (alias != NULL && key != NULL)
    {
      tmp = alias_key_to_value(alias, key);
      if (tmp == NULL)
	return (0);
      free(tmp);
      return (1);
    }
  return (0);
}

char		*get_alias_value(char *key)
{
  t_list	*tmp;
  char		*tmp_key;

  tmp = g_mysh.alias;
  while (tmp)
    {
      tmp_key = get_env_key(((t_alias_data *)tmp->data)->alias);
      if (tmp_key && !my_strcmp(key, tmp_key))
	return (get_env_value(((t_alias_data *)tmp->data)->alias));
      free(tmp_key);
      tmp = tmp->next;
    }
  return (NULL);
}

void		reset_alias_flag(t_alias_data *data)
{
  data->flag = 0;
}

t_cmd		*alloc_cmd_list(t_list2 *parser_list)
{
  t_cmd		*cmd;
  int		options_size;
  int		redi_size;

  if ((cmd = malloc(sizeof(*cmd))) == NULL)
    return (NULL);
  options_size = count_command_type(parser_list, TOKEN_OPTION, NULL) + 1;
  if ((cmd->options = malloc(sizeof(*(cmd->options)) * options_size)) == NULL)
    return (NULL);
  redi_size = count_command_type(parser_list, TOKEN_UNKNOWN, &OPS[2]) + 1;
  if ((cmd->redirect = malloc(sizeof(*(cmd->redirect)) * (redi_size))) == NULL)
    return (NULL);
  return (cmd);
}
