/*
** my_wordtab_to_str.c for my_wordtab_to_str in /home/bongol_b/rendu_ok/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Jan 19 20:06:54 2016 Berdrigue BONGOLO BETO
** Last update Fri Jun  3 20:30:54 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

char		*my_wordtab_to_str(const char **args, char sp)
{
  char		*arg;
  int		i;
  int		j;
  int		k;

  j = my_wordtab_word_count(args);
  i = 0;
  if ((arg = malloc(sizeof(*arg) * (j + my_wordtab_count(args) + 1))) == NULL)
    return (0);
  j = 0;
  k = 0;
  while (args[i])
    {
      if (args[i][k] != 0)
	arg[j++] = args[i][k++];
      else
	{
	  if (args[i + 1] != NULL)
	    arg[j++] = sp;
	  k = 0;
	  i++;
	}
    }
  arg[j] = 0;
  return (arg);
}
