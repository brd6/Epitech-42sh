/*
** get_env_key.c for tek in /home/fougea_a/rendu/Programmation Shell/PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Fri May 20 20:20:13 2016 fougea_a
** Last update Fri Jun  3 20:50:47 2016 Berdrigue BONGOLO BETO
*/

#include <stddef.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char		*extract_env_key(const char *str)
{
  char		*key;
  int		i;

  i = 0;
  key = NULL;
  str += 1;
  while (str[i] != '\0' &&
	 (!env_key_exist(g_mysh.my_env, key) &&
	  !env_key_exist(g_mysh.variables, key)))
    {
      free(key);
      if (!(key = my_strncat(NULL, str, i + 2)))
	return (NULL);
      i += 1;
    }
  if (!env_key_exist(g_mysh.my_env, key) &&
      !env_key_exist(g_mysh.variables, key))
    return (NULL);
  return (key);
}
