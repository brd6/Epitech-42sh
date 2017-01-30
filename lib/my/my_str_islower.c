/*
** my_str_islower.c for my_str_islower in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 17:04:43 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 13:07:47 2015 berdrigue bongolo-beto
*/

int	is_lower(char c)
{
  return (c >= 'a' && c <= 'z');
}

int	my_str_islower(char *str)
{
  while (*str && is_lower(*str))
    str = str + 1;
  return (!(*str));
}
