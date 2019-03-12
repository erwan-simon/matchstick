/*
** allum1.c for allum1 in /home/simon_w/Prog_Elem/alum1/CPE_2015_Allum1
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Wed Feb 10 16:14:38 2016 Erwan Simon
** Last update Thu Feb 25 15:28:30 2016 Erwan Simon
*/
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "alum1.h"

char	**dup_my_array(char **array)
{
  if ((array[0] = my_strdup("*********\0")) == NULL)
    return (NULL);
  if ((array[1] = my_strdup("*   |   *\0")) == NULL)
    return (NULL);
  if ((array[2] = my_strdup("*  |||  *\0")) == NULL)
    return (NULL);
  if ((array[3] = my_strdup("* ||||| *\0")) == NULL)
    return (NULL);
  if ((array[4] = my_strdup("*|||||||*\0")) == NULL)
    return (NULL);
  if ((array[5] = my_strdup("*********\0")) == NULL)
    return (NULL);
  return (array);
}

char	**first_fill()
{
  char	**array;
  int	y;

  y = 0;
  if ((array = malloc(sizeof(char*) * 7)) == NULL)
    return (NULL);
  while (y != 6)
    {
      if ((array[y] = malloc(sizeof(char) * 10)) == NULL)
  	return (NULL);
      y++;
    }
  y = 0;
  if (dup_my_array(array) == NULL)
    return (NULL);
  return (array);
}

void	my_free(char **array)
{
  int	a;

  a = 0;
  while (a != 6)
    {
      free(array[a]);
      a++;
    }
  free(array);
}

int	main()
{
  char	**array;
  int	tour;

  tour = 0;
  srand(time(NULL));
  if ((array = first_fill()) == NULL)
    return (1);
  if (display(array, tour) == 0)
    return (1);
  tour = 1;
  while (1)
    {
      if (display(array, tour) == 0)
	return (1);
      if (how_many_left(array, tour) == NULL)
	{
	  my_free(array);
	  return (0);
	}
      tour = (tour == 1) ? 2 : 1;
    }
}
