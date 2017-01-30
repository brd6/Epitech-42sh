/*
** transcript_env_variables.c for tek in PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Sat May 21 20:50:56 2016 fougea_a
** Last update Fri Jun  3 20:51:53 2016 Berdrigue BONGOLO BETO
*/

#include <stddef.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static char	*handle_variables(const char *old, char *new, int *i)
{
  char		*value;
  char		*key;
  char		*tmp;

  *i += 1;
  if (!(key = extract_env_key(old)) ||
      (!(value = key_to_value(g_mysh.my_env, key)) &&
       !(value = key_to_value(g_mysh.variables, key))) ||
      !(tmp = mystrcat(4, new, "\"", value, "\"")))
    return (new);
  *i += my_strlen(key);
  free(value);
  free(key);
  free(new);
  return (tmp);
}

static char	*handle_strings(const char *old, char *new, int *i)
{
  char		*tmp;
  int		j;

  j = 0;
  while ((old[j] != '$' || (j > 0 && old[j - 1] == '\\')) &&
	 (old[j] != '\0'))
    j += 1;
  if (!(tmp = my_strncat(new, old, j)))
    return (NULL);
  free(new);
  *i += j;
  return (tmp);
}

char		*transcript_env_variables(char *old)
{
  char		*new;
  int		i;

  i = 0;
  new = NULL;
  while (old[i] != '\0')
    {
      if (old[i] == '$' && (i == 0 || old[i - 1] != '\\'))
	new = handle_variables(old + i, new, &i);
      else if (!(new = handle_strings(old + i, new, &i)))
	return (old);
    }
  if (i > 0)
    return (free(old), new);
  return (old);
}
