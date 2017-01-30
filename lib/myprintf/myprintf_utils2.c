/*
** myprintf_utils2.c for tek in /home/fougea_a/libmyc/WIP/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Mon Apr 25 12:23:51 2016 fougea_a
** Last update Mon Apr 25 21:43:56 2016 fougea_a
*/

#include <stddef.h>
#include "private_myprintf.h"

void		myprintf_putnbrbase(unsigned int nb,
				    const char *base,
				    t_output *out)
{
  char		buff[64];
  int		len;
  int		i;

  i = 0;
  if (base == NULL || (len = myprintf_strlen(base)) < 2)
    return ;
  while (nb != 0)
    {
      buff[i++] = base[nb % len];
      nb /= len;
    }
  while (--i >= 0)
    myprintf_putchar(buff[i], out);
}
