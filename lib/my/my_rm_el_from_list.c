/*
** my_rm_el_from_list.c for my_rm_el_from_list in /home/bongol_b/rendu/Piscine_C_J11
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jan 14 23:59:08 2016 Berdrigue BONGOLO BETO
** Last update Tue Apr  5 17:49:26 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		*my_rm_el_from_list(t_list **begin,
				    void *data_ref,
				    int (*cmp)())
{
  t_list	*curr;
  t_list	*prev;

  prev = NULL;
  curr = *begin;
  while (curr != NULL)
    {
      if ((*cmp)(curr->data, data_ref) == 0)
	{
	  if (prev == NULL)
	    *begin = curr->next;
	  else
	    prev->next = curr->next;
	  free(curr);
	  return (NULL);
	}
      prev = curr;
      curr = curr->next;
    }
  return (NULL);
}
