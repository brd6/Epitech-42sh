/*
** builtin_env.c<builtins> for builtin_env in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Apr  6 20:45:54 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:15:59 2016 fougea_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "myprintf.h"
#include "my.h"
#include "mysh.h"

static void	print_env(void *data)
{
  myprintf("%s\n", data);
}

int		builtin_env(t_cmd *cmd)
{
  struct stat	path_stat;

  if (cmd->options[1] != NULL)
    {
      cmd->status = 127;
      g_mysh.exit_code = -1;
      if (stat(cmd->options[1], &path_stat) == -1 ||
	  !S_ISDIR(path_stat.st_mode))
	return (myeprintf(ERR_ENV_ARG_FILE, cmd->options[1]), 0);
      return (myeprintf(ERR_ENV_ARG_DIR, cmd->options[1]), 0);
    }
  my_apply_on_list(g_mysh.my_env, print_env);
  if (cmd != NULL)
    cmd->status = 0;
  return (1);
}
