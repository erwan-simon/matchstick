/*
** allum1_3.c for allum1 in /home/simon_w/Prog_Elem/alum1/CPE_2015_Allum1
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Fri Feb 19 16:27:06 2016 Erwan Simon
** Last update Thu Feb 25 17:27:11 2016 Erwan Simon
*/

#include <stdlib.h>
#include <unistd.h>
#include "alum1.h"

int	error_line(int line, char **array)
{
  int	*number_left;

  number_left = how_many_left(array, 0);
  if (line == 0 || line > 4)
    {
      my_printf("Error: this line is out of range\n");
      return (0);
    }
  if (line < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (0);
    }
 if (number_left[line - 1] == 0)
    {
      my_printf("Error: this line is empty\n");
      return (0);
    }
  return (1);
}

int	error_matches(int line, int matches, char **array)
{
  int	*number_left;

  number_left = how_many_left(array, 0);
  if (matches == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      return (0);
    }
  if (matches < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (matches > number_left[line - 1])
    {
      my_printf("Error: not enough matches on this line\n");
      return (0);
    }
  return (1);
}

void	ia_turn(char **array)
{
  int	line;
  int	match;
  int	*number_left;
  int	boleene;

  match = 1;
  boleene = 1;
  line = 0;
  number_left = how_many_left(array, 0);
  while (boleene)
    {
      line = (rand() % 4) + 1;
      if (number_left[line - 1] > 0)
	{
	  boleene = 0;
	  remove_match(array, line, match);
	}
    }
  my_printf("AI removed %d match(es) from line %d\n", match, line);
}

t_return	test_if_error(char **array, t_return player)
{
  char	*str;

  while (!player.error)
    {
      player.line = 0;
      my_printf("Line: ");
      if ((str = get_next_line(0)) == NULL)
	{
	  player.error = (-1);
	  return (player);
	}
      player.line = my_getnbr(str);
      player.error = error_line(player.line, array);
    }
  player.error = 0;
  player.matches = 0;
  my_printf("Matches: ");
  if ((str = get_next_line(0)) == NULL)
    {
      player.error = (-1);
      return (player);
    }
  player.matches = my_getnbr(str);
  player.error = error_matches(player.line, player.matches, array);
  return (player);
}

int		player_turn(char **array)
{
  t_return	player;

  player.error = 0;
  while (!player.error)
    {
      player = test_if_error(array, player);
      if (player.error == (-1))
	return (0);
    }
  my_printf("Player removed %d match(es)", player.matches);
  my_printf(" from line %d\n", player.line);
  remove_match(array, player.line, player.matches);
  return (1);
}
