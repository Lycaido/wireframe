/*
** count.c for wireframe in /home/Rev/wireframe
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Dec	6 18:22:37 2016 Roméo Nahon
** Last update	Tue Dec	6 18:22:37 2016 Roméo Nahon
*/

#include "include/my.h"

int	**count_value(char *buffer)
{
  int		**nb;
  char		*str;
  t_count	count;

  count.i = -1;
  count.r = 0;
  count.j = -1;
  nb = malloc(sizeof(int*) * my_strlen(buffer));
  nb[0] = malloc(sizeof(int) * my_strlen(buffer));
  nb = count_value_next(count, buffer, str, nb);
  return (nb);
}

int	**count_value_next(t_count count, char *buffer, char *str, int **nb)
{
  while (buffer[++count.i] != '\0')
    {
      if (buffer[count.i] >= '0' && buffer[count.i] <= '9')
	{
	  count.t = -1;
	  str = malloc(sizeof(char) * my_strlen(buffer));
	  while (buffer[count.i] >= '0' && buffer[count.i] <= '9')
	    str[++count.t] = buffer[count.i++];
	  str[++count.t] = 0;
	  nb[count.r][++count.j] = my_getnbr(str);
	  free(str);
	}
      if (buffer[count.i] == '\n')
	{
	  count.j = -1;
	  count.r += 1;
	  nb[count.r] = malloc(sizeof(int) * my_strlen(buffer));
	}
    }
  return (nb);
}

int	count_column(int **nb)
{
  int	i;

  i = 0;
  while (nb[0][i] != '\0')
    i += 1;
  return (i);
}
int	count_line(int **nb)
{
  int	i;

  i = 0;
  while (nb[i] != NULL)
    i += 1;
  i -= 1;
  return (i);
}
