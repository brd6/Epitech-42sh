/*
** flag_tabs.c for tek in /home/fougea_a/personnal/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Mon Apr 18 22:55:20 2016 fougea_a
** Last update Tue Apr 26 00:38:48 2016 fougea_a
*/

#include <stddef.h>
#include <stdarg.h>
#include "private_myprintf.h"

int		flag_tab1(va_list list, t_output *out)
{
  char		**tab;
  int		i;

  i = 0;
  tab = (char **)va_arg(list, char *);
  if (tab == NULL)
    myprintf_putstr("(nil)", out);
  else
    while (tab[i] != NULL)
      {
	if (i != 0)
	  myprintf_putchar('\n', out);
	myprintf_putstr(tab[i], out);
	i += 1;
      }
  return (0);
}

int		flag_tab2(va_list list, t_output *out)
{
  char		***tab;
  int		i;
  int		j;

  i = 0;
  tab = (char ***)va_arg(list, char *);
  while (tab[i] != NULL)
    {
      j = 0;
      if (i != 0)
	myprintf_putstr("\n\n", out);
      while (tab[i][j] != NULL)
	{
	  if (j != 0)
	    myprintf_putchar('\n', out);
	  myprintf_putstr(tab[i][j], out);
	  j += 1;
	}
      i += 1;
    }
  return (0);
}
