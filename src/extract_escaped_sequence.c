/*
** extract_escaped_sequence.c for tek in /home/fougea_a/rendu/Programmation Shell/PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Sat May 21 14:57:23 2016 fougea_a
** Last update Sat May 21 15:41:05 2016 fougea_a
*/

#include <stddef.h>
#include "mysh.h"

static t_repl_char		g_repl[] =
  {
    {"\\033", "\033"},
    {"\\\"", "\""},
    {"\\\'", "\'"},
    {"\\r", "\r"},
    {"\\n", "\n"},
    {"\\\\", "\\"},
    {NULL, NULL}
  };

const char	*get_special_sequence(const char *escaped_sequence)
{
  int		i;

  i = 0;
  while (g_repl[i].name)
    {
      if (g_repl[i].name == escaped_sequence)
	return (g_repl[i].repl);
      i += 1;
    }
  return (NULL);
}

const char	*extract_escaped_sequence(const char *str)
{
  int		i;
  int		j;

  i = 0;
  while (g_repl[i].name)
    {
      j = 0;
      while (str[j] != '\0' && g_repl[i].name[j] == str[j])
	j += 1;
      if (g_repl[i].name[j] == '\0')
	return (g_repl[i].name);
      i += 1;
    }
  return (NULL);
}
