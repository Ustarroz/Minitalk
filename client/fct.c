/*
** fct.c for minitalk in /home/voyevoda/rendu/systeme_unix/PSU_2015_minitalk
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Mon Feb  1 20:03:25 2016 Voyevoda
** Last update Tue Feb  9 11:03:27 2016 Voyevoda
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/fonction.h"

void    my_putchar(unsigned char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void    my_pid()
{
  pid_t pid;

  pid = getpid();
  my_putnbr(pid);
  my_putchar('\n');
}

void    my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  while (nb > 9)
    {
      my_putnbr(nb / 10);
      nb = nb % 10;
    }
  nb += 48;
  my_putchar(nb);
}
