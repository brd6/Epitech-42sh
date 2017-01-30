/*
** builtin_exit.c<src> for builtin_exit in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Apr  1 17:21:16 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:16:18 2016 fougea_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		builtin_exit(t_cmd *cmd)
{
  if (cmd->options[1] == NULL || cmd->options[1][0] == 0)
    {
      g_mysh.exit_code = 0;
      cmd->status = 0;
      if (!(!isatty(0) && !isatty(1)))
	my_putstr(EXIT_MSG);
      return (EXIT_PROG);
    }
  if (!my_str_isnum(cmd->options[1]) || cmd->options[2] != NULL)
    {
      g_mysh.exit_code = 1;
      cmd->status = 1;
      my_puterr(ERR_EXIT_EXPR_SYNTAX);
      return (GO_ON);
    }
  g_mysh.exit_code = my_getnbr(cmd->options[1]) % 256;
  if (!isatty(0) && !isatty(1))
    my_putstr(EXIT_MSG);
  cmd->status = g_mysh.exit_code;
  return (EXIT_PROG);
}
