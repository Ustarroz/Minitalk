/*
** main_server.c for minitalk in /home/voyevoda/rendu/systeme_unix/PSU_2015_minitalk
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Mon Feb  1 12:51:00 2016 Voyevoda
** Last update Wed Feb  3 16:27:08 2016 Voyevoda
*/

#define _BSD_SOURCE
#define _POSIX_SOURCE

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "./include/fonction.h"

void			receive(int signum)
{
  static unsigned char	k = '\0';
  static int		i = 0;
  int			b;

  if (signum == SIGUSR1)
    {
      k<<=1;
      i++;
    }
  if (signum == SIGUSR2)
  {
    b = 00000001;
    k = k | b;
    k<<=1;
    i++;
  }
if (i == 8)
  {
    my_putchar(k);
    i = 0;
    k = '\0';
  }
}

int	main(int ac, char **av)
{
  int	i;

  (void) ac;
  (void) av;
  i = 0;
  my_pid();

  if (signal(SIGUSR1, receive))
    {
      my_putchar('a');
      i++;
    }
  if (signal(SIGUSR2, receive))
    {
      my_putchar('b');
      i++;
    }
  while (1)
    {
    }
  return (0);
}
