/*
** myprintf.h for tek in /home/fougea_a/personnal/myprintf
**
** Made by fougea_a
** Login   <fougea_a@epitech.net>
**
** Started on  Mon Apr 18 14:05:21 2016 fougea_a
** Last update Tue May 17 10:39:09 2016 fougea_a
*/

#ifndef		MYPRINTF_H_
# define	MYPRINTF_H_

# include <stddef.h>

/*
**	--===={>  DESCRIPTION  <}====--
**
** All of these functions print the format string by
** replacing all the flags (man printf) by it's
** value, stored in order after the format argument.
**
**
**	--===={>  SYNOPSIS  <}====--
**
** myprintf   writes on the stdout (1).
** myeprintf  writes on the stderr (2).
** mydprintf  writes on the fd given in parameter.
**
** mysprintf  writes in the buffer
** mysnprintf writes in the buffer but will stop at <size - 1> chars
**
**
**	--===={>  WARNING  <}====--
**
**  The last two functions automatically add a null char
**       Be sure to plan this while sizing buffer
*/
int			myprintf(const char *format, ...);
int			myeprintf(const char *format, ...);
int			mydprintf(int fd, const char *format, ...);
int			mysprintf(char *buff, const char *format, ...);
int			mysnprintf(char *buff,
				   size_t size,
				   const char *format,
				   ...);

#endif		/* !MYPRINTF_H_ */
