/*
** builtin_alias.c for builtin_alias in /home/bongol_b/rendu_ok/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Jan 19 15:44:39 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:16:05 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "myprintf.h"
#include "mysh.h"

static void	show_alias()
{
  t_list	*curr;
  char		*key;
  char		*value;
  int		is_multi_value;

  curr = g_mysh.alias;
  is_multi_value = 0;
  while (curr)
    {
      key = get_env_key(((t_alias_data *)curr->data)->alias);
      value = get_env_value(((t_alias_data *)curr->data)->alias);
      is_multi_value = my_get_char_pos(value, ' ');
      myprintf("%s\t", key);
      if (is_multi_value >= 0)
	my_putchar('(');
      my_putstr(value);
      if (is_multi_value >= 0)
	my_putchar(')');
      my_putchar('\n');
      free(key);
      free(value);
      curr = curr->next;
    }
}

int		alias_find_key(t_alias_data *data, void *data_ref1)
{
  int		i;
  char		*data_ref;

  i = 0;
  data_ref = (char *)(data_ref1);
  if (data == NULL || data_ref == NULL)
    return (1);
  while (data->alias && data->alias[i] != '=')
    {
      if (data->alias[i] != data_ref[i])
	return (1);
      i++;
    }
  return (!(data_ref[i] == '\0' && data->alias[i] == '='));
}

int		builtin_setalias(t_cmd *cmd, char *key, char *value)
{
  t_list	*tmp;
  char		*new_elem;
  t_alias_data	*data;

  new_elem = concat_two_str(key, value, "=");
  if (alias_key_exist(g_mysh.alias, key))
    {
      tmp = my_find_node_eq_in_list(g_mysh.alias, key, alias_find_key);
      ((t_alias_data *)(tmp->data))->alias = new_elem;
      return (cmd != NULL ? !(cmd->status = 0) : 0);
    }
  else
    {
      if ((data = malloc(sizeof(*data))) == NULL)
	return (0);
      data->alias = epur_str(new_elem, "'\"", -1);
      data->flag = 0;
      if (!my_add_elem_in_list_end(&g_mysh.alias, data))
	return (my_puterr(ERR_SET_ALIAS), cmd != NULL ? !(cmd->status = 1) : 0);
    }
  return (cmd != NULL ? !(cmd->status = 0) : 0);
}

int		builtin_alias(t_cmd *cmd)
{
  char		*value;
  const char	**options;

  if (cmd->options[1] == NULL)
    {
      show_alias();
      return (!(cmd->status = 0));
    }
  if (cmd->options[2] == NULL)
    return (!(cmd->status = 0));
  options = (const char **)&(cmd->options[2]);
  value = my_wordtab_to_str(options, ' ');
  return (builtin_setalias(cmd, cmd->options[1], value));
}
