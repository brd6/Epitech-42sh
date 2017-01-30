/*
** my_tabdup.c for tek in /home/fougea_a/rendu/Programmation Shell/PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Fri May 20 12:04:29 2016 fougea_a
** Last update Fri May 20 12:10:00 2016 fougea_a
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char		**my_tabdup(char **tab)
{
  char		**ret;
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  if (!(ret = malloc(sizeof(char *) * (i + 1))))
    return (NULL);
  ret[i] = NULL;
  while (--i >= 0)
    if (!(ret[i] = my_strdup(tab[i])))
      return (NULL);
  return (ret);
}
