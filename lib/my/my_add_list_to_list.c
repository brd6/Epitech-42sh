/*
** my_add_list_to_list.c for my_add_list_to_list in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 19:23:57 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:49:48 2016 Berdrigue BONGOLO BETO
*/

#include "mylist.h"

void		my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  t_list	*curr;

  curr = *begin1;
  while (curr->next)
    {
      curr = curr->next;
    }
  curr->next = begin2;
}
