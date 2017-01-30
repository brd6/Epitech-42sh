/*
** mysh.h for mysh in /home/bongol_b/Epitech-rendu/PSU_2015_minishell2
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Mar 20 21:55:09 2016 Berdrigue BONGOLO BETO
** Last update Sun Jun  5 03:13:22 2016 fougea_a
*/

#ifndef MYSH_H_
# define MYSH_H_

# include "mylist.h"
# include "config.h"
# include "parser.h"

typedef struct	s_alias_data
{
  char		*alias;
  int		flag;
}		t_alias_data;

typedef struct	s_mysh
{
  t_list	*my_env;
  t_list	*alias;
  t_list	*variables;
  int		exit_code;
}		t_mysh;

typedef struct	s_my_builtin
{
  char		*name;
  int		(*func)(t_cmd *cmd);
}		t_my_builtin;

typedef struct	s_repl_char
{
  char		*name;
  char		*repl;
}		t_repl_char;

extern t_mysh		g_mysh;

void		free_mysh(void);
void		sig_handler_sigint(int code);
char		*epur_str(const char *str,
			  const char *to_remove,
			  int replace_with_space);
int		is_space_str(char *str);
char		*concat_two_str(const char *str1, const char *str2, char *c);
int		find_key(char *data, char *data_ref);
int		directory_exist(char *dirr);
int		is_space_char(char c);
t_cmd		*get_globs(t_cmd *cmd);
void		read_42sh_file(const char *filename, t_my_builtin *builtins);
void		update_variables_list(const char *line);
t_list		*init_variables_list(void);
int		key_cmp(void *data, void *data_ref);
void		pipe_exec(t_cmd *cmd,
			  t_my_builtin *builtins,
			  t_list *tmp);
void		pipe_son_dup(int *pipefd, int *fd_in, t_list **tmp, int flag);

/*
** Parser
*/
char		*get_token(int *j,
			   int i,
			   char *line,
			   int *ttype);
int		check_null_line(char *line);
t_list		*check_valid_line(char *line);
void		read_config_file(t_my_builtin *builtins);
char		*replace_line(const char *src, int end);
int		replace_escaped_seq(const char *str, char *n);
char		*replace_env_seq(const char *str, int *len);
int		print_special_char(const char *str);
const char	*get_special_sequence(const char *escaped_sequence);
const char	*extract_escaped_sequence(const char *str);
char		*transcript_env_variables(char *old);

/*
** Env
*/
int		env_key_exist(t_list *my_env, char *key);
char		*key_to_value(t_list *env, char *key);
int		env_key_exist_v(t_list *my_env, char *key);
char		**env_list_to_array(t_list *my_env);
int		builtin_setenv_cond(t_list *my_env, char **args);
int		syntax_env_key(char *key);
char		*get_env_value(char *env_data);
char		*get_env_key(char *env_data);
char		*extract_env_key(const char *str);

/*
** Exec
*/
int		check_bin_permission(char *bin);
int		father_process_action(int son_pid);
void		son_process_action(t_cmd *cmd);
char		*get_bin_path(char *bin,
			      const char *str_path,
			      const char *str_path2);
struct stat	my_stat(char *file);
int		redirect_right(char *type, char *filename);
int		redirect_left(char *type, char *filename);
int		redirect_cmd(t_cmd *cmd);
t_list		*my_heredoc(char *eof);
char		*filewrite_heredoc(t_list *list);
int		exec_multi_cmd(t_list *cmd,
			       t_my_builtin *builtins);
int		exec_simple_cmd(t_cmd *cmd,
				t_my_builtin *builtins);
int		exec_multi_pipes(t_cmd *cmd2,
				 t_my_builtin *builtins,
				 t_cmd **exit_cmd);
int		exec_builtins(t_my_builtin *builtins,
			      t_cmd *cmd,
			      int builtin_index);

/*
** builtins
*/
t_my_builtin	*init_builtins();
int		is_builins_cmd(char *cmd, t_my_builtin *builtins);
int		builtin_exit(t_cmd *cmd);
int		builtin_cd(t_cmd *cmd);
int		builtin_env(t_cmd *cmd);
int		builtin_setenv(t_cmd *cmd);
int		builtin_unsetenv(t_cmd *cmd);
int		builtin_alias(t_cmd *cmd);
int		builtin_unalias(t_cmd *cmd);
int		builtin_setalias(t_cmd *cmd, char *key, char *value);
int		builtin_echo(t_cmd *cmd);
int		builtin_set(t_cmd *cmd);
int		builtin_unset(t_cmd *cmd);

/*
** Alias
*/
char		*alias_replacing(char *line);
char		*alias_key_to_value(t_list *alias, char *key);
int		alias_key_exist(t_list *alias, char *key);
int		alias_find_key(t_alias_data *data, void *data_ref);
char		*get_alias_value(char *key);
void		reset_alias_flag(t_alias_data *data);

/*
** Tilde
*/
char		*tilde_replacing(char *str);

/*
** prompt
*/
void		prompt_display(void);

#endif /* !MYSH_H_ */
