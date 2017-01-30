/*
** flag_numbers.c for tek in /home/fougea_a/personnal/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Tue Apr 19 00:33:06 2016 fougea_a
** Last update Tue Apr 26 00:40:29 2016 fougea_a
*/

#include <stdarg.h>
#include "private_myprintf.h"

int			flag_int(va_list list, t_output *out)
{
  int			nb;

  nb = va_arg(list, int);
  myprintf_putnbr(nb, out);
  return (0);
}

int			flag_unsignedint(va_list list, t_output *out)
{
  unsigned int		nb;

  nb = va_arg(list, unsigned int);
  myprintf_putunbr(nb, out);
  return (0);
}

int			flag_ptr(va_list list, t_output *out)
{
  long long		nb;
  char			*base;
  char			buff[64];
  int			i;

  i = 0;
  base = "0123456789abcdef";
  nb = va_arg(list, long long);
  if (nb == 0)
    myprintf_putstr("(nil)", out);
  else
    {
      myprintf_putstr("0x", out);
      while (nb != 0)
	{
	  buff[i++] = base[nb % 16];
	  nb /= 16;
	}
      while (--i >= 0)
	myprintf_putchar(buff[i], out);
    }
  return (0);
}
