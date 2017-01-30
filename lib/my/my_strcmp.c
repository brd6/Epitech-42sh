/*
** my_strcmp.c for my_strcmp in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 14:59:45 2015 berdrigue bongolo-beto
** Last update Sat Apr 30 01:42:09 2016 fougea_a
*/

#include <stdio.h>

int	my_strcmp(char *s1, char *s2)
{
  if (s1 == NULL && s2 == NULL)
    return (1);
  else if (s1 == NULL)
    return (1);
  else if (s2 == NULL)
    return (-1);
  while (*s1 && (*s1 == *s2))
    {
      if (!(*s2))
	return (1);
      s1 = s1 + 1;
      s2 = s2 + 1;
    }
  if (!(*s1) && (*s2))
    return (-1);
  return (*s1 - *s2);
}

int	my_strcmp2(const char *str1, const char *str2)
{
  int	i;

  i = -1;
  if (!str1 || !str2)
    return (0);
  while (str1[(i = i + 1)] != '\0' && str2[i] != '\0')
    if (str1[i] != str2[i])
      return (0);
  if (str1[i] != str2[i])
    return (0);
  return (1);
}
