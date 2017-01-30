/*
** exec_builtins.c for exec_builtins in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun May 29 18:36:44 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 01:11:50 2016 Berdrigue Bongolo-Beto
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"

int		exec_builtins(t_my_builtin *builtins,
			      t_cmd *cmd,
			      int builtin_index)
{
  int		bak_stdout;
  int		ret;

  if (cmd->redirect[0].file != NULL)
    {
      bak_stdout = dup(STDOUT_FILENO);
      redirect_cmd(cmd);
    }
  ret = builtins[builtin_index].func(cmd);
  if (cmd->redirect[0].file != NULL)
    {
      dup2(bak_stdout, STDOUT_FILENO);
      close(bak_stdout);
    }
  return (ret);
}
