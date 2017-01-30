/*
** my_putstr.c for my_putstr in /home/bongol_b/rendu/Piscine_C_J04
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Oct  1 09:13:04 2015 berdrigue bongolo-beto
** Last update Wed Feb 10 14:00:55 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}
