/*
** myprintf_utils.c for tek in /home/fougea_a/libmyc/WIP/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Thu Apr 21 01:04:53 2016 fougea_a
** Last update Tue Apr 26 00:40:24 2016 fougea_a
*/

#include <stddef.h>
#include <unistd.h>
#include "private_myprintf.h"

int		myprintf_putchar(char n, t_output *out)
{
  if (out->str_output != NULL && out->limit > 0)
    {
      *out->str_output = n;
      out->str_output += 1;
      *out->str_output = '\0';
      out->ret += 1;
      if (out->limit != 0)
	out->limit -= 1;
    }
  else if (out->str_output == NULL)
    if (write(out->fd_output, &n, 1) != -1)
      out->ret += 1;
  return (1);
}

void		myprintf_putstr(const char *str, t_output *out)
{
  int		i;

  i = 0;
  if (str == NULL)
    {
      myprintf_putstr("(null)", out);
      return ;
    }
  while (str[i] != '\0')
    {
      myprintf_putchar(str[i], out);
      i += 1;
    }
}

void		myprintf_putnbr(int nb, t_output *out)
{
  int		div;

  div = 1;
  if (nb == -2147483648)
    myprintf_putstr("-2147483648", out);
  else
    {
      if (nb < 0)
	{
	  myprintf_putchar('-', out);
	  nb = nb * -1;
	}
      while ((nb / div) >= 10)
	div = div * 10;
      div = div * 10;
      while ((div = div / 10) > 0)
	myprintf_putchar((nb / div) % 10 + '0', out);
    }
}

void		myprintf_putunbr(unsigned int nb, t_output *out)
{
  int		div;

  div = 1;
  while ((nb / div) >= 10)
    div = div * 10;
  while (div > 0)
    {
      myprintf_putchar((nb / div) % 10 + '0', out);
      div = div / 10;
    }
}

int		myprintf_strlen(const char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}
