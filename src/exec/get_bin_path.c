/*
** get_bin_path.c for get_bin_path in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 15:18:28 2016 Berdrigue BONGOLO BETO
** Last update Sat Jun  4 00:15:51 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int		is_relative_dir(char *bin)
{
  if (!my_strncmp(bin, "~/", 2) || !my_strncmp(bin, "/", 1)
      || !my_strncmp(bin, "./", 2))
    return (1);
  return (0);
}

char		*get_bin_path_search(char **path, char *bin)
{
  char		*correct_bin;
  int		i;
  struct stat	file_stat;

  i = 0;
  while (path[i])
    {
      correct_bin = concat_two_str(path[i], bin, "/");
      file_stat = my_stat(correct_bin);
      if (!access(correct_bin, F_OK | X_OK) && S_ISREG(file_stat.st_mode))
	return (correct_bin);
      i++;
      free(correct_bin);
    }
  return (NULL);
}

char		*get_bin_path(char *bin,
			      const char *str_path,
			      const char *str_path2)
{
  char		**path;
  char		*correct_bin;
  struct stat	file_stat;

  correct_bin = NULL;
  file_stat = my_stat(bin);
  if (is_relative_dir(bin) || my_get_char_pos(bin, '/') != -1)
    {
      if (!access(bin, F_OK | X_OK) && S_ISREG(file_stat.st_mode))
	return (my_strdup(bin));
    }
  else if (((str_path != NULL &&
	     (path = my_str_split(str_path, ":")) != NULL) ||
	    (str_path2 != NULL &&
	     (path = my_str_split(str_path2, "() ")) != NULL)) &&
	   (correct_bin = get_bin_path_search(path, bin)) != NULL)
    return (correct_bin);
  my_puterr(bin);
  my_puterr(ERR_COMMAND_NOT_FOUND);
  return (NULL);
}
