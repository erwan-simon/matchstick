/*
** sources.c for alum1 in /home/simon_w/Prog_Elem/alum1/CPE_2015_Allum1
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Mon Feb 15 16:00:56 2016 Erwan Simon
** Last update Thu Feb 25 17:43:40 2016 Erwan Simon
*/

#include <stdlib.h>
#include "alum1.h"

int	my_putnbr(int nb)
{
  int	s_nb;

  s_nb = 1;
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while ((nb / s_nb) >= 10)
    s_nb = s_nb * 10;
  while (s_nb > 0)
    {
      my_putchar((nb / s_nb) % 10 + '0');
      s_nb = s_nb / 10;
    }
  return (0);
}

char	*my_strdup(char *src)
{
  char	*str;
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (src[a] != 0)
    a = a + 1;
  if ((str = malloc(a)) == NULL)
    return (NULL);
  b = a;
  a = 0;
  while (a != b)
    {
      str[a] = src[a];
      a = a + 1;
    }
  return (str);
}

int	my_getnbr(char *str)
{
  int	a;
  int	nbr;

  nbr = 0;
  if (str[0] == '\0')
    return (-1);
  a = (str[0] == 45) ? 1 : 0;
  while (str[a] != '\0')
    {
      nbr = nbr + (str[a] - 48);
      if ((str[a] < '0' || str[a] > '9'))
	return (-1);
      if (str[a + 1] != '\0')
        nbr = nbr * 10;
      a++;
    }
  if (str[0] == 45 && nbr > 0)
    nbr = nbr * (-1);
  if (str[0] != 45 && nbr < 0)
    nbr = nbr * (-1);
  return (nbr);
}

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (*str)
    {
      str = str + 1;
      a = a + 1;
    }
  return (a);
}

int	my_power_rec(int nb, int power)
{
  if (power <= 0)
    {
      if (power == 0)
        return (1);
      else
        return (0);
    }
  else
    return (nb * my_power_rec(nb, power - 1));
}
