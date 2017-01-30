/*
** my_strstr.c for my_strstr.c in /home/bongol_b/rendu/PSU_2015_minishell1/lib/my
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan 15 16:30:29 2016 Berdrigue BONGOLO BETO
** Last update Tue Feb 23 00:27:35 2016 Berdrigue BONGOLO BETO
*/

#include <stdio.h>

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str == NULL || to_find == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] == to_find[j])
	j = j + 1;
      else
	j = 0;
      if (to_find[j] == 0)
	{
	  i = i - (j - 1);
	  return (str + i);
	}
      i = i + 1;
    }
  return (NULL);
}
