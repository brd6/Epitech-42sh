/*
** variables_list_utils.c for variables_list_utils in /home/bongol_b/Epitech-rendu/PSU_2015_42sh/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jun  3 20:14:08 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:17:38 2016 fougea_a
*/

#include "my.h"
#include "mysh.h"

t_list		*init_variables_list()
{
  t_list	*vars;
  char		*data;

  vars = NULL;
  data = concat_two_str("version", MYSH_VERSION, "=");
  my_add_elem_in_list_end(&vars, data);
  data = concat_two_str("shell", MYSH_PATH, "=");
  my_add_elem_in_list_end(&vars, data);
  data = concat_two_str("mysh", MYSH_VERSION_CODE, "=");
  my_add_elem_in_list_end(&vars, data);
  data = concat_two_str("_", "", "=");
  my_add_elem_in_list_end(&vars, data);
  data = concat_two_str("prompt", "$> ", "=");
  my_add_elem_in_list_end(&vars, data);
  data = concat_two_str("path", DEFAULT_PATH, "=");
  my_add_elem_in_list_end(&vars, data);
  my_sort_list(&vars, key_cmp);
  return (vars);
}

void		update_variables_list(const char *line)
{
  t_list	*tmp;

  if (env_key_exist(g_mysh.variables, "_"))
    {
      tmp = my_find_node_eq_in_list(g_mysh.variables, "_", find_key);
      line = epur_str(line, "'\"", -1);
      tmp->data = concat_two_str("_", line, "=");
    }
}
