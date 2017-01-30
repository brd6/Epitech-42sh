/*
** my_rm_all_eq_from_list.c for my_rm_all_eq_from_list in /home/bongol_b/rendu/Piscine_C_J11/ex_08
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 16:40:57 2015 berdrigue bongolo-beto
** Last update Mon Feb 22 01:15:31 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*my_rm_node(t_list *current, void *data_ref, int (*cmp)())
{
  t_list	*next;

  if (current == NULL)
    return (NULL);
  if ((*cmp)((current)->data, data_ref) == 0)
    {
      next = current->next;
      free(current->data);
      free(current);
      next = my_rm_node(current->next, data_ref, cmp);
      return (next);
    }
  else
    {
      current->next = my_rm_node(current->next, data_ref, cmp);
      return (current);
    }
}

int		my_rm_all_eq_from_list(t_list **begin, void *data_ref,
				       int (*cmp)())
{
  t_list	*tmp;

  if (begin == NULL || *begin == NULL)
    return (1);

  tmp = my_rm_node((*begin), data_ref, cmp);
  *begin = tmp;
  return (0);
}
