/*
** prompt.c for tek in PSU_2015_42sh/src/config
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Tue Apr 26 10:45:44 2016 fougea_a
** Last update Sat Jun  4 16:38:16 2016 fougea_a
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "myprintf.h"
#include "mysh.h"
#include "my.h"

static int	display_env_var(char *key)
{
  char		*data;
  int		i;

  if (!(data = key_to_value(g_mysh.my_env, key)) &&
      !(data = key_to_value(g_mysh.variables, key)))
    return (myprintf("$"), 1);
  myprintf("%s", data);
  free(data);
  i = my_strlen(key) + 1;
  free(key);
  return (i);
}

void		prompt_display(void)
{
  char		*prompt;
  char		*key;
  int		i;

  i = 0;
  prompt = NULL;
  if (!isatty(0) && !isatty(1))
    return ;
  if (!(env_key_exist(g_mysh.variables, "prompt")) ||
      !(prompt = key_to_value(g_mysh.variables, "prompt")))
    my_putstr("$> ");
  else
    while (prompt[i] != '\0')
      if (prompt[i] == '$' && (key = extract_env_key(prompt + i)) != NULL)
	i += display_env_var(key);
      else if (prompt[i] == '\\')
	i += print_special_char(prompt + i);
      else
	my_putchar(prompt[i++]);
  free(prompt);
}
