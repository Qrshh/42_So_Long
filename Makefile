NAME = JEU

LIBFT 	= inc/Libft/libft.a
LIBMLX	= inc/MLX42

HEADERS	:= -I inc -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS =		src/So_Long.c \
		 	src/So_Long_utils.c \
			src/personnage.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

all : $(NAME)
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
	@rm -rf
	make clean -C inc/Libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C inc/Libft



re : fclean all

.PHONY: all, clean, fclean, re, libmlx