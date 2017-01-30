/*
** my_wordtab_search.c for my_wordtab_search in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Mar  4 12:47:51 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:56:09 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

char		*my_wordtab_search(char **tab, char *data, int (*cmp)())
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (cmp(tab[i], data) == 0)
	return (tab[i]);
      i++;
    }
  return (NULL);
}
