NAME = so_long

LIBFT 	= inc/Libft/libft.a
LIBMLX	= inc/MLX42

HEADERS	:= -I inc -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS =		src/solong.c \
		 	src/solong_utils.c \
			src/perso.c \
			src/check_map.c \
			src/create_map.c \
			src/check_map_utils.c \
			src/valid_path.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

all : libmlx $(NAME)
compil : libmlx
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C inc/Libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean :
	$(RM) $(OBJS)
	make clean -C inc/Libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C inc/Libft
	rm -f inc/MLX42/build/CMakeCache.txt

re : fclean all

.PHONY: all, clean, fclean, re, libmlx

.SILENT:
