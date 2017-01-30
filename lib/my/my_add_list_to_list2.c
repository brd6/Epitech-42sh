/*
** my_add_list_to_list2.c for my_add_list_to_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 01:25:14 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:51:33 2016 Berdrigue BONGOLO BETO
*/

#include "mylist.h"

void		my_add_list_to_list2(t_list2 **begin1, t_list2 *begin2)
{
  t_list2	*curr;

  curr = *begin1;
  while (curr->next)
    {
      curr = curr->next;
    }
  curr->next = begin2;
}
