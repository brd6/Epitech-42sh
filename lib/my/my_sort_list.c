/*
** my_sort_list.c for my_sort_list in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jun  3 22:53:30 2016 Berdrigue BONGOLO BETO
** Last update Fri Jun  3 23:21:25 2016 Berdrigue BONGOLO BETO
*/

#include "mylist.h"

int		my_sort_list(t_list **begin, int (*cmp)())
{
  int		sorted;
  void		*tmp;
  t_list	*current;

  sorted = 1;
  while (sorted)
    {
      sorted = 0;
      current = *begin;
      while (current && current->next)
	{
	  if ((*cmp)(current->data, current->next->data) > 0)
	    {
	      tmp = current->data;
	      current->data = current->next->data;
	      current->next->data = tmp;
	      sorted = 1;
	    }
	  current = current->next;
	}
    }
  return (1);
}
