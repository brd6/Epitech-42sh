/*
** my_apply_elm_eq_in_list.c for my_apply_elm_eq_in_list in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 19:19:34 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:49:43 2016 Berdrigue BONGOLO BETO
*/

#include "mylist.h"

void		my_apply_elm_eq_in_list(t_list *begin,
					int (*f)(),
					void *data_ref,
					int (*cmp)())
{
  t_list	*curr;

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
