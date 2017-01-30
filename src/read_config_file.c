/*
** read_config_file.c for tek in PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Thu Apr 28 09:19:43 2016 fougea_a
** Last update Sun Jun  5 03:15:45 2016 fougea_a
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
  static int	counter = 0;
  t_list	*cmd;

  if (!is_space_str(str) &&
      (cmd = check_valid_line(str)) &&
      exec_multi_cmd(cmd, builtins) == EXIT_PROG)
    myeprintf(ERR_CONFIG_FILE, counter);
  counter += 1;
}

void		read_config_file(t_my_builtin *builtins)
{
  char		*str;
  int		fd;

  if (!(str = my_strcat2("./", MYSH_CONFIG_FILE)) ||
      (fd = open(str, O_RDONLY | O_CREAT, FLG_FILE_PERM)) == -1)
    {
      myeprintf(ERR_OPEN_FILE);
      return ;
    }
  free(str);
  while ((str = get_next_line(fd)))
    {
      if (str[0] != '#')
	exec_line(str, builtins);
      free(str);
    }
  close(fd);
}
