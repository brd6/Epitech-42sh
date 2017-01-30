/*
** myprintf.c for tek in /home/fougea_a/personnal/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Mon Apr 18 12:43:58 2016 fougea_a
** Last update Thu Apr 21 01:31:43 2016 fougea_a
*/

#include <stddef.h>
#include "private_myprintf.h"

int			myprintf(const char *format, ...)
{
  t_output		out;
  va_list		list;

  if (format == NULL)
    return (-1);
  out.ret = 0;
  out.str_output = NULL;
  out.fd_output = 1;
  va_start(list, format);
  print_all(format, &out, list);
  va_end(list);
  return (out.ret);
}

int			myeprintf(const char *format, ...)
{
  t_output		out;
  va_list		list;

  if (format == NULL)
    return (-1);
  out.ret = 0;
  out.str_output = NULL;
  out.fd_output = 2;
  va_start(list, format);
  print_all(format, &out, list);
  va_end(list);
  return (out.ret);
}

int			mydprintf(int fd, const char *format, ...)
{
  t_output		out;
  va_list		list;

  if (format == NULL)
    return (-1);
  out.ret = 0;
  out.str_output = NULL;
  out.fd_output = fd;
  va_start(list, format);
  print_all(format, &out, list);
  va_end(list);
  return (out.ret);
}

int			mysprintf(char *buff, const char *format, ...)
{
  t_output		out;
  va_list		list;

  if (format == NULL || buff == NULL)
    return (-1);
  out.ret = 0;
  out.str_output = buff;
  out.limit = -1;
  va_start(list, format);
  print_all(format, &out, list);
  va_end(list);
  return (out.ret);
}

int			mysnprintf(char *buff,
				   size_t size,
				   const char *format,
				   ...)
{
  t_output		out;
  va_list		list;

  if (format == NULL || buff == NULL)
    return (-1);
  out.ret = 0;
  out.str_output = buff;
  out.limit = size;
  va_start(list, format);
  print_all(format, &out, list);
  va_end(list);
  return (out.ret);
}
