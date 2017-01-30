/*
** builtin_setenv.c for builtin_setenv in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Apr  6 23:58:22 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:16:15 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "myprintf.h"

int		syntax_env_key(char *key)
{
  int		i;

  if (!is_alpha(key[0]) && key[0] != '_')
    return (myeprintf(ERR_SETENV_VARNAME1, "setenv"), 0);
  i = 0;
  while (key && key[i])
    {
      if (!is_alpha(key[i]) && !is_num(key[i]) && key[i] != '_')
	return ((myeprintf(ERR_SETENV_VARNAME2, "setenv"), 0));
      i++;
    }
  return (1);
}

int		builtin_setenv_cond(t_list *my_env, char **args)
{
  t_list	*tmp;
  char		*new_elem;

  new_elem = concat_two_str(args[1], args[2], "=");
  if (env_key_exist(my_env, args[1]))
    {
      tmp = my_find_node_eq_in_list(g_mysh.my_env, args[1], find_key);
      tmp->data = new_elem;
      return (1);
    }
  else
    {
      if (!my_add_elem_in_list_end(&g_mysh.my_env, new_elem))
	return (my_puterr(ERR_SETENV_MALLOC), 0);
      return (1);
    }
}

int		builtin_setenv(t_cmd *cmd)
{
  if (cmd->options[1] == NULL)
    return (builtin_env(cmd));
  if (cmd->options[2] != NULL && cmd->options[3] != NULL)
    return (myeprintf(ERR_SETENV_ARG), !(cmd->status = 1));
  if (!syntax_env_key(cmd->options[1]))
    {
      cmd->status = 1;
      return (GO_ON);
    }
  cmd->status = 0;
  return (builtin_setenv_cond(g_mysh.my_env, cmd->options));
}
