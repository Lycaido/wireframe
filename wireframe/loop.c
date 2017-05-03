/*
** loop.c for wireframe in /home/Rev/wireframe
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Dec	3 13:49:27 2016 Roméo Nahon
** Last update	Sat Dec	3 13:49:27 2016 Roméo Nahon
*/

#include "include/my.h"

void	display(t_my_framebuffer *framebuffer)
{
  sfRenderWindow_clear(framebuffer->window, sfBlack);
  sfRenderWindow_drawSprite(FMV, framebuffer->sprite, NULL);
  sfRenderWindow_display(framebuffer->window);
}
void	event(t_my_framebuffer *framebuffer, int **nb)
{
  while (sfRenderWindow_pollEvent(framebuffer->window, &framebuffer->event))
    {
      if (FEKC == sfKeyEscape || framebuffer->event.type == sfEvtClosed)
	sfRenderWindow_close(framebuffer->window);
    }
}
void	loop(t_my_framebuffer *framebuffer, int **nb)
{
  while (sfRenderWindow_isOpen(framebuffer->window))
    {
      event(framebuffer, nb);
      display(framebuffer);
    }
  sfRenderWindow_destroy(framebuffer->window);
}
