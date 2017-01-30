/*
** my_list_rev_copy.c for my_list_rev_copy in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 19:13:17 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:54:40 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*my_list_rev_copy(t_list *begin)
{
  t_list	*curr;
  t_list	*new_list;

  new_list = NULL;
  curr = begin;
  while (curr)
    {
      my_add_elem_in_list_begin(&new_list, curr->data);
      curr = curr->next;
    }
  return (new_list);
}
