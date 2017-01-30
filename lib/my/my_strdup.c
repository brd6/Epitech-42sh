/*
** my_strdup.c for my_strdup in /home/bongol_b/rendu/Piscine_C_J08/ex_01
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct  7 13:36:20 2015 berdrigue bongolo-beto
** Last update Fri Jun  3 20:17:46 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(const char *src)
{
  char	*src_cp;
  int	src_len;

  if (src == NULL)
    return (NULL);
  src_len = my_strlen(src);
  src_cp = malloc((src_len + 1));
  if (src_cp == NULL)
    return (NULL);
  my_strcpy(src_cp, src);
  src_cp[src_len] = 0;
  return (src_cp);
}
