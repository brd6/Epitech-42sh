/*
** builtin_unsetenv.c<builtins> for PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Apr  7 00:18:25 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:22:22 2016 fougea_a
*/

#include <stdlib.h>
#include "myprintf.h"
#include "mysh.h"
#include "my.h"
#include "myprintf.h"

static int	search_env_value(char *value, char *value2)
{
  return (my_strcmp(get_env_key(value), value2));
}

int		builtin_unsetenv(t_cmd *cmd)
{
  if (cmd->options[1] == NULL)
    return (myeprintf(ERR_UNSETENV_ARG, "unsetenv"), !(cmd->status = 1));
  if (cmd->options[1] != NULL && env_key_exist(g_mysh.my_env, cmd->options[1]))
    my_rm_el_from_list(&g_mysh.my_env, cmd->options[1], search_env_value);
  return (!(cmd->status = 0));
}
