/*
** my_params_in_list2.c for my_params_in_list2 in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 23:58:16 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 14:07:38 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

t_list2		*my_params_in_list2(int ac, char **av)
{
  t_list2	*new;
  int		i;

  i = 0;
  new = NULL;
  while (i < ac)
    {
      my_add_elem_in_list2_end(&new, my_strdup(av[i]));
      i = i + 1;
    }
  return (new);
}
