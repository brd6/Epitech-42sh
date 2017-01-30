/*
** main.c for main in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:57:42 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:17:50 2016 fougea_a
*/

#include <stddef.h>
#include <signal.h>
#include "myprintf.h"
#include "my.h"
#include "get_next_line.h"
#include "mysh.h"

t_mysh		g_mysh;

/*
** The main loop command intepreter.
*/
static void	mysh_loop(t_my_builtin *builtins)
{
  char		*line;
  t_list	*cmds;

  while (1)
    {
      prompt_display();
      if (!check_null_line((line = get_next_line(0))) ||
	  !(line = transcript_env_variables(line)))
	break ;
      if (!is_space_str(line) &&
	  (cmds = check_valid_line(line)) != NULL &&
	  exec_multi_cmd(cmds, builtins) == EXIT_PROG)
	break ;
      update_variables_list(line);
      free(line);
    }
  free(line);
}

/*
** Get the user environnement and save it in a linked list.
** @envn : user environnement to copy
** Return : success or not (bool)
*/
static int	get_shell_env(const char **envn)
{
  if (envn == NULL || envn[0] == 0)
    g_mysh.my_env = NULL;
  else
    {
      g_mysh.my_env = my_params_in_list(my_wordtab_count(envn), envn);
      if (g_mysh.my_env == NULL || !my_rev_list(&g_mysh.my_env))
	return (my_putstr(ERR_MALLOC), 0);
    }
  return (1);
}

int		main(int ac, const char **av, const char **envn)
{
  t_my_builtin	*builtins;

  signal(SIGINT, sig_handler_sigint);
  g_mysh.exit_code = 0;
  g_mysh.alias = NULL;
  g_mysh.variables = init_variables_list();
  if (!get_shell_env(envn) || (builtins = init_builtins()) == NULL)
    return (1);
  read_config_file(builtins);
  if (ac > 1)
    read_42sh_file(av[1], builtins);
  else
    mysh_loop(builtins);
  free_mysh();
  return (g_mysh.exit_code);
}
