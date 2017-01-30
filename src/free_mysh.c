/*
** free_mysh.c for free_mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 21 00:08:58 2016 Berdrigue BONGOLO BETO
** Last update Sat Jun  4 23:46:58 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "mylist.h"
#include "mysh.h"

static void	free_alias(void *data)
{
  t_alias_data	*alias;

  alias = data;
  free(alias->alias);
  free(alias);
}

void		free_mysh()
{
  my_free_list(&g_mysh.my_env, NULL);
  my_free_list(&g_mysh.alias, free_alias);
  my_free_list(&g_mysh.variables, NULL);
}
