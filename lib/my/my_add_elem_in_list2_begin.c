/*
** my_add_elem_in_list2_begin.c for my_add_elem_in_list2_begin in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 19:49:52 2016 Berdrigue BONGOLO BETO
** Last update Fri Apr  1 14:53:07 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

int		my_add_elem_in_list2_begin(t_list2 **begin, void *data)
{
  t_list2	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (0);
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  if (*begin == NULL)
    {
      *begin = new;
      return (1);
    }
  (*begin)->prev = new;
  new->next = *begin;
  *begin = new;
  return (1);
}
