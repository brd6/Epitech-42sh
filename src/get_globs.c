/*
** get_globs.c for get_globs in /home/bruel_a/rendu/42sh_bruel_a
**
** Made by Jonathan bruel
** Login   <bruel_a@epitech.net>
**
** Started on  Tue May 17 10:33:12 2016 Jonathan bruel
** Last update Sun Jun  5 03:18:29 2016 fougea_a
*/

#include <stddef.h>
#include <glob.h>
#include "my.h"
#include "myprintf.h"
#include "parser.h"
#include "mysh.h"

/*
** Return the options of a command by replacing the paths matching pattern
** with glob function.
** @cmd : command with its options
** Return : the new cmd
*/
static int	apply_globing(const char *pattern,
			      int flags,
			      glob_t *globbuf,
			      const char *command)
{
  int		ret;

  ret = glob(pattern, GLOB_FLAGS | flags, NULL, globbuf);
  if (ret == GLOB_NOSPACE || ret == GLOB_ABORTED)
    return (myeprintf(ERR_GLOBING), 0);
  else if (ret == GLOB_NOMATCH)
    return (myeprintf(ERR_NO_MATCH, command), 0);
  return (1);
}

t_cmd		*get_globs(t_cmd *cmd)
{
  glob_t	globbuf;
  int		flags;
  int		i;

  if (cmd == NULL || cmd->command == NULL)
    return (cmd);
  globbuf.gl_offs = 0;
  if (!apply_globing(cmd->options[0], 0, &globbuf, cmd->options[0]))
    return (NULL);
  i = 1;
  while (cmd->options[i])
    {
      flags = GLOB_APPEND;
      if (my_get_char_pos(cmd->options[i], '*') == -1 &&
	  my_get_char_pos(cmd->options[i], '{') == -1)
	flags |= GLOB_NOCHECK;
      if (!apply_globing(cmd->options[i], flags, &globbuf, cmd->options[0]))
	return (NULL);
      i++;
    }
  my_free_wordtab(cmd->options);
  cmd->options = my_tabdup(globbuf.gl_pathv);
  cmd->command = cmd->options[0];
  globfree(&globbuf);
  return (cmd);
}
