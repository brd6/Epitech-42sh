/*
** print_special_char.c for tek in /home/fougea_a/rendu/Programmation Shell/PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Fri May 20 23:56:52 2016 fougea_a
** Last update Sat May 21 15:42:12 2016 fougea_a
*/

#include <stddef.h>
#include "myprintf.h"
#include "mysh.h"
#include "my.h"

int		print_special_char(const char *str)
{
  const char	*seq;
  const char	*esc;
  int		len;

  if (!(esc = extract_escaped_sequence(str)) ||
      !(seq = get_special_sequence(esc)))
    return (1);
  myprintf("%s", seq);
  len = my_strlen(esc);
  return (len);
}
