/*
** tilde_replacing.c for tilde_replacing in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri May 20 16:34:34 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:17:42 2016 fougea_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "mysh.h"
#include "myprintf.h"

static int	is_directory(const char *path)
{
  struct stat	my_stat;

  if (stat(path, &my_stat) != 0)
    return (0);
  return (S_ISDIR(my_stat.st_mode));
}

static char	*replace_user_tilde(char *str)
{
  char		*new_str;
  char		*user;
  char		*user_dir;
  int		i;

  if ((user = malloc(sizeof(*user) * my_strlen(str))) == NULL)
    return (str);
  i = 0;
  while (str && str[i + 1] && str[i + 1] != '/')
    {
      user[i] = str[i + 1];
      i++;
    }
  user[i] = 0;
  user_dir = concat_two_str("/home/", user, NULL);
  new_str = concat_two_str("/home/", &str[1], NULL);
  if (user_dir != NULL && my_strncmp(user, ".", 1) && is_directory(user_dir))
    {
      free(user_dir);
      return (free(user), new_str);
    }
  free(user_dir);
  mydprintf(2, ERR_TILDE_USER, user);
  free(user);
  return (NULL);
}

char		*tilde_replacing(char *str)
{
  char		*new_str;
  char		*home_val;
  int		home_exist;

  if (g_mysh.my_env == NULL ||
      (!(home_exist = env_key_exist(g_mysh.my_env, "HOME")) && str[1] == 0))
    return (str);
  if (home_exist && str[1] == 0)
    {
      free(str);
      return (key_to_value(g_mysh.my_env, "HOME"));
    }
  if (str[1] == '/')
    {
      home_val = key_to_value(g_mysh.my_env, "HOME");
      new_str = concat_two_str(home_val, &str[1], NULL);
      free(str);
      return (new_str);
    }
  return (replace_user_tilde(str));
}
