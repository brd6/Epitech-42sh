/*
** my_nbr_len.c for my_nbr_len in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 30 13:02:50 2015 berdrigue bongolo-beto
** Last update Mon Dec 28 12:57:24 2015 berdrigue bongolo-beto
*/

int	my_nbr_len(int nbr)
{
  int	i;

  i = !nbr;
  while (nbr)
    {
      nbr = nbr / 10;
      i = i + 1;
    }
  return (i);
}
