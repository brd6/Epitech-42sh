/*
** my_strcpy.c for my_strcpy in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 09:03:10 2015 berdrigue bongolo-beto
** Last update Fri Jun  3 20:18:12 2016 Berdrigue BONGOLO BETO
*/

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
