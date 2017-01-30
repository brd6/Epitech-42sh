/*
** my_str_isalphanum.c for my_str_isalphanum in /home/bongol_b/rendu/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jan 14 20:06:15 2016 Berdrigue BONGOLO BETO
** Last update Thu Jan 14 20:06:48 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"

int	my_str_isalphanum(char *str)
{
  while (*str && (is_alpha(*str) || is_num(*str)))
      str = str + 1;
  return (!(*str));
}
