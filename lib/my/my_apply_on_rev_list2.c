/*
** my_apply_on_rev_list2.c for my_apply_on_rev_list2 in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 28 19:47:46 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 28 22:27:07 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_apply_on_rev_list2(t_list2 *begin, void (*f)(void *))
{
  t_list2	*curr;

  curr = begin;
  if (curr == NULL)
    return (0);
  while (curr->next != NULL)
    curr = curr->next;
  while (curr != NULL)
    {
      (*f)(curr->data);
      curr = curr->prev;
    }
  return (1);
}
