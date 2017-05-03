##
## Makefile for bootstrap in /home/Rev/CSFML/bootstrap
## 
## Made by Roméo Nahon
## Login	 <Rev@epitech.net>
## 
## Started on	Thu Nov	10 12:12:07 2016 Roméo Nahon
## Last update	Thu Nov	10 12:12:07 2016 Roméo Nahon
##

SRC = 		init.c 				\
			loop.c 				\
			src/my_put_pixel.c 	\
			src/my_draw_line.c 	\
			src/my_parallel_projection.c \
			src/my_isometric_projection.c \
			my_parallel_project.c 			\
			create.c 			\
			count.c 			\
			main.c				

OBJ = $(SRC:.c=.o)

NAME = wireframe

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra $(OBJ) -lcsfml-window -lcsfml-graphics -lc_graph_prog -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

val: $(SRC)
	gcc -g3 $(SRC) -lcsfml-window -lcsfml-graphics -lc_graph_prog -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re: fclean all
