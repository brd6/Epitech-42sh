/*
** my_strncmp.c for my_strncmp in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 15:35:26 2015 berdrigue bongolo-beto
** Last update Wed Apr 13 07:53:50 2016 Berdrigue BONGOLO BETO
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  while (*s1 && (*s1 == *s2)  && (n > 1 || n <= 0))
    {
      if (!(*s2))
	return (1);
      s1 = s1 + 1;
      s2 = s2 + 1;
      if (n > 1)
	n = n - 1;
    }
  if (!(*s1) && (*s2))
    return (-1);
  return (*s1 - *s2);
}
