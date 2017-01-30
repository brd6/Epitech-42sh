/*
** my_apply_on_list.c for my_apply_on_list in /home/bongol_b/rendu/Piscine_C_J11/ex_04
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 15:24:21 2015 berdrigue bongolo-beto
** Last update Fri May 20 22:47:58 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_apply_on_list(t_list *begin, void (*f)())
{
  t_list	*current;

  current = begin;
  while (current != NULL)
    {
      (*f)(current->data);
      current = current->next;
    }
  return (1);
}
