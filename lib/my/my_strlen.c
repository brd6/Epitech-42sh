/*
** my_strlen.c for my_strlen in /home/bongol_b/rendu/Piscine_C_J04
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Oct  1 09:29:01 2015 berdrigue bongolo-beto
** Last update Sat May 21 15:32:35 2016 fougea_a
*/

#include <stdio.h>

int		my_strlen(const char *str)
{
  int		cp;

  cp = 0;
  if (str == NULL || str[0] == 0)
    return (cp);
  while (str[cp])
    cp = cp + 1;
  return (cp);
}
