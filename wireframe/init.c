/*
** init.c for wireframe in /home/Rev/wireframe
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
**
** Started on	Sat Dec	3 14:19:08 2016 Roméo Nahon
** Last update	Sat Dec	3 14:19:08 2016 Roméo Nahon
*/

#include "include/my.h"

sfUint8*	create_pixel_buffer(t_my_framebuffer *framebuffer)
{
  int		i;
  sfUint8	*pixels;

  framebuffer->width = S_WIDTH;
  framebuffer->height = S_HEIGHT;
  pixels = malloc(FW * FH * 4 * sizeof(*pixels));
  i = 0;
  if (pixels == NULL)
    return (NULL);
  while (i < framebuffer->width * framebuffer->height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}

int	init(t_my_framebuffer *framebuffer, char *buffer, int **nb)
{
  framebuffer->mode.width = S_WIDTH;
  framebuffer->mode.height = S_HEIGHT;
  framebuffer->mode.bitsPerPixel = 32;
  FMV = sfRenderWindow_create(FM, "wireframe", sfResize | sfClose, NULL);
  if (framebuffer->window == NULL)
    return (-1);
  framebuffer->sprite = sfSprite_create();
  framebuffer->texture = sfTexture_create(S_WIDTH, S_HEIGHT);
  framebuffer->pixels = create_pixel_buffer(framebuffer);
  sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
  quadrillage(framebuffer , count_column(nb), count_line(nb), nb);
  sfTexture_updateFromPixels(FT, FP, S_WIDTH, S_HEIGHT, 0, 0);
  return (0);
}

sfVector2i	set_vector(int x, int y)
{
  sfVector2i	set;

  set.x = x;
  set.y = y;
  return (set);
}
