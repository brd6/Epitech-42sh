/*
** my_free_list2.c for my_free_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 19:59:58 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr 24 13:47:11 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "mylist.h"

void		my_free_list2(t_list2 **begin, void (*f)(void *))
{
  t_list2	*curr;

  while (*begin)
    {
      curr = *begin;
      *begin = (*begin)->next;
      if (*f == NULL)
	free(curr->data);
      else
	(*f)(curr->data);
      free(curr);
    }
  *begin = NULL;
}
