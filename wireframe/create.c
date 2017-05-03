/*
** create.c for wireframe in /home/Rev/wireframe
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Dec	7 10:52:20 2016 Roméo Nahon
** Last update	Wed Dec	7 10:52:20 2016 Roméo Nahon
*/

#include <include/my.h>

void	quadrillage(BUFF, int line, int column, int** nb)
{
  t_create	all;
  int		i;

  all.col = column;
  all.li = line;
  all.y = 30;
  all.x = 100;
  all.tmp = line;
  all.nb = nb;
  i = -1;
  all.i = 0;
  all.j = 0;
  while (++i < line)
    {
      all = my_parallel_project(framebuffer, 200, all);
      all.x += 100;
    }
  free(nb);
}

t_create	rise_of_wire(int **nb, t_para v, BUFF, t_create all)
{
  int	equal;
  int	other_equal;

  all.nb = nb;
  if (all.j < all.li)
    {
      if (all.i < all.col)
	{
	  equal = nb[all.i][all.j] - nb[all.i + 1][all.j];
	  other_equal = nb[all.i][all.j] - nb[all.i][all.j + 1];
	  all = wire_to_sky(v, all, framebuffer);
	  all = wire_vertical(v, all, framebuffer, equal);
	  all = wire_horizontal(v, all, framebuffer, other_equal);
	}
      all.i += 1;
    }
  if (all.i == all.li)
    {
      all.j += 1;
      all.i = 0;
    }
  return (all);
}
t_create	wire_to_sky(t_para v, t_create all, BUFF)
{
  sfVector2i	from;
  sfVector2i	to;

  from = set_vector(v.x1, v.y1);
  to = set_vector(v.x1, v.y1 - (all.nb[all.i][all.j] * SIZE));
  all.y1 = v.y1 - (all.nb[all.i][all.j] * SIZE);
  my_draw_line(framebuffer, from, to, sfGreen);
  return (all);
}
t_create	wire_vertical(t_para v, t_create all, BUFF, int equal)
{
  sfVector2i	from;
  sfVector2i	to;

  if (all.i < all.col - 1)
    {
      from = set_vector(v.x1, v.y1 - (all.nb[all.i][all.j] * SIZE));
      to = set_vector(v.x1 - 70, all.y1 + (equal * SIZE) + 30);
      my_draw_line(framebuffer, from, to, sfBlue);
    }
  return (all);
}
t_create	wire_horizontal(t_para v, t_create all, BUFF, int other_equal)
{
  sfVector2i	from;
  sfVector2i	to;

  if (all.j < all.li - 1)
    {
      from = set_vector(v.x1, v.y1 - (all.nb[all.i][all.j] * SIZE));
      to = set_vector(v.x1 + 100, all.y1 + (other_equal * SIZE));
      my_draw_line(framebuffer, from, to, sfWhite);
    }
  return (all);
}
