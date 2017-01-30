/*
** parser_checker2.c for parser_checker2 in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 27 16:21:07 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:18:55 2016 fougea_a
*/

#include "my.h"
#include "mysh.h"
#include "parser.h"
#include "myprintf.h"

static void	set_nb_quote(char *line,
			     int i,
			     int *quote_cp,
			     int *quote_pos)
{
  if (line[i] == '"' && quote_cp[1] % 2 == 0)
    {
      *quote_pos = i;
      quote_cp[0]++;
    }
  else if (line[i] == '\'' && quote_cp[0] % 2 == 0)
    {
      *quote_pos = i;
      quote_cp[1]++;
    }
}

/*
** check if there are an operator in the next line.
** return : the end position of operator
*/
int		check_next_operator(char *line)
{
  if (line[0] != 0 && my_get_char_pos(OPS, line[0]) != -1)
    {
      if (my_get_char_pos(&OPS[1], line[1]) != -1 && line[0] == line[1])
	return (2);
      return (1);
    }
  return (-1);
}

/*
** check if there are a command in the next line.
** return : the end position of command
*/
int		check_next_command(char *line)
{
  int		quote_cp[2];
  int		i;
  int		quote_pos;
  char		end_char;

  end_char = (line[0] == '"' || line[0] == '\'') ? line[0] : ' ';
  if (end_char == ' ' && (line[0] == ' ' || line[0] == '\t'))
    return (-1);
  quote_cp[0] = 0;
  quote_cp[1] = 0;
  quote_pos = 0;
  i = 0;
  while (line[i])
    {
      set_nb_quote(line, i, quote_cp, &quote_pos);
      if ((line[i + 1] == 0 || is_space_char(line[i + 1]) ||
	   (my_get_char_pos(OPS, line[i + 1]) != -1)) &&
	  (quote_cp[0] % 2 == 0 && quote_cp[1] == 0) && ++i)
	break ;
      i++;
    }
  if (quote_cp[0] % 2 != 0 || quote_cp[1] % 2 != 0)
    return (myeprintf(ERR_UNMATCH, line[quote_pos]), -2);
  return (i);
}
