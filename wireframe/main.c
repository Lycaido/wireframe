/*
** main.c for main in /home/Rev/wireframe
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Wed Dec 14 10:33:32 2016 Roméo Nahon
** Last update Wed Dec 14 10:41:44 2016 Roméo Nahon
*/

#include "include/my.h"

int     main(int ac, char **av)                                                                                      
{                                                                                                                    
  t_my_framebuffer      framebuffer;                                                                                 
  int                   fd;                                                                                          
  char                  buffer[1000000];                                                                             
  int                   **nb;                                                                                        
                                                                                                                     
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


