/*
** fct2.c for minitalk in /home/voyevoda/rendu/systeme_unix/PSU_2015_minitalk
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Mon Feb  1 20:14:32 2016 Voyevoda
** Last update Tue Feb  2 13:53:13 2016 Voyevoda
*/
#include "./include/fonction.h"

char	*my_revstr(char *str)
{
  int   i;
  int   y;
  int   a;

  a = 0;
  i = 0;
  y = my_strlen(str) - 1;
  while (i < y)
    {
      a = str[i];
      str[i++] = str[y];
      str[y--] = a;
    }
  return (str);
}
