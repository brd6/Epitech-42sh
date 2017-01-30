/*
** builtin_echo.c for tek in /home/fougea_a/rendu/Programmation Shell/PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Tue May 17 18:19:04 2016 fougea_a
** Last update Sun May 29 16:34:04 2016 fougea_a
*/

#include "myprintf.h"
#include "mysh.h"
#include "my.h"

static void		echo_arg(const char *arg)
{
  int			i;

  i = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] == '\\')
	i += print_special_char(arg + i);
      else
	{
	  my_putchar(arg[i]);
	  i += 1;
	}
    }
}

int		builtin_echo(t_cmd *cmd)
{
  int		new_line;
  int		i;

  i = 1;
  new_line = 1;
  while (cmd->options[i] != NULL)
    {
      if (!my_strcmp(cmd->options[i], "-n"))
	new_line = 0;
      else
	{
	  echo_arg(cmd->options[i]);
	  if (cmd->options[i + 1] != NULL &&
	      my_strcmp(cmd->options[i + 1], "-n"))
	    my_putchar(' ');
	}
      i += 1;
    }
  if (new_line)
    my_putchar('\n');
  return (0);
}
