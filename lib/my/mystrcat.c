/*
** mystrcat.c for tek in /home/fougea_a/libmyc/WIP/mystrcat
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Tue Apr 19 14:58:56 2016 fougea_a
** Last update Sat May 21 23:02:43 2016 fougea_a
*/

#include <stdlib.h>
#include <stdarg.h>

static char	*str_concat(char *str1, char *str2)
{
  char		*ret;
  int		len1;
  int		len2;

  len1 = 0;
  if (str1)
    while (str1[len1] != '\0')
      len1 += 1;
  len2 = 0;
  if (str2)
    while (str2[len2] != '\0')
      len2 += 1;
  if (!(ret = malloc(sizeof(char) * (len1 + len2 + 1))))
    return (NULL);
  ret[len1 + len2] = '\0';
  while (--len2 >= 0)
    ret[len1 + len2] = str2[len2];
  while (--len1 >= 0)
    ret[len1] = str1[len1];
  return (ret);
}

static char	*adding_loop(size_t count, char *ret, va_list list)
{
  char		*str;

  if (count == 0)
    return (ret);
  str = va_arg(list, char *);
  if (!(ret = str_concat(ret, str)) ||
      !(ret = adding_loop(count - 1, ret, list)))
    return (NULL);
  return (ret);
}

char		*mystrcat(size_t count, ...)
{
  va_list	list;
  char		*str;

  va_start(list, count);
  str = adding_loop(count, NULL, list);
  va_end(list);
  return (str);
}
