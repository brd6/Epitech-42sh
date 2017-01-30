/*
** check_valid_line_utils.c for check_valid_line_utils in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Apr 10 11:35:37 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:17:15 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "mysh.h"

static void	init_parsing_line_var(int *i,
				      t_list2 **list,
				      int *j)
{
  *i = 0;
  *list = NULL;
  *j = 0;
}

/*
** Return the token relative to the end_pos in str
** return: string
*/
static char	*get_str_cmd(char *str, int end_pos)
{
  char		*str_cmd;

  if ((str_cmd = malloc(sizeof(*str_cmd) * (my_strlen(str) + 1))) == NULL)
    return (my_puterr(ERR_MALLOC), NULL);
  my_strncpy(str_cmd, str, end_pos);
  return (str_cmd);
}

char		*get_token(int *j,
			   int i,
			   char *line,
			   int *ttype)
{
  if (((*j = check_next_operator(&line[i])) > -1 &&
       ((*ttype = TOKEN_OPERATOR))) ||
      ((*j = check_next_command(&line[i])) > -1 &&
       ((*ttype = TOKEN_COMMAND))))
    return (get_str_cmd(&line[i], *j));
  return (NULL);
}

/*
** Add a token to the list and check for useless ";"
** @list : a double linked list containing the tokens and their type
** @str : a token to add (operator or command)
** @type : token's type
*/
static int		add_to_cmd_list(t_list2 **list,
					char *str,
					int type)
{
  t_parser		*parser;
  t_parser		*parser_tmp;

  if (((*list != NULL &&
       (parser_tmp = ((t_parser *)((*list)->data))) &&
       type == TOKEN_OPERATOR && parser_tmp != NULL &&
       parser_tmp->token[0] == OP_AND[0]) || *list == NULL) &&
      str[0] == OP_AND[0])
    return (1);
  if ((parser = malloc(sizeof(*parser))) == NULL)
    return (my_puterr(ERR_MALLOC), 0);
  if (*list != NULL && (type == TOKEN_COMMAND || type == TOKEN_OPTION) &&
      (parser_tmp = ((t_parser *)((*list)->data))) &&
      (parser_tmp->type == TOKEN_COMMAND || parser_tmp->type == TOKEN_OPTION))
    parser->type = TOKEN_OPTION;
  else
    parser->type = type;
  parser->token = str;
  if (parser->token[0] == '~' &&
      (parser->token = tilde_replacing(str)) == NULL)
    return (0);
  my_add_elem_in_list2_begin(list, parser);
  return (1);
}

/*
** Parse the line and return a double linked list of command's token
** @line : line to parse
** return : double linked list
*/
t_list2		*parsing_line(char *line)
{
  int		i;
  int		ttype;
  int		j;
  char		*str_cmd;
  t_list2	*list;

  init_parsing_line_var(&i, &list, &j);
  str_cmd = NULL;
  ttype = TOKEN_UNKNOWN;
  while (line[i])
    {
      str_cmd = get_token(&j, i, line, &ttype);
      if (j == -2)
	return (NULL);
      if (j > 0)
	{
	  if ((ttype == TOKEN_OPERATOR && !check_str_operator(list, str_cmd)) ||
	      (!add_to_cmd_list(&list, str_cmd, ttype)))
	    return (NULL);
	  i = i + j;
	}
      else
	i++;
    }
  return (list);
}
