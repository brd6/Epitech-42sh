/*
** flag_chars.c for tek in /home/fougea_a/personnal/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Mon Apr 18 18:49:28 2016 fougea_a
** Last update Tue Apr 26 00:43:59 2016 fougea_a
*/

#include <stddef.h>
#include <stdarg.h>
#include "private_myprintf.h"

int		flag_char(va_list list, t_output *out)
{
  char		n;

  n = va_arg(list, int);
  myprintf_putchar(n, out);
  return (0);
}

int		flag_string(va_list list, t_output *out)
{
  const char	*str;

  str = va_arg(list, char *);
  myprintf_putstr(str, out);
  return (0);
}

int		flag_non_printable_string_chars(va_list list, t_output *out)
{
  const char	*str;
  int		i;

  i = 0;
  str = va_arg(list, char *);
  if (str == NULL)
    myprintf_putstr("(null)", out);
  while (str != NULL && str[i] != '\0')
    {
      if (str[i] > ' ' && str[i] <= '~')
	myprintf_putchar(str[i], out);
      else
	{
	  myprintf_putchar('\\', out);
	  if (str[i] == 0)
	    myprintf_putstr("000", out);
	  else if (str[i] < 8)
	    myprintf_putstr("00", out);
	  else if (str[i] < 64)
	    myprintf_putchar('0', out);
	  myprintf_putnbrbase(str[i], "01234567", out);
	}
      i += 1;
    }
  return (0);
}

int		flag_modulo(va_list list, t_output *out)
{
  (void)list;
  myprintf_putchar('%', out);
  return (0);
}
