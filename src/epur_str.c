/*
** epur_str.c for epur_str in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 28 22:30:37 2016 Berdrigue BONGOLO BETO
** Last update Fri Jun  3 20:59:23 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

static int	skip_char(const char *str, const char *s)
{
  int		i;

  i = 0;
  while (my_get_char_pos(s, str[i]) != -1)
    i++;
  return (i);
}

static int	set_first_char(const char *to_remove,
			       const char *str,
			       char *new_str,
			       int *j)
{
  int		i;

  i = 0;
  if (my_get_char_pos(to_remove, str[i]) != -1)
    {
      new_str[(*j)++] = str[i];
      i = skip_char(str, to_remove);
    }
  return (i);
}

static char	*init_epur_str(const char *str, int *j, int *str_len)
{
  char		*new_str;

  if ((new_str = malloc(sizeof(*str) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  *j = 0;
  *str_len = my_strlen(str);
  return (new_str);
}

char		*epur_str(const char *str,
			  const char *to_remove,
			  int replace_with_space)
{
  int		i;
  char		*new_str;
  int		j;
  int		str_len;

  if ((new_str = init_epur_str(str, &j, &str_len)) == NULL)
    return (NULL);
  if (replace_with_space != -1)
    i = set_first_char(to_remove, str, new_str, &j);
  else
    i = skip_char(str, to_remove);
  while (str[i])
    {
      if (my_get_char_pos(to_remove, str[i]) == -1)
	{
	  new_str[j] = str[i];
	  if (replace_with_space != -1 &&
	      i + 2 < str_len && my_get_char_pos(to_remove, str[i + 1]) != -1)
	    new_str[++j] = (replace_with_space) ? ' ' : str[i + 1];
	  j++;
	}
      i++;
    }
  new_str[j] = 0;
  return (new_str);
}
