/*
** my_rev_list.c for my_rev_list in /home/bongol_b/rendu/Piscine_C_J11/ex_03
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 14:25:18 2015 berdrigue bongolo-beto
** Last update Sat Mar 12 13:48:16 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_rev_list(t_list **begin)
{
  t_list	*current;
  t_list	*tmp;

  current = *begin;
  *begin = NULL;
  while (current != NULL)
    {
      tmp = current->next;
      current->next = *begin;
      *begin = current;
      current = tmp;
    }
  return (1);
}
