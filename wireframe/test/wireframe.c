/*
** wireframe.c for wireframe in /home/Rev/wireframe
**
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
**
** Started on	Sat Dec	3 16:10:26 2016 Roméo Nahon
** Last update	Sat Dec	3 16:10:26 2016 Roméo Nahon
*/

#include "include/my.h"

int	main(int ac, char **av)
{
  t_my_framebuffer	framebuffer;
  int			fd;
  char			buffer[1000000];
  int			**nb;

  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    return (84);
  read(fd, buffer, 999999);
  framebuffer.angle = -70;
  nb = count_value(buffer);
  init(&framebuffer, buffer, nb);
  loop(&framebuffer, nb);
  close(fd);
  return (0);
}
