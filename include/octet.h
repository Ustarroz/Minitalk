/*
** octet.h for minitalk in /home/voyevoda/rendu/systeme_unix/PSU_2015_minitalk/include
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Tue Feb  2 13:40:03 2016 Voyevoda
** Last update Tue Feb  2 13:41:39 2016 Voyevoda
*/

#ifndef OCTET_H_
#define OCTET_H_

typedef union
{
  unsigned char octet;

  struct {
    byte bit0         :1;
    byte bit1         :1;
    byte bit2         :1;
    byte bit3         :1;
    byte bit4         :1;
    byte bit5         :1;
    byte bit6         :1;
    byte bit7         :1;
  } Bits;

} octetdecompose;
