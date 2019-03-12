/*
** my_printf.c for printf in /home/simon_w/Lib/printf
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Thu Feb 18 16:42:39 2016 Erwan Simon
** Last update Sun Feb 21 18:27:47 2016 Erwan Simon
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "alum1.h"

int		cutstr(char *s, int a, int nb)
{
  while (s[a] != '%' && a <= nb)
    {
      my_putchar(s[a]);
      a = a + 1;
    }
  return (a);
}

void		my_printf(char *s, ...)
{
  va_list	ap;
  int		a;
  int		nb;

  a = 0;
  va_start(ap, *s);
  nb = my_strlen(s) - 1;
  while (a <= nb)
    {
      a = cutstr(s, a, nb);
      if (s[a] == '%')
        {
          a = a + 1;
          flags(s[a], ap);
        }
      a = a + 1;
    }
  va_end(ap);
}

void		flags(char a, va_list ap)
{
  if (a == 's')
    {
      my_putstr(va_arg(ap, char*));
      return;
    }
  if (a == 'i' || a == 'd')
    {
      my_putnbr(va_arg(ap, int));
      return;
    }
}
