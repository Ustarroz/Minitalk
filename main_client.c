/*
** main_client.c for minitalk in /home/voyevoda/rendu/systeme_unix/PSU_2015_minitalk
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Mon Feb  1 12:50:26 2016 Voyevoda
** Last update Wed Feb  3 16:28:07 2016 Voyevoda
*/

#define _BSD_SOURCE
#define _POSIX_SOURCE

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "./include/fonction.h"

int	send_binary(char **av)
{
  int	j;
  int	i;
  int	pid;

  j = 0;
  i = 0;
  pid = my_getnbr(av[1]);
  av[2][j]<<=1;
  while (av[2][j] != '\0')
    {
      while (i != 7)
	{
	  if ((av[2][i]%2) == 1)
	    kill(pid, SIGUSR2);
	  else
	    kill(pid, SIGUSR1);
	  usleep(100);
	  av[2][i]<<=1;
	  i++;
	}
      j++;
      i = 0;
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      my_pid();
      send_binary(av);
    }
  else
    my_putstr("error, waiting for [SERVER_PID] [MESSAGE]\n");
  return (0);
}
