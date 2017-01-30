/*
** flags.h for tek in /home/fougea_a/personnal/WIP/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Tue Apr 19 12:55:36 2016 fougea_a
** Last update Mon Apr 25 21:51:17 2016 fougea_a
*/

#ifndef		PRIVATE_MYPRINTF_H_
# define	PRIVATE_MYPRINTF_H_

# include <stdarg.h>
# include <stddef.h>

/*
** ----{>  Structure flag  <}----
*/
typedef struct		s_output
{
  char			*str_output;
  int			fd_output;
  size_t		limit;
  int			ret;
}			t_output;

typedef struct		s_flag
{
  char			*flag;
  int			(*fcn)(va_list list, t_output *out);
}			t_flag;

void	print_all(const char *format, t_output *out, va_list list);

/*
** ----{>  Flags Functions  <}----
*/
int			flag_modulo(va_list list, t_output *out);
int			flag_char(va_list list, t_output *out);
int			flag_string(va_list list, t_output *out);
int			flag_non_printable_string_chars(va_list list,
							t_output *out);

int			flag_int(va_list list, t_output *out);
int			flag_unsignedint(va_list list, t_output *out);
int			flag_ptr(va_list list, t_output *out);

int			flag_hex(va_list list, t_output *out);
int			flag_hex2(va_list list, t_output *out);
int			flag_oct(va_list list, t_output *out);
int			flag_bin(va_list list, t_output *out);

int			flag_tab1(va_list list, t_output *out);
int			flag_tab2(va_list list, t_output *out);

/*
** ----{>  Utils  <}----
*/
int			myprintf_putchar(char n, t_output *out);
int			myprintf_strlen(const char *str);
void			myprintf_putstr(const char *str, t_output *out);
void			myprintf_putnbr(int nb, t_output *out);
void			myprintf_putunbr(unsigned int nb, t_output *out);
void			myprintf_putnbrbase(unsigned int nb,
					    const char *base,
					    t_output *out);

#endif		/* !PRIVATE_MYPRINTF_H_ */
