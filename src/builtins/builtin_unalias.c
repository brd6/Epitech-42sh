/*
** builtin_unalias.c for builtin_unalias in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  4 00:20:06 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:13:47 2016 fougea_a
*/

#include <stddef.h>
#include "mysh.h"
#include "my.h"
#include "myprintf.h"

static int	search_alias_value(t_alias_data *data, void *data_ref1)
{
  return (my_strcmp(get_env_key(data->alias), (char *)data_ref1));
}

int		builtin_unalias(t_cmd *cmd)
{
  if (cmd->options[1] == NULL)
    return (myeprintf(ERR_UNSETENV_ARG, "unalias"), !(cmd->status = 1));
  if (cmd->options[1] != NULL && alias_key_exist(g_mysh.alias, cmd->options[1]))
    my_rm_el_from_list(&g_mysh.alias, cmd->options[1], search_alias_value);
  return (!(cmd->status = 0));
}
