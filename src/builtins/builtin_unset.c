/*
** builtin_unset.c for builtin_unset in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  4 00:18:54 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:14:09 2016 fougea_a
*/

#include <stddef.h>
#include "mysh.h"
#include "my.h"
#include "myprintf.h"

static int	search_set_value(char *value, char *value2)
{
  return (my_strcmp(get_env_key(value), value2));
}

int		builtin_unset(t_cmd *cmd)
{
  if (cmd->options[1] == NULL)
    return (myeprintf(ERR_UNSETENV_ARG, "unset"), !(cmd->status = 1));
  if (cmd->options[1] != NULL &&
      env_key_exist(g_mysh.variables, cmd->options[1]))
    my_rm_el_from_list(&g_mysh.variables, cmd->options[1], search_set_value);
  return (!(cmd->status = 0));
}
