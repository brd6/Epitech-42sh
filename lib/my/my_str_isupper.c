/*
** my_str_isupper.c for my_str_isupper in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 17:16:15 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:08:53 2015 berdrigue bongolo-beto
*/

int	is_upper(char c)
{
  return (c >= 'A' && c <= 'Z');
}

int	my_str_isupper(char *str)
{
  while (*str && is_upper(*str))
    str = str + 1;
  return (!(*str));
}
