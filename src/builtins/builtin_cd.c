/*
** builtin_cd.c<builtins> for builtin_cd in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Apr  5 17:31:23 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:16:22 2016 fougea_a
*/

#include <unistd.h>
#include <stdlib.h>
#include <linux/limits.h>
#include "my.h"
#include "mysh.h"
#include "myprintf.h"

static char	*get_goto_dir(char **args, char *oldpwd)
{
  if ((args[1] == NULL || args[1][0] == 0) &&
      env_key_exist(g_mysh.my_env, "HOME"))
    return (key_to_value(g_mysh.my_env, "HOME"));
  if (!my_strcmp(args[1], "-") && oldpwd != NULL)
    return (oldpwd);
  if (!my_strcmp(args[1], "~") && env_key_exist(g_mysh.my_env, "HOME"))
    return (key_to_value(g_mysh.my_env, "HOME"));
  return (my_strdup(args[1]));
}

static void	builtin_cd_replacing_pwd(char *cwd, char *flag)
{
  char		*pwd_value;
  t_list	*tmp;

  if (!env_key_exist(g_mysh.my_env, "PWD"))
    {
      pwd_value = concat_two_str("PWD", cwd, "=");
      my_add_elem_in_list_end(&g_mysh.my_env, pwd_value);
      return ;
    }
  if ((tmp = my_find_node_eq_in_list(g_mysh.my_env, flag, find_key)))
    {
      pwd_value = key_to_value(g_mysh.my_env, flag);
      if (!pwd_value || !pwd_value[0])
	tmp->data = concat_two_str(tmp->data, cwd, "=");
      else
	tmp->data = my_str_replace(pwd_value, cwd, tmp->data, 1);
      free(pwd_value);
    }
}

static int	check_for_error(char *goto_dir)
{
  if (access(goto_dir, F_OK) != 0)
    return (mydprintf(2, ERR_FILE_NOEXIST, goto_dir), 0);
  if (access(goto_dir, R_OK) != 0)
    return (mydprintf(2, ERR_FILE_NOACCESS, goto_dir), 0);
  return (1);
}

int		builtin_cd(t_cmd *cmd)
{
  static char	*oldpwd;
  char		*goto_dir;
  int		res;
  char		buf[PATH_MAX + 1];
  char		*cwd;

  if ((goto_dir = get_goto_dir(cmd->options, oldpwd)) == NULL ||
      !check_for_error(goto_dir))
    return (!(cmd->status = 1));
  if ((cwd = getcwd(buf, PATH_MAX + 1)) == NULL)
    return (my_puterr(ERR_GETWCD), !(cmd->status = 1));
  if (!(oldpwd = my_strdup(cwd)))
    return (myeprintf(ERR_MALLOC), !(cmd->status = 1));
  if ((res = chdir(goto_dir)) == -1 ||
      (cwd = getcwd(buf, PATH_MAX + 1)) == NULL)
    return (mydprintf(2, ERR_NODIRECTORY, goto_dir), !(cmd->status = 1));
  builtin_cd_replacing_pwd(cwd, "PWD");
  free(goto_dir);
  return (!(cmd->status = 0));
}
