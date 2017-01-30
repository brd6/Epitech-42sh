/*
** my_getnbr.c for my_getnbr in /home/bongol_b/rendu/Piscine_C_J04
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Oct  1 13:45:13 2015 berdrigue bongolo-beto
** Last update Sun Oct 25 15:24:32 2015 berdrigue bongolo-beto
*/

int	my_get_operator_sign(char *str)
{
  int	sign;

  sign = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	  sign = sign * (-1);
      str = str + 1;
    }
  return (sign);
}

int	my_get_nbr_start(char *str)
{
  int	start;

  start = 0;
  while (*str == '-' || *str == '+')
    {
      start = start + 1;
      str = str + 1;
    }
  return (start);
}

int	my_check_int_limit(int res, int sign, char *str, int i)
{
  if (res > 214748364)
      return (0);
  else if (res == 214748364 && str[i] > 7 && sign == 1)
    return (0);
  else if (res == 214748364 && *str > 8 && sign == -1)
      return (0);
  return (1);
}

int	my_getnbr(char *str)
{
  int	sign;
  int	res;
  int	i;
  int	str_length;

  sign = my_get_operator_sign(str);
  res = 0;
  i = my_get_nbr_start(str);
  str_length = i;
  while (str[str_length])
      str_length = str_length + 1;
  if (str_length - i > 10)
    return (0);
  while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
    {
      if (!my_check_int_limit(res, sign, str, i))
	  return (0);
      res = res * 10 + str[i] - 48;
      i = i + 1;
    }
  return (res * sign);
}
