/*
** env_util.c for env_util in /home/bongol_b/rendu/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan  8 02:28:31 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 22:41:52 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my.h"
#include "myprintf.h"
#include "mysh.h"

char		*get_env_key(char *env_data)
{
  char		*key;
  int		i;

  if ((key = malloc(sizeof(*key) * (my_strlen(env_data) + 1))) == NULL)
    return (my_puterr(ERR_MALLOC), NULL);
  i = 0;
  while (env_data && env_data[i])
    {
      if (env_data[i] == '=')
	break ;
      key[i] = env_data[i];
      i++;
    }
  key[i] = 0;
  return (key);
}

char		*get_env_value(char *env_data)
{
  char		*value;
  int		i;
  int		j;

  if ((value = malloc(sizeof(*value) * (my_strlen(env_data) + 1))) == NULL)
    return (my_puterr(ERR_MALLOC), NULL);
  i = 0;
  j = 0;
  while (env_data && env_data[i])
    {
      if (env_data[i] == '=')
	break ;
      i++;
    }
  if (env_data[i] != 0 && env_data[i + 1] != 0)
    {
      i++;
      while (env_data && env_data[i])
	value[j++] = env_data[i++];
    }
  value[j] = 0;
  return (value);
}

char		*key_to_value(t_list *env, char *key)
{
  t_list	*curr;

  if (env == NULL || key == NULL)
    return (NULL);
  curr = env;
  while (curr != NULL)
    {
      if (my_strcmp(get_env_key(curr->data), key) == 0)
	return (get_env_value(curr->data));
      curr = curr->next;
    }
  return (NULL);
}

char		**env_list_to_array(t_list *my_env)
{
  char		**tab;
  int		j;
  char		*s;

  if ((tab = malloc(sizeof(*tab) * (my_list_size(my_env) + 2))) == NULL)
    return (myeprintf(ERR_MALLOC), NULL);
  j = 0;
  while (my_env)
    {
      s = my_env->data;
      tab[j++] = my_strdup(s);
      my_env = my_env->next;
    }
  tab[j] = NULL;
  return (tab);
}
