/*
** main_client.c for minitalk in /home/voyevoda/rendu/systeme_unix/PSU_2015_minitalk
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Mon Feb  1 12:50:26 2016 Voyevoda
** Last update Thu Feb  4 17:30:30 2016 Voyevoda
*/

#define _BSD_SOURCE
#define _POSIX_SOURCE

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "./include/fonction.h"

int		recursive(unsigned char av, int pid, int i)
{
  if (i < 8)
    {
      recursive (av >> 1, pid, i + 1);
      if ((av % 2) == 1)
	kill(pid, SIGUSR2);
      else
	kill(pid, SIGUSR1);
      usleep(10);
    }
  return (0);
}

int	send_binary(char **av)
{
  int	pid;
  int	j;
  int	i;

  i = 0;
  j = 0;
  pid = my_getnbr(av[1]);
  while (av[2][j] != '\0')
    {
      recursive(av[2][j], pid, i);
      j++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    send_binary(av);
  else
    my_putstr("error, expected [SERVER_PID] [MESSAGE]\n");
  return (0);
}
