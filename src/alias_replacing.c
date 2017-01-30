/*
** alias_replacing.c for alias_replacing in /home/bongol_b/Epitech-rendu/PSU_2015_42sh
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May  4 09:37:26 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:18:05 2016 fougea_a
*/

#include <stdlib.h>
#include "my.h"
#include "parser.h"
#include "mysh.h"
#include "myprintf.h"

static char	*get_first_value_arg(char *value)
{
  char		*arg1;
  int		i;

  if ((arg1 = malloc(sizeof(*arg1) * (my_strlen(value)) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (value[i] && (value[i] != ' ' && value[i] != '\t'))
    {
      arg1[i] = value[i];
      i++;
    }
  arg1[i] = 0;
  return (arg1);
}

static char	*get_corr_alias(char *alias, char *final_value)
{
  t_alias_data	*data;
  t_list	*tmp;
  char		*value;
  char		*key;

  tmp = my_find_node_eq_in_list(g_mysh.alias, alias, alias_find_key);
  if (tmp == NULL || (data = tmp->data) == NULL)
    return (final_value);
  if (data->flag == 2)
    return (my_puterr(ERR_ALIAS_LOOP), NULL);
  data->flag++;
  if (final_value == NULL)
    {
      if ((final_value = get_env_value(data->alias)) == NULL)
	return (myeprintf(ERR_MALLOC), NULL);
    }
  else
    {
      value = final_value + my_strlen(alias);
      final_value = concat_two_str(get_env_value(data->alias), value, NULL);
    }
  key = get_first_value_arg(final_value);
  if (my_strcmp(key, alias) == 0)
    return (final_value);
  return (get_corr_alias(key, final_value));
}

static char	*process_alias_replacing(char *alias, char *new_line)
{
  char		*alias_val;
  char		*first_val;
  char		*tmp;

  if (!alias_key_exist(g_mysh.alias, alias))
    return (new_line);
  alias_val = alias_key_to_value(g_mysh.alias, alias);
  first_val = get_first_value_arg(alias_val);
  if (alias_key_exist(g_mysh.alias, first_val))
    {
      first_val = get_corr_alias(alias, NULL);
      my_apply_on_list(g_mysh.alias, reset_alias_flag);
      if (!first_val)
	return (NULL);
      tmp = my_str_replace(alias, first_val, new_line, -1);
      free(first_val);
      return (tmp);
    }
  else
    {
      tmp = (my_str_replace(alias, alias_val, new_line, -1));
      return (free(alias_val), tmp);
    }
  return (new_line);
}

static char	*alias_replacing_init(int *i,
				      int *j,
				      int *ttype,
				      int *next_is_cmd)
{
  *j = 0;
  *i = 0;
  *next_is_cmd = 1;
  *ttype = TOKEN_UNKNOWN;
  return (NULL);
}

char		*alias_replacing(char *line)
{
  int		i;
  int		ttype;
  int		j;
  char		*str_cmd;
  int		next_is_cmd;
  char		*new_line;

  str_cmd = alias_replacing_init(&i, &j, &ttype, &next_is_cmd);
  new_line = line;
  while (line[i])
    {
      str_cmd = get_token(&j, i, line, &ttype);
      if (j == -2)
	return (NULL);
      if (j > 0)
	{
	  if (next_is_cmd && (line[i] != '\'' && line[i] != '"'))
	    new_line = process_alias_replacing(str_cmd, new_line);
	  next_is_cmd = (ttype == TOKEN_OPERATOR);
	  i = i + j;
	}
      else
	i++;
    }
  return (new_line);
}
