/*
** allum1_2.c for allum1 in /home/simon_w/Prog_Elem/alum1/CPE_2015_Allum1
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Fri Feb 19 16:21:06 2016 Erwan Simon
** Last update Thu Feb 25 15:41:30 2016 Erwan Simon
*/

#include <stdlib.h>
#include <unistd.h>
#include "alum1.h"

void	my_putchar(char	c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a++;
    }
}

int	*win_or_lose(int tour, int a, int *number)
{
  if (tour == 1 && a == 4)
    {
      my_printf("You lost, too bad..\n");
      return (NULL);
    }
  if (tour == 2 && a == 4)
    {
      my_printf("I lost.. snif.. but I'll get you next time!!\n");
      return (NULL);
    }
  if (tour == 3 && a != 4)
    {
      my_printf("\n");
      return (number);
    }
  return (number);
}

int	*how_many_left(char **array, int tour)
{
  int	y;
  int	x;
  int	*number;
  int	a;

  y = 1;
  x = 1;
  a = 0;
  number = malloc(sizeof(int) * 4);
  while (y != 5)
    {
      while (x != 8)
	{
	  if (array[y][x] == '|')
	    number[y - 1]++;
	  x++;
	}
      if (number[y - 1] == 0)
	a++;
      x = 1;
      y++;
    }
  return (win_or_lose(tour, a, number));
}

char	**remove_match(char **array, int line, int match)
{
  int	a;

  a = 7;
  while (match != 0)
    {
      if (array[line][a] == '|')
	{
	  array[line][a] = ' ';
	  match--;
	}
      a--;
    }
  return (array);
}
