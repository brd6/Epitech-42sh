/*
** my_params_in_list.c for my_params_in_list in /home/bongol_b/rendu/Piscine_C_J11/ex_01
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 09:33:50 2015 berdrigue bongolo-beto
** Last update Fri Jun  3 20:29:16 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

t_list		*my_params_in_list(int ac, const char **av)
{
  t_list	*new;
  t_list	*next;
  int		i;

  i = 0;
  new = NULL;
  next = NULL;
  while (i < ac)
    {
      if (!(next = malloc(sizeof(*next))))
	return (NULL);
      next->next = new;
      if (!(next->data = my_strdup(av[i])))
	return (NULL);
      new = next;
      i = i + 1;
    }
  return (new);
}
