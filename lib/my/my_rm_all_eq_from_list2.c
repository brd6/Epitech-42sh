/*
** my_rm_all_eq_from_list2.c for my_rm_all_eq_from_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 01:14:46 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:54:24 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_rm_all_eq_from_list2(t_list2 **begin, void *data_ref,
					int (*cmp)())
{
  t_list2	*curr;

  curr = *begin;
  while (curr != NULL)
    {
      if ((*cmp)(curr->data, data_ref) == 0)
	{
	  if (curr->prev == NULL)
	    *begin = curr->next;
	  else
	    curr->prev->next = curr->next;
	  free(curr->data);
	  free(curr);
	}
      curr->prev = curr;
      curr = curr->next;
    }
  return (1);
}
