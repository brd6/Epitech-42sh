/*
** env_util2.c for env_util2 in /home/bongol_b/rendu_ok/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan 15 18:02:00 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:18:36 2016 fougea_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "myprintf.h"

int		env_key_exist(t_list *my_env, char *key)
{
  char		*tmp;

  if (my_env != NULL && key != NULL)
    {
      if ((tmp = key_to_value(my_env, key)) == NULL)
	return (0);
      free(tmp);
      return (1);
    }
  return (0);
}

int		env_key_exist_v(t_list *my_env, char *key)
{
  char		*tmp;

  if (key == NULL)
    return (0);
  if ((tmp = key_to_value(my_env, key)) == NULL)
    {
      myeprintf(ERR_UNDEF_VAR, key);
      return (0);
    }
  free(tmp);
  return (1);
}
