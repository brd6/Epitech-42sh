/*
** config.h for tek in /home/fougea_a/rendu/Programmation Shell/PSU_2015_42sh
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Sun Jun  5 02:27:45 2016 fougea_a
** Last update Sun Jun  5 03:03:53 2016 fougea_a
*/

#ifndef CONFIG_H_
# define CONFIG_H_

/*
** /|====================|l
** ||     Settings       ||
** \|====================|/
*/
# define GO_ON			1
# define EXIT_PROG		42
# define FLG_FILE_PERM		(S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)
# define FLG_FILE_CWRITE	(O_WRONLY | O_TRUNC | O_CREAT)
# define FLG_FILE_CWRITE2	(O_WRONLY | O_APPEND | O_CREAT)
# define GLOB_FLAGS		(GLOB_BRACE | GLOB_NOMAGIC | GLOB_ERR)
# define HEREDOC_TMP1		"/tmp/.mysh_heredoc_%pid%"
# define HEREDOC_TMP2		".mysh_heredoc_%pid%"
# define EXIT_MSG		"exit\n"
# define MAX_CMD_LEN		1024
# define BUILTIN_NB		13
# define MYSH_VERSION		"42sh 1.24.42.1 (Epitech) 2016-03-06"
# define MYSH_VERSION_CODE	"1.24.42.1"
# define MYSH_PATH		"./42sh"
# define DEFAULT_PATH		"(/usr/bin /bin)"
# define MYSH_CONFIG_FILE	".42shrc"

/*
** Parser
*/
# define TOKEN_UNKNOWN		-1
# define TOKEN_COMMAND		1
# define TOKEN_OPTION		2
# define TOKEN_OPERATOR		3
# define SEP_NONE		0
# define SEP_OR			1
# define SEP_AND		2
# define OPS			";|><&"
# define OP_PIPE		"|"
# define OP_AND			";"
# define OP_R_REDIRECT		">"
# define OP_RR_REDIRECT		">>"
# define OP_L_REDIRECT		"<"
# define OP_LL_REDIRECT		"<<"
# define OP_DOUBLE_AND		"&&"
# define OP_SIMPLE_AND		"&"
# define OP_DOUBLE_PIPE		"||"

/*
** /|====================|l
** ||      Errors        ||
** \|====================|/
*/
# define ERR_UNSETENV_ARG "%s: Too few arguments.\n"
# define ERR_SETENV_ARG "setenv: Too many arguments.\n"
# define ERR_SET_ALIAS "alias: Unable to set a new alias\n"
# define ERR_SET_VAR "set: Unable to set a new variable\n"
# define ERR_UNDEF_VAR "Error: The %s variable is not defined.\n"
# define ERR_SETENV_VARNAME1 "%s: Variable name must begin with a letter.\n"
# define ERR_SETENV_MALLOC "setenv: Unable to set a new variable to the env\n"
# define ERR_ENV_ARG_FILE "env: %s: Aucun fichier ou dossier de ce type\n"
# define ERR_ENV_ARG_DIR "env: %s: Aucun fichier ou dossier de ce type\n"
# define ERR_COMMAND_NOT_FOUND ": Command not found.\n"
# define ERR_PERMISSION_DENIED ": Permission denied.\n"
# define ERR_FLOATING_PTS_EXCP1	"Floating exception (core dumped)\n"
# define ERR_FLOATING_PTS_EXCP2	"Floating exception\n"
# define ERR_SEGMENTATION_FAULT1 "Segmentation fault (core dumped)\n"
# define ERR_SEGMENTATION_FAULT2 "Segmentation fault\n"
# define ERR_FILE_NOEXIST "'%s': No such file or folder type.\n"
# define ERR_FILE_NOACCESS "%s: Permission denied.\n"
# define ERR_NODIRECTORY "%s: Not a directory.\n"
# define ERR_EXIT_EXPR_SYNTAX "exit: Expression Syntax.\n"
# define ERR_TILDE_USER	"Unknown user: %s.\n"
# define ERR_CONFIG_FILE "Unable to read config file.\n"
# define ERR_SETENV_VARNAME2 "%s: Variable name must contain \
alphanumeric characters.\n"

/*
** System function failed
*/
# define ERR_GLOBING	"Error glob.\n"
# define ERR_MALLOC	"Malloc error\n"
# define ERR_FORK	"Error : unable to create a new process\n"
# define ERR_DUP2	"dup2 error\n"
# define ERR_PIPE	"pipe error\n"
# define ERR_OPEN_FILE	"Unable to open file\n"
# define ERR_HEREDOC	"heredoc error\n"
# define ERR_EXECVE	"Execve: an error has occurred\n"
# define ERR_GETWCD	"getcwd error\n"

/*
** Command line errors
*/
# define ERR_UNMATCH	"Unmatched %c.\n"
# define ERR_ENV_PATH	"There aren't PATH in the env variable\n"
# define ERR_NO_MATCH	"%s: No match.\n"
# define ERR_ALIAS_LOOP	"Alias loop.\n"
# define ERROR_1	"Invalid null command.\n"
# define ERROR_2	"Missing name for redirect.\n"
# define ERROR_3	"Unmatched \".\n"
# define ERROR_4	"Ambiguous output redirect.\n"
# define ERROR_5	"Ambiguous input redirect.\n"
# define ERR_TOKEN	"Unmatched token %c\n"

#endif /* !CONFIG_H_ */
