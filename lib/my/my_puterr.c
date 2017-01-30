/*
** my_puterr.c for my_puterr in /home/bongol_b/rendu/PSU_2015_my_select_bak2
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Dec 11 16:42:59 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 13:43:29 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>

void		my_puterr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i = i + 1;
    }
}
