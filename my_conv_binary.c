/*
** my_conv_binary.c for my_printf in /home/ustarr_r/rendu/systeme_unix/PSU_2015_my_printf
** 
** Made by Ustarroz Robin
** Login   <ustarr_r@epitech.net>
** 
** Started on  Sat Nov 14 19:51:14 2015 Ustarroz Robin
** Last update Mon Nov 16 11:36:06 2015 Ustarroz Robin
*/
#include <stdarg.h>

int	my_put_nbr_binary(int nb)
{
  int   a;
  char  *c;

  a = 0;
  c = "01";
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(-nb);
    }
  if (nb > 0)
    {
      a = nb%2;
      nb = nb/2;
      my_put_nbr_binary(nb);
      my_putchar(c[a]);
    }
  return (0);
}

int	my_conv_binary(va_list ap)
{
  int   nb;

  nb = va_arg(ap, int);
  my_put_nbr_binary(nb);
}
