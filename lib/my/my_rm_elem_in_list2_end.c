/*
** my_rm_elem_in_list2_end.c for my_rm_elem_in_list2_end in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 00:20:30 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:50:18 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		my_rm_elem_in_list2_end(t_list2 **begin)
{
  t_list2	*curr;

  if ((*begin)->next == NULL)
    {
      free(*begin);
      *begin = NULL;
      return;
    }
  curr = *begin;
  while (curr->next->next != NULL)
    curr = curr->next;
  if (*begin == curr)
    *begin = curr->next;
  if (curr->next != NULL)
    curr->next->prev = curr->prev;
  if (curr->prev != NULL)
    curr->prev->next = curr->next;
  free(curr->data);
  free(curr);
}
