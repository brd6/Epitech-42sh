/*
** read_42sh_file.c for read_42sh_file in /home/bongol_b/Epitech-rendu/PSU_2015_42sh
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat May 21 01:25:08 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:18:11 2016 fougea_a
*/

#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "myprintf.h"
#include "mysh.h"
#include "my.h"

static void	exec_line(char *str, t_my_builtin *builtins)
{
  t_list	*cmd;
  int		counter;

  counter = 0;
  if (!is_space_str(str) &&
      (cmd = check_valid_line(str)) &&
      exec_multi_cmd(cmd, builtins) == EXIT_PROG)
    myeprintf(ERR_CONFIG_FILE, counter);
  counter += 1;
}

void		read_42sh_file(const char *filename, t_my_builtin *builtins)
{
  char		*str;
  int		fd;

  if (filename == NULL ||
      filename[0] == 0 ||
      (fd = open(filename, O_RDONLY)) == -1)
    return ;
  while ((str = get_next_line(fd)))
    {
      if (str[0] != '#')
	exec_line(str, builtins);
      free(str);
    }
  close(fd);
}
