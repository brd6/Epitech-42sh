/*
** my_rm_elem_in_list_end.c for my_rm_elem_in_list_end in /home/bongol_b/rendu/PSU_2015_minishell1/lib/my
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan  8 03:09:20 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:47:47 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		my_rm_elem_in_list_end(t_list **begin)
{
  t_list	*curr;

  if ((*begin)->next == NULL)
    {
      free(*begin);
      *begin = NULL;
      return;
    }
  curr = *begin;
  while (curr->next->next != NULL)
    curr = curr->next;
}
