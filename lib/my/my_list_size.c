/*
** my_list_size.c for my_list_size in /home/bongol_b/rendu/Piscine_C_J11/ex_02
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 13:53:43 2015 berdrigue bongolo-beto
** Last update Sat Mar 12 13:49:04 2016 Berdrigue BONGOLO BETO
*/

#include "mylist.h"

int		my_list_size(t_list *begin)
{
  int		i;
  t_list	*current;

  i = 0;
  current = begin;
  while (current != 0)
    {
      i = i + 1;
      current = current->next;
    }
  return (i);
}
