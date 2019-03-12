/*
** allum1_4.c for allum1 in /home/simon_w/Prog_Elem/alum1/CPE_2015_Allum1
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Thu Feb 25 16:03:16 2016 Erwan Simon
** Last update Thu Feb 25 16:03:51 2016 Erwan Simon
*/

#include <stdlib.h>
#include <unistd.h>
#include "alum1.h"

int	display(char **array, int tour)
{
  int	y;

  y = 0;
  if (tour == 1)
    {
      my_printf("Your turn:\n");
      if (player_turn(array) == 0)
	return (0);
    }
  if (tour == 2)
    {
      my_printf("AI's turn...\n");
      ia_turn(array);
    }
  while (y != 6)
    {
      my_printf("%s\n", array[y]);
      y++;
    }
  how_many_left(array, 3);
  return (1);
}
