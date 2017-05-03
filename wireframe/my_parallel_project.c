/*
** my_parallel_projection->c for wireframe in /home/Rev/wireframe/src
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech->net>
** 
** Started on	Mon Dec	5 10:05:22 2016 Roméo Nahon
** Last update	Mon Dec	5 10:05:22 2016 Roméo Nahon
*/

#include "include/my.h"

t_para	init_value(t_para v, t_create all)
{
  v.nx = 950;
  v.ny = 450;
  v.mx = all.col;
  v.my = all.li;
  v.dx = all.x;
  v.dy = all.y;
  v.x = 0;
  v.y = 0;
  return (v);
}
t_create	my_parallel_project(BUFF, float angle, t_create all)
{
  t_para	v;

  v = init_value(v, all);
  while (v.x++ < v.mx)
    {
      while (v.y++ < v.my)
	{
	  v.x1 = v.nx + v.x * v.dx + v.y  * framebuffer->angle;
	  v.x2 = v.nx + (v.x - 1) * v.dx + v.y * framebuffer->angle;
	  v.x3 = v.nx + v.x * v.dx + (v.y - 1) * framebuffer->angle;
	  v.y1 = v.ny + v.y * v.dy;
	  v.y2 = v.ny + (v.y - 1) * v.dy;
	  v.fromx = set_vector(v.x1, v.y1);
	  v.toy = set_vector(v.x2 + 100, v.y1);
	  v.toy2 = set_vector(v.x3 - 70, v.y2 + 30);
	  if (v.y <= v.mx)
	    my_draw_line(framebuffer, v.fromx, v.toy, sfRed);
	  v.fromx = set_vector(v.x1 - 70, v.y1 + 30);
	  if (v.y < v.mx)
	    my_draw_line(framebuffer, v.fromx, v.toy2, sfRed);
	  all = rise_of_wire(all.nb, v, framebuffer, all);
	}
    }
  return (all);
}
