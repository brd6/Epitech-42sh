/*
** my_list2_rev_copy.c for my_list2_rev_copy in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 01:22:13 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:55:00 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

t_list2		*my_list2_rev_copy(t_list2 *begin)
{
  t_list2	*curr;
  t_list2	*new_list;

  new_list = NULL;
  curr = begin;
  while (curr)
    {
      my_add_elem_in_list2_begin(&new_list, curr->data);
      curr = curr->next;
    }
  return (new_list);
}
