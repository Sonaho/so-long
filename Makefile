NAME	= so_long

SRCS 	= so_long.c \
		src/hook_keys.c \
		src/open_files.c \
		src/validate_file.c \
		src/utils.c \
		src/graphics/manage_screen.c \
		src/validations.c \
		src/graphics/keywords.c \
		includes/get_next_line/get_next_line.c 

FRWORK	= -lmlx -framework OpenGL -framework AppKit 

CC		= gcc 

CFLAGS	= -Wall -Werror -Wextra 

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

LIBRARY	 = 	./includes/libft.a\
			./includes/libmlx.a
INCLUDE_D = ./includes

all: $(NAME)

$(NAME):  libs
	$(CC) $(CFLAGS) $(SRCS) $(LIBRARY) -L $(INCLUDE_D) $(FRWORK) -o ./bin/$(NAME)

libs: 
		$(MAKE) all -C ./includes/libft
		$(MAKE) all -C ./includes/minilibx_opengl/
		mv ./includes/libft/libft.a ./includes
		mv ./includes/minilibx_opengl/libmlx.a ./includes

clean:
		$(MAKE) clean -C ./includes/libft
		$(MAKE) clean -C ./includes/minilibx_opengl/
		$(RM) $(LIBRARY)
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./includes/libft
		$(RM) $(NAME)

re: fclean all
