/*
** builtin_set.c for tek in /home/fougea_a/rendu/Programmation Shell/PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Fri Jun  3 17:54:10 2016 fougea_a
** Last update Sun Jun  5 00:00:01 2016 Berdrigue Bongolo-Beto
*/

#include <stddef.h>
#include <stdlib.h>
#include "mysh.h"
#include "myprintf.h"
#include "my.h"

static void	show_variables(void)
{
  t_list	*curr;
  char		*key;
  char		*value;

  curr = g_mysh.variables;
  while (curr)
    {
      key = get_env_key(curr->data);
      myprintf("%s", key);
      if ((value = get_env_value(curr->data)))
	myprintf("\t%s", value);
      myprintf("\n");
      if (!my_strcmp(key, "_") && value != NULL)
	myprintf("\n");
      free(key);
      free(value);
      curr = curr->next;
    }
}

static int		syntax_set_key(char *key)
{
  int			i;

  if (!is_alpha(key[0]) && key[0] != '_')
    return (myeprintf(ERR_SETENV_VARNAME1, "set"), 0);
  i = 0;
  while (key && key[i] && key[i] != '=')
    {
      if (!is_alpha(key[i]) && !is_num(key[i]) && key[i] != '_')
	return ((myeprintf(ERR_SETENV_VARNAME2, "set"), 0));
      i++;
    }
  return (1);
}

int		key_cmp(void *data, void *data_ref)
{
  char		*key;
  char		*key_ref;

  if (!(key_ref = get_env_key((char *)data_ref)) ||
      !(key = get_env_key((char *)data)))
    return (-1);
  return (my_strcmp(key, key_ref));
}

static int	builtin_setvar(t_cmd *cmd, char *_value)
{
  t_list	*tmp;
  char		*key;
  char		*value;

  if (!(key = get_env_key(_value)) ||
      !(value = get_env_value(_value)))
    return (!(cmd->status = 1));
  if (my_strcmp(key, "_") == 0)
    return (!(cmd->status = 0));
  if (env_key_exist(g_mysh.variables, key))
    {
      tmp = my_find_node_eq_in_list(g_mysh.variables, key, find_key);
      tmp->data = my_strdup(_value);
      return (cmd != NULL ? !(cmd->status = 0) : 0);
    }
  else
    {
      _value = epur_str(_value, "'\"", -1);
      if (!my_add_elem_in_list_end(&g_mysh.variables, _value))
	return (my_puterr(ERR_SET_VAR), cmd != NULL ? !(cmd->status = 1) : 0);
      my_sort_list(&g_mysh.variables, key_cmp);
    }
  return (cmd != NULL ? !(cmd->status = 0) : 0);
}

int		builtin_set(t_cmd *cmd)
{
  if (cmd->options[1] == NULL)
    {
      show_variables();
      return (!(cmd->status = 0));
    }
    if (!syntax_set_key(cmd->options[1]))
    {
      cmd->status = 1;
      return (GO_ON);
    }
  return (builtin_setvar(cmd, cmd->options[1]));
}
