NAME = JEU

LIBFT = ./inc/Libft/libft.a
LIBMLX	:= ./inc/MLX42

HEADERS	:= -I $(LIBMLX)/include/MLX42
SRCS =	./src/So_Long.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

all : libmlx $(NAME)
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME) $(LIBFT)


$(LIBFT):
	@make -C ./inc/Libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean :
	$(RM) $(OBJS)
	@rm -rf $(LIBMLX)/build
	make clean -C ./inc/Libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C ./inc/Libft

re : fclean all

.PHONY: all, clean, fclean, re, libmlx