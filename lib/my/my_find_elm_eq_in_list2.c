/*
** my_find_elm_eq_in_list2.c for my_find_elm_eq_in_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 00:17:44 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:51:21 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		*my_find_elm_eq_in_list2(t_list2 *begin, void *data_ref,
					 int (*cmp)())
{
  t_list2	*curr;

  curr = begin;
  while (curr != NULL)
    {
      if ((*cmp)(curr->data, data_ref) == 0)
      	{
      	  return (curr->data);
      	}
      curr = curr->next;
    }
  return (NULL);
}
