/*
** my_find_node_eq_in_list.c for my_find_node_eq_in_list in /home/bongol_b/rendu/Piscine_C_J11/ex_07
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 16:28:35 2015 berdrigue bongolo-beto
** Last update Fri May  6 14:23:03 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*my_find_node_eq_in_list(t_list *begin, void *data_ref,
					 int (*cmp)())
{
  t_list	*current;

  current = begin;
  while (current != NULL)
    {
      if ((*cmp)(current->data, data_ref) == 0)
	return (current);
      current = current->next;
    }
  return (NULL);
}
