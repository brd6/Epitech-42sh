/*
** exec_utils.c for exec_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr  3 15:06:44 2016 Berdrigue BONGOLO BETO
** Last update Thu Apr  7 19:53:02 2016 Berdrigue BONGOLO BETO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

struct stat	my_stat(char *file)
{
  struct stat	file_stat;

  stat(file, &file_stat);
  return (file_stat);
}

int		file_exist(char *file)
{
  struct stat	file_stat;

  return (stat(file, &file_stat) == 0);
}

int		directory_exist(char *dirr)
{
  struct stat	dir_stat;

  return (stat(dirr, &dir_stat) == 0 && S_ISDIR(dir_stat.st_mode));
}

int		check_bin_permission(char *bin)
{
  struct stat	file_stat;

  if (bin == NULL)
    return (0);
  file_stat = my_stat(bin);
  if (access(bin, F_OK) != 0)
    {
      my_puterr(bin);
      my_puterr(ERR_COMMAND_NOT_FOUND);
      return (0);
    }
  if (access(bin, X_OK) != 0 || !S_ISREG(file_stat.st_mode))
    {
      my_puterr(bin);
      my_puterr(ERR_PERMISSION_DENIED);
      return (0);
    }
  return (1);
}
