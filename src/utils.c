/*
** utils.c for utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:54:30 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:16:27 2016 fougea_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int		check_null_line(char *line)
{
  if (line == NULL)
    {
      if (!(!isatty(0) || isatty(1)))
	my_putstr(EXIT_MSG);
      return (0);
    }
  return (1);
}

int		is_space_char(char c)
{
  return (c == ' ' || c == '\t');
}

int		is_space_str(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (1);
  while (str[i])
    {
      if (!is_space_char(str[i]))
	return (0);
      i++;
    }
  return (1);
}

char		*concat_two_str(const char *str1, const char *str2, char *c)
{
  char		*tmp;

  tmp = malloc(my_strlen(str1) + my_strlen(str2) + 2);
  if (tmp == NULL)
    return (NULL);
  if (str1 == NULL || str1[0] == 0)
    return (my_strcpy(tmp, str2));
  tmp[0] = 0;
  if (c != NULL && str1[my_strlen(str1) - 1] != c[0])
    {
      my_strcat(tmp, str1);
      my_strcat(tmp, c);
      tmp[my_strlen(str1) + 1] = 0;
    }
  else
    {
      my_strcat(tmp, str1);
      tmp[my_strlen(str1)] = 0;
    }
  my_strcat(tmp, str2);
  tmp[my_strlen(str1) + my_strlen(str2) + 1] = 0;
  return (tmp);
}
