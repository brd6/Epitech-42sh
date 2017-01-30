/*
** flag_bases.c for tek in /home/fougea_a/libmyc/WIP/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Mon Apr 25 16:21:58 2016 fougea_a
** Last update Mon Apr 25 21:48:21 2016 fougea_a
*/

#include <stddef.h>
#include "private_myprintf.h"

int			flag_hex(va_list list, t_output *out)
{
  unsigned int		nb;

  nb = va_arg(list, unsigned int);
  myprintf_putnbrbase(nb, "0123456789abcdef", out);
  return (0);
}

int			flag_hex2(va_list list, t_output *out)
{
  unsigned int		nb;

  nb = va_arg(list, unsigned int);
  myprintf_putnbrbase(nb, "0123456789ABCDEF", out);
  return (0);
}

int			flag_bin(va_list list, t_output *out)
{
  unsigned int		nb;

  nb = va_arg(list, unsigned int);
  myprintf_putnbrbase(nb, "01", out);
  return (0);
}

int			flag_oct(va_list list, t_output *out)
{
  unsigned int		nb;

  nb = va_arg(list, unsigned int);
  myprintf_putnbrbase(nb, "01234567", out);
  return (0);
}
