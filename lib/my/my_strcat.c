/*
** my_strcat.c for my_strcat in /home/bongol_b/rendu/Piscine_C_J07
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct  7 00:09:50 2015 berdrigue bongolo-beto
** Last update Fri Jun  3 20:25:22 2016 Berdrigue BONGOLO BETO
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, const char *src)
{
  int	dest_len;
  int	i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src && src[i])
    {
      dest[i + dest_len] = src[i];
      i = i + 1;
    }
  dest[i + dest_len] = 0;
  return (dest);
}

char	*my_strcat2(char *str1, char *str2)
{
  char	*new;
  int	len1;
  int	len2;

  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  if (!(new = malloc(sizeof(char) * (len1 + len2 + 1))))
    return (NULL);
  new[len1 + len2] = '\0';
  while (--len2 >= 0)
    new[len1 + len2] = str2[len2];
  while (--len1 >= 0)
    new[len1] = str1[len1];
  return (new);
}
