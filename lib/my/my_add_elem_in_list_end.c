/*
** my_add_elem_in_list_end.c for my_add_elem_in_list_end in /home/bongol_b/rendu/PSU_2015_minishell1/lib/my
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan  8 02:56:08 2016 Berdrigue BONGOLO BETO
** Last update Fri May  6 11:50:02 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int		my_add_elem_in_list_end(t_list **begin, void *data)
{
  t_list	*curr;

  curr = *begin;
  if (curr == NULL)
    return (my_add_elem_in_list_begin(begin, data));
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = malloc(sizeof(*curr));
  if (curr->next == NULL)
    return (0);
  curr->next->data = data;
  curr->next->next = NULL;
  return (1);
}
