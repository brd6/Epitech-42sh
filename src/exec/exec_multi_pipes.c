/*
** exec_multi_pipes.c for exec_multi_pipes in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 18:05:39 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 01:06:44 2016 Berdrigue Bongolo-Beto
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int	loop_pipe_cond(int *reset_var,
			       t_list **tmp,
			       t_cmd *cmd,
			       t_my_builtin *builtins)
{
  static int	fd_in = 0;
  static int	tmp_status = 0;
  int		pipefd[2];
  pid_t		son_pid;

  if (*reset_var && (*reset_var = 0) == 0)
    {
      fd_in = 0;
      tmp_status = 0;
    }
  if (pipe(pipefd) == -1 || (son_pid = fork()) == -1)
    return (-42);
  if (son_pid == 0)
    {
      pipe_son_dup(pipefd, &fd_in, tmp, 0);
      pipe_exec(cmd, builtins, *tmp);
    }
  else
    {
      pipe_son_dup(pipefd, &fd_in, tmp, 1);
      cmd->status = father_process_action(son_pid);
      if (cmd->status != tmp_status && cmd->status != 0)
	tmp_status = cmd->status;
    }
  return (tmp_status);
}

static t_cmd	*loop_pipe(t_list *list, t_my_builtin *builtins)
{
  t_list	*tmp;
  t_cmd		*cmd;
  int		builtin_index;
  int		reset_var;
  int		sts;

  tmp = list;
  cmd = NULL;
  reset_var = 1;
  sts = 0;
  while (tmp != NULL)
    {
      cmd = ((t_cmd *)(tmp->data));
      if ((builtin_index = is_builins_cmd(cmd->command, builtins)) != -1 &&
	  tmp->next == NULL)
	{
	  exec_builtins(builtins, cmd, builtin_index);
	  tmp = tmp->next;
	}
      else if ((sts = loop_pipe_cond(&reset_var, &tmp, cmd, builtins)) == -42)
	break ;
    }
  if (cmd != NULL)
    cmd->status = (sts) ? 1 : 0;
  return (cmd);
}

int		exec_multi_pipes(t_cmd *cmd2,
				 t_my_builtin *builtins,
				 t_cmd **exit_cmd)
{
  t_list	*list;

  if ((cmd2->line = my_str_replace("|", ";", cmd2->line, -1)) == NULL)
    return (GO_ON);
  if ((list = check_valid_line(cmd2->line)) == NULL)
    return (GO_ON);
  *exit_cmd = loop_pipe(list, builtins);
  g_mysh.exit_code = (*exit_cmd)->status;
  return (GO_ON);
}
