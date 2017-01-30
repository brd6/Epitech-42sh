/*
** exec_multi_pipes_util.c for exec_multi_pipes_util in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun  5 00:21:54 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun  5 00:24:10 2016 Berdrigue Bongolo-Beto
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void		pipe_exec(t_cmd *cmd,
			  t_my_builtin *builtins,
			  t_list *tmp)
{
  int		builtin_index;

  if ((builtin_index = is_builins_cmd(cmd->command, builtins)) != -1)
    {
      if (!(tmp->next == NULL && !my_strcmp(cmd->command, "exit")))
	exec_builtins(builtins, cmd, builtin_index);
      exit(0);
    }
  else
    son_process_action(cmd);
}

void		pipe_son_dup(int *pipefd, int *fd_in, t_list **tmp, int flag)
{
  if (!flag)
    {
      close(pipefd[0]);
      dup2(*fd_in, 0);
      if ((*tmp)->next != NULL)
	{
	  dup2(pipefd[1], 1);
	  close(pipefd[1]);
	}
    }
  else
    {
      close(pipefd[1]);
      *fd_in = pipefd[0];
      *tmp = (*tmp)->next;
    }
}
