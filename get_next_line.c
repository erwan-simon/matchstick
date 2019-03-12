/*
** get_next_line.c for get_next_line in /home/simon_w/Prog_Elem/get_next_line/CPE_2015_getnextline
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Sun Jan 17 17:02:59 2016 Erwan Simon
** Last update Tue Dec 19 15:29:31 2017 Erwan Simon
*/

#include "alum1.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*mallocat(char *blk, char *ret, int a, int pos)
{
  char	*final_line;
  int	b;

  b = 0;
  while ((ret != 0) && (ret[b] != '\0'))
    b++;
  if ((final_line = malloc(b + ((a + 1) - pos) + 1)) == 0)
    return (0);
  b = 0;
  while ((ret != 0) && (ret[b] != '\0'))
    {
      final_line[b] = ret[b];
      b++;
    }
  while (pos < (a + 1))
    {
      final_line[b] = blk[pos];
      if (final_line[b] == '\n')
        final_line[b] = '\0';
      b++;
      pos++;
    }
  final_line[b] = '\0';
  return (final_line);
}

t_var			declarations(t_static stat, t_var var)
{
  var.ret = 0;
  var.bol = 0;
  var.pos = stat.a;
  return (var);
}

char			*get_next_line(const int fd)
{
  t_var			var;
  static t_static	stat;

  var = declarations(stat, var);
  while (!var.bol)
    {
      if (stat.a == 0)
        {
      	  if ((stat.read_bit = read(fd, stat.blk, 1)) <= 0)
            return (0);
        }
      if ((stat.blk[stat.a] == '\n') || (stat.a == (stat.read_bit - 1)))
        {
          if ((var.ret = mallocat(stat.blk, var.ret, stat.a, var.pos)) == NULL)
            return (0);
        }
      if ((stat.blk[stat.a] == '\n') || ((stat.read_bit < 1) &&
					 (stat.a == (stat.read_bit - 1))))
      	var.bol = 1;
      if (stat.a == (stat.read_bit - 1))
	{
	  stat.a = -1;
	  var.pos = 0;
	}
      stat.a++;
    }
  return (var.ret);
}
