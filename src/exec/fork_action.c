/*
** fork_action.c for fork_action in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 15:04:05 2016 Berdrigue BONGOLO BETO
** Last update Sat Jun  4 00:08:36 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void		son_process_action(t_cmd *cmd)
{
  int		res;
  char		**env;
  char		*bin;
  char		*path;
  char		*path2;

  if (((env = env_list_to_array(g_mysh.my_env)) == NULL))
    exit(1);
  if (!redirect_cmd(cmd))
    exit(1);
  path = key_to_value(g_mysh.my_env, "PATH");
  path2 = key_to_value(g_mysh.variables, "path");
  bin = get_bin_path(cmd->command, path, path2);
  if (bin == NULL || !check_bin_permission(bin))
    exit(1);
  else if ((res = execve(bin, cmd->options, env)) == -1)
    my_puterr(ERR_EXECVE);
}

int		father_process_action(int son_pid)
{
  int		son_status;

  while (wait(&son_status) != son_pid)
    ;
  if (WIFSIGNALED(son_status) && WTERMSIG(son_status) == SIGSEGV)
    {
      if (WCOREDUMP(son_status))
	my_puterr(ERR_SEGMENTATION_FAULT1);
      else
	my_puterr(ERR_SEGMENTATION_FAULT2);
      g_mysh.exit_code = -1;
      return (139);
    }
  else if (WIFSIGNALED(son_status) && WTERMSIG(son_status) == SIGFPE)
    {
      if (WCOREDUMP(son_status))
	my_puterr(ERR_FLOATING_PTS_EXCP1);
      else
	my_puterr(ERR_FLOATING_PTS_EXCP2);
      g_mysh.exit_code = -1;
      return (136);
    }
  return (son_status);
}
