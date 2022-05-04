NAME	= so_long

SRCS 	= main.c \
		source/key_hooks.c \
		source/validations/validate.c \
		source/validations/validate_file.c \
		source/validations/validate_map.c \
		source/system/clear.c \
		source/system/file_operations.c \
		source/system/errors.c \
		source/graphics/create_screen.c \
		source/graphics/destory_screen.c \
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
