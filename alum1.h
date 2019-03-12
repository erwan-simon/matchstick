/*
** alum1.h for alum1 in /home/simon_w/Prog_Elem/alum1/CPE_2015_Allum1
** 
** Made by Erwan Simon
** Login   <simon_w@epitech.net>
** 
** Started on  Thu Feb 18 15:28:22 2016 Erwan Simon
** Last update Thu Feb 25 16:29:18 2016 Erwan Simon
*/

#include <stdarg.h>

#ifndef ALUM1_H_
# define ALUM1_H_

typedef struct	s_return
{
  int		line;
  int		matches;
  int		error;
}		t_return;

typedef struct  s_var
{
  char          *ret;
  int           bol;
  int           pos;
}               t_var;

typedef struct  s_static
{
  char          blk[1];
  int           read_bit;
  int           a;
}               t_static;

char	*my_strdup(char *);
int	*how_many_left(char **, int);
void	flags(char, va_list);
char	*get_next_line(const int);
int	display(char **, int);
void	my_printf(char *, ...);
char	**remove_match(char **, int, int);
int	my_getnbr(char *);
int	my_putnbr(int);
void	my_putchar(char);
void	my_putstr(char *);
int	my_strlen(char *);
int	player_turn(char **);
void	ia_turn(char **);

#endif /* !ALUM1_H_ */
