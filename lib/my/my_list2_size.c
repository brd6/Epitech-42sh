/*
** my_list2_size.c for my_list2_size in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 01:17:54 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:53:23 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_list2_size(t_list2 *begin)
{
  int		i;
  t_list2	*current;

  i = 0;
  current = begin;
  while (current != NULL)
    {
      i = i + 1;
      current = current->next;
    }
  return (i);
}
