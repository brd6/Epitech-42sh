/*
** exec_multi_cmd.c for exec_multi_cmd.c in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 16:43:46 2016 Berdrigue BONGOLO BETO
** Last update Fri Jun  3 23:42:24 2016 Berdrigue BONGOLO BETO
*/

#include <stddef.h>
#include "my.h"
#include "mysh.h"

static void	exec_cmd_cond(t_cmd *cmd)
{
  if (g_mysh.exit_code == -1)
    g_mysh.exit_code = cmd->status;
  else
    g_mysh.exit_code = (cmd->status > 0);
}

int		exec_cmd(t_cmd *cmd,
			 t_my_builtin *builtins,
			 t_cmd **exit_cmd)
{
  static int	prev_cmd_status;

  if (!cmd->cond_separator ||
      (cmd->cond_separator == SEP_OR && prev_cmd_status) ||
      (cmd->cond_separator == SEP_AND && !prev_cmd_status))
    {
      if (cmd->is_pipe_line)
	{
	  exec_multi_pipes(cmd, builtins, exit_cmd);
	  prev_cmd_status = (*exit_cmd)->status;
	}
      else
	{
	  exec_simple_cmd(cmd, builtins);
	  prev_cmd_status = cmd->status;
	  exec_cmd_cond(cmd);
	}
    }
  else if (prev_cmd_status && cmd->cond_separator != SEP_OR)
    {
      prev_cmd_status = 1;
      g_mysh.exit_code = 1;
    }
  return (GO_ON);
}

int		exec_multi_cmd(t_list *cmd,
			       t_my_builtin *builtins)
{
  t_list	*tmp;
  t_cmd		*exit_cmd;
  int		builtin_index;
  t_cmd		*curr_cmd;

  tmp = cmd;
  exit_cmd = NULL;
  while (tmp != NULL)
    {
      curr_cmd = (t_cmd *)(tmp->data);
      if ((curr_cmd = get_globs(curr_cmd)) == NULL)
	return ((g_mysh.exit_code = 1), GO_ON);
      if (!curr_cmd->is_pipe_line && !my_strcmp(curr_cmd->command, "exit"))
	exit_cmd = curr_cmd;
      exec_cmd(tmp->data, builtins, &exit_cmd);
      tmp = tmp->next;
    }
  if (exit_cmd != NULL && !exit_cmd->is_pipe_line &&
      !my_strcmp(exit_cmd->command, "exit") &&
      (builtin_index = is_builins_cmd(exit_cmd->command, builtins)) != -1)
    return (builtins[builtin_index].func(exit_cmd));
  my_free_list(&cmd, free_cmd_data);
  return (GO_ON);
}
