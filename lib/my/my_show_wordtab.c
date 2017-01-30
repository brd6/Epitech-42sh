/*
** my_show_wordtab.c for my_show_wordtab in /home/bongol_b/rendu/Piscine_C_J08/ex_03
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct  7 17:08:54 2015 berdrigue bongolo-beto
** Last update Wed Apr 13 07:52:46 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i = i + 1;
    }
  return (1);
}
