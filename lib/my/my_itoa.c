/*
** my_itoa.c for my_itoa in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 30 12:58:22 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 13:58:54 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	recurr_itoa(char *str, int nbr, int *i)
{
  if (nbr >= 0 && nbr <= 9)
    {
      str[*i] = nbr + '0';
      *i = *i + 1;
    }
  else if (nbr > 9)
    {
      recurr_itoa(str, nbr / 10, i);
      recurr_itoa(str, nbr % 10, i);
    }
}

char	*my_itoa(int nbr)
{
  char *str;
  int	i;

  str = malloc(my_nbr_len(nbr) + 1);
  if (str == NULL)
    return (NULL);
  i = 0;
  if (nbr < 0)
    {
      str[i] = '-';
      i = i + 1;
      nbr = nbr * (-1);
    }
  recurr_itoa(str, nbr, &i);
  str[i] = 0;
  return (str);
}
