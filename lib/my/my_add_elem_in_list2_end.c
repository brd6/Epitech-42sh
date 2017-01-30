/*
** my_add_elem_in_list2_end.c for my_add_elem_in_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 22:52:28 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 28 19:07:42 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_add_elem_in_list2_end(t_list2 **begin, void *data)
{
  t_list2	*curr;
  t_list2	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (0);
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  if (*begin == NULL)
    {
      *begin = new;
      return (1);
    }
  curr = *begin;
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = new;
  new->prev = curr;
  return (1);
}
