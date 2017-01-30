/*
** my_list2_to_wordtab.c for my_list2_to_wordtab in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 01:17:13 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 24 17:25:46 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

char		**my_list2_to_wordtab(t_list2 *begin)
{
  char		**array;
  int		j;
  t_list2	*curr;

  array = malloc(sizeof(*array) * (my_list2_size(begin) + 2));
  if (!array)
    return (NULL);
  curr = begin;
  j = 0;
  while (curr)
    {
      if (!(array[j] = my_strdup((char *)curr->data)))
	return (NULL);
      j++;
      curr = curr->next;
    }
  array[j] = 0;
  return (array);
}
