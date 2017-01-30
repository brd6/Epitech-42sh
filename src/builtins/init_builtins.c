/*
** init_builtins.c for init_builtins in /home/bongol_b/rendu/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Jan 13 21:26:09 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:16:09 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "myprintf.h"

int		is_builins_cmd(char *cmd, t_my_builtin *builtins)
{
  int		i;

  i = 0;
  while (builtins[i].name != NULL)
    {
      if (my_strcmp(builtins[i].name, cmd) == 0)
	return (i);
      i = i + 1;
    }
  return (-1);
}

static void	init_builtin_struct(t_my_builtin *builtin,
				    char *name,
				    int (*func)(t_cmd *cmd))
{
  builtin->name = name;
  builtin->func = func;
}

t_my_builtin		*init_builtins()
{
  t_my_builtin		*builtins;
  int			i;

  if ((builtins = malloc(sizeof(*builtins) * BUILTIN_NB)) == NULL)
    return (myeprintf(ERR_MALLOC), NULL);
  i = 0;
  init_builtin_struct(&builtins[i++], "exit", &builtin_exit);
  init_builtin_struct(&builtins[i++], "cd", &builtin_cd);
  init_builtin_struct(&builtins[i++], "env", &builtin_env);
  init_builtin_struct(&builtins[i++], "setenv", &builtin_setenv);
  init_builtin_struct(&builtins[i++], "unsetenv", &builtin_unsetenv);
  init_builtin_struct(&builtins[i++], "alias", &builtin_alias);
  init_builtin_struct(&builtins[i++], "unalias", &builtin_unalias);
  init_builtin_struct(&builtins[i++], "export", &builtin_setenv);
  init_builtin_struct(&builtins[i++], "echo", &builtin_echo);
  init_builtin_struct(&builtins[i++], "set", &builtin_set);
  init_builtin_struct(&builtins[i++], "unset", &builtin_unset);
  init_builtin_struct(&builtins[i++], NULL, NULL);
  return (builtins);
}
