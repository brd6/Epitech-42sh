/*
** my_apply_on_list2.c for my_apply_on_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 00:58:16 2016 Berdrigue BONGOLO BETO
** Last update Thu Mar 31 12:09:14 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_apply_on_list2(t_list2 *begin, void (*f)(void *))
{
  t_list2	*curr;

  curr = begin;
  while (curr != NULL)
    {
      (*f)(curr->data);
      curr = curr->next;
    }
  return (1);
}
