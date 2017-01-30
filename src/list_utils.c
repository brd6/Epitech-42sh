/*
** list_utils.c for list_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 28 19:37:16 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:18:21 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "myprintf.h"
#include "parser.h"
#include "mysh.h"

void		print_list2_handler(void *data)
{
  t_parser	*parser;

  if (data == NULL)
    return;
  parser = ((t_parser *)(data));
  myprintf("'%s' (%d)\n", parser->token, parser->type);
}

int		find_key(char *data, char *data_ref)
{
  int		i;

  i = 0;
  while (data_ref && data_ref[i])
    {
      if (data[i] == '=')
	break;
      if (data_ref[i] != data[i])
	return (1);
      i++;
    }
  return (!(data_ref[i] == '\0'));
}

char		*alias_key_to_value(t_list *alias, char *key)
{
  t_list	*curr;
  t_alias_data	*data;

  if (alias == NULL || key == NULL)
    return (NULL);
  curr = alias;
  while (curr != NULL)
    {
      data = (t_alias_data *)(curr->data);
      if (my_strcmp(get_env_key(data->alias), key) == 0)
	return (get_env_value(data->alias));
      curr = curr->next;
    }
  return (NULL);
}
