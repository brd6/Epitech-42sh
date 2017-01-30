/*
** my.h for my in /home/bongol_b/rendu/Piscine_C_workshoplib
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 16 01:09:57 2015 berdrigue bongolo-beto
** Last update Sat Jun  4 00:10:02 2016 Berdrigue BONGOLO BETO
*/

#ifndef MY_H_
# define MY_H_

# include <stddef.h>

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(const char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *dest, const char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strcmp2(const char *s1, const char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
int	my_str_isalpha(char *str);
int	is_num(char c);
int	is_alpha(char c);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	is_printable(char c);
char	*my_strcat(char *dest, const char *src);
char	*my_strdup(const char *src);
int	my_show_wordtab(char **);
char	**my_str_split(const char *str, const char *sp);
int	my_nbr_len(int nbr);
char	*my_itoa(int nbr);
int	my_get_char_pos(const char *str, char c);
int	my_wordtab_count(const char **);
void	my_puterr(char *str);
char	*my_str_replace(char *search, char *replace, char *subject, int n);
int	my_str_isalphanum(char *str);
int	is_alpha(char c);
char	*my_wordtab_to_str(const char **args, char sp);
int	my_wordtab_word_count(const char **args);
void	my_free_wordtab(char **);
char	*my_wordtab_search(char **, char *data, int (*cmp)());
char	*my_strncat(const char *dest, const char *src, int nb);
char	*my_strcat2(char *str1, char *str2);
char	**my_tabdup(char **tab);
char	*mystrcat(size_t count, ...);

#endif /* !MY_H_ */
