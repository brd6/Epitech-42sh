/*
** my_apply_elm_eq_in_list2.c for my_apply_elm_eq_in_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 01:23:45 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:51:30 2016 Berdrigue BONGOLO BETO
*/

#include "mylist.h"

void		my_apply_elm_eq_in_list2(t_list2 *begin,
					 int (*f)(),
					 void *data_ref,
					 int (*cmp)())
{
  t_list2	*curr;

  curr = begin;
  while (curr)
    {
      if ((*cmp)(curr->data, data_ref) == 0)
	{
	  (*f)(curr->data);
	}
      curr = curr->next;
    }
}
