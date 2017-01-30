/*
** my_rm_elem_in_list2_begin.c for my_rm_elem_in_list2_begin in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Mar 29 16:34:45 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 29 17:16:38 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		my_rm_elem_in_list2_begin(t_list2 **begin)
{
  t_list2	*curr;

  if (*begin == NULL)
    return;
  if ((*begin)->next == NULL)
    {
      free(*begin);
      *begin = NULL;
      return;
    }
  curr = *begin;
  *begin = (*begin)->next;
  (*begin)->prev = NULL;
  free(curr->data);
  free(curr);
}
