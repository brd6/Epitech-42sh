/*
** myprintf_flags.c for tek in /home/fougea_a/personnal/WIP/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Tue Apr 19 11:17:59 2016 fougea_a
** Last update Mon Apr 25 17:38:33 2016 fougea_a
*/

#include <stddef.h>
#include <stdarg.h>
#include "private_myprintf.h"

static t_flag		g_flags[] =
  {
    {"%", &flag_modulo},
    {"t2", &flag_tab2},
    {"t", &flag_tab1},
    {"c", &flag_char},
    {"s", &flag_string},
    {"S", &flag_non_printable_string_chars},
    {"d", &flag_int},
    {"i", &flag_int},
    {"u", &flag_unsignedint},
    {"x", &flag_hex},
    {"X", &flag_hex2},
    {"o", &flag_oct},
    {"b", &flag_bin},
    {"p", &flag_ptr},
    {NULL, NULL}
  };

static int		print_arg(const char *_str,
				  va_list list,
				  t_output *out)
{
  const char		*str;
  int			len;
  int			i;
  int			j;

  i = 0;
  len = -1;
  str = _str + 1;
  while (len == -1 && g_flags[i].flag != NULL)
    {
      j = 0;
      while (g_flags[i].flag[j] != '\0' && str[j] == g_flags[i].flag[j])
	j += 1;
      if (g_flags[i].flag[j] == '\0' && g_flags[i].fcn != NULL)
	if (g_flags[i].fcn(list, out) != -1)
	  len = myprintf_strlen(g_flags[i].flag);
      i += 1;
    }
  return (len + 1);
}

void		print_all(const char *format,
			  t_output *out,
			  va_list list)
{
  int		tmp;
  int		i;

  i = 0;
  while (format[i] != '\0')
    if (format[i] == '%' &&
	(tmp = print_arg(format + i, list, out)) > 0)
      i += tmp;
    else
      i += myprintf_putchar(format[i], out);
}
