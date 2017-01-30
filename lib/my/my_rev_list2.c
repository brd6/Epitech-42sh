/*
** my_rev_list2.c for my_rev_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 00:01:25 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:50:28 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_rev_list2(t_list2 **begin)
{
  t_list2	*curr;
  t_list2	*tmp;

  curr = *begin;
  while (curr != NULL)
    {
      tmp = curr->prev;
      curr->prev = curr->next;
      curr->next = tmp;
      curr = curr->prev;
    }
  if (tmp != NULL)
    (*begin) = tmp->prev;
  return (1);
}
