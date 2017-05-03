/*
** my.h for bootstrap in /home/Rev/CSFML/bootstrap
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Nov	10 10:15:08 2016 Roméo Nahon
** Last update	Thu Nov	10 10:15:08 2016 Roméo Nahon
*/

#ifndef MY_H
# define MY_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF 		t_my_framebuffer *framebuffer
#define S_WIDTH 	1920
#define S_HEIGHT 	1080
#define SIZE 		15
#define FM 			framebuffer->mode
#define FMV 		framebuffer->window
#define FT			framebuffer->texture
#define FP 			framebuffer->pixels
#define FW 			framebuffer->width
#define FH 			framebuffer->height
#define FEKC		framebuffer->event.key.code
#define ABS			(Value)	(((Value) < (0)) ? -(Value) : (Value))

void 	my_printf(char *str, ...);
int 	my_getnbr(char *str);
int 	count_column(int **nb);
int 	count_line(int **nb);
int 	my_strlen(char *str);

typedef struct 		s_my_framebuffer
{
	sfRenderWindow* window;
	sfVideoMode     mode;
	sfTexture* 		texture;
	sfSprite* 		sprite;
	sfUint8* 		pixels;
	sfEvent  		event;
	int 			width;
	int 			height;
	float 			angle;
} 					t_my_framebuffer;

typedef struct 		s_line
{
	int 			dx;
	int 			dy;
	int 			xinc;
	int 			yinc;
	int 			i;
	int 			cumul;
	int 			x;
	int 			y;
} 					t_line;

typedef struct 		s_count
{
	int 			i;
	int 			r;
	int 			t;
	int 			j;
} 					t_count;

typedef struct 		s_create
{
	int 			x;
	int 			y;
	int 			x1;
	int 			y1;
	int 			tmp;
	int 			col;
	int 			li;
	int 			**nb;
	char 			*buff;
	int 			i;
	int 			j;
	int 			angle;
} 					t_create;

typedef struct 		s_para
{
	sfVector2i 		to;
	sfVector2i 		from;
	sfVector2i 		to2;
	sfVector2i		fromx;
	sfVector2i 		toy2;
	sfVector2i		toy;
	int 			x;
	int 			y;
	int 			x1;
	int 			x2;
	int				x3;
	int				y1;
	int 			y2;
	int 			nx;
	int 			ny;
	int 			mx;
	int 			my;
	int 			dx;
	int 			dy;
	int 			lol;
} 					t_para;

t_create 		wire_horizontal(t_para v, t_create all, BUFF, int other_equal);
t_create		wire_vertical(t_para v, t_create all, BUFF, int equal);
t_create		wire_to_sky(t_para v, t_create all, BUFF);
t_create 		rise_of_wire(int **nb, t_para v, BUFF, t_create);
t_para			init_value(t_para v, t_create all);
void 			quadrillage(BUFF, int, int, int**);
sfVector2i 		my_parallel_projection(sfVector3f, float);
sfVector2i 		my_isometric_projection(sfVector3f);
t_create		my_parallel_project(BUFF, float angle, t_create);
t_create		*create_column(int col, int li, BUFF);
t_create		*create_line(int li, BUFF);
void 			create_quadri(int column, int line, t_my_framebuffer *framebuffer);
int				**count_value_next(t_count count, char *buffer, char *str, int **nb);
int 			**count_value(char *buffer);
void			wireframe(BUFF, char  *buffer);
sfVector2i		set_vector(int x, int y);
void			line_dx_sup(t_line line, BUFF, sfColor color);
void			line_dx_inf(t_line line, BUFF, sfColor color);
int				init(t_my_framebuffer *framebuffer, char *buffer, int **nb);
void			my_draw_line(BUFF, 
							sfVector2i from, 
							sfVector2i to, 
							sfColor color);
void			loop(t_my_framebuffer *framebuffer, int**);
void 			event(t_my_framebuffer *framebuffer, int**);
void			display(t_my_framebuffer *framebuffer);
void			my_put_pixel(BUFF, int x, int y, sfColor color) ;
sfUint8*		create_pixel_buffer(t_my_framebuffer *framebuffer);

#endif /* MY_H */