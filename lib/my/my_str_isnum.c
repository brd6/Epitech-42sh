/*
** my_str_isnum.c for my_str_isnum in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 16:58:19 2015 berdrigue bongolo-beto
** Last update Mon Feb 29 21:56:43 2016 Berdrigue BONGOLO BETO
*/

int	is_num(char c)
{
  return (c >= '0' && c <= '9');
}

int	my_str_isnum(char *str)
{
  if (*str == '+' || *str == '-')
    str = str + 1;
  while (*str && is_num(*str))
    str = str + 1;
  return (!(*str));
}
