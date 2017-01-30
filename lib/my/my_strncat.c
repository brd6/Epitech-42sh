/*
** my_strncat.c for my_strncat in /home/bongol_b/rendu/Piscine_C_J07
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct  7 00:14:02 2015 berdrigue bongolo-beto
** Last update Thu Apr 28 01:40:23 2016 fougea_a
*/

#include <stddef.h>
#include <stdlib.h>

static int	strcat_strlen(const char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i += 1;
  return (i);
}

char	*my_strncat(const char *dest, const char *src, int nb)
{
  char	*ret;
  int	len1;
  int	len2;
  int	i;
  int	j;

  len1 = strcat_strlen(dest);
  len2 = strcat_strlen(src);
  if (nb < len2)
    len2 = nb;
  j = 0;
  if (!(ret = malloc(sizeof(char) * (len1 + len2 + 1))))
    return (NULL);
  while (j < len1)
    ret[j] = dest[j++];
  i = j;
  j = 0;
  while (j < len2)
    ret[i + j] = src[j++];
  ret[i + j] = '\0';
  return (ret);
}
