/*
** my_rm_el_from_list2.c for my_rm_el_from_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 01:04:18 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:50:12 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		*my_rm_el_from_list2(t_list2 **begin,
				     void *data_ref,
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
	  return (NULL);
	}
      curr->prev = curr;
      curr = curr->next;
    }
  return (NULL);
}
