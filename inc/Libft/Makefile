NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

# Files for each folder without .c extension
SRC_IS = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint
SRC_STR = ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr \
			ft_strnstr ft_strncmp ft_substr ft_strjoin ft_strtrim \
			ft_split ft_strmapi ft_striteri ft_strdup ft_strcmp
SRC_MEM = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr \
			ft_memcmp ft_calloc
SRC_TO = ft_atoi ft_toupper ft_tolower ft_itoa
SRC_PUT = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
SRC_LST = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
			ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
			ft_lstmap
SRC_PRINTF = ft_printf_utils ft_printf 
SRC_GNL = get_next_line_utils get_next_line
SRC_ADD = ft_count_line

# Adding the .c extension back to the file names
SRC_IS := $(addsuffix .c, $(SRC_IS))
SRC_STR := $(addsuffix .c, $(SRC_STR))
SRC_MEM := $(addsuffix .c, $(SRC_MEM))
SRC_TO := $(addsuffix .c, $(SRC_TO))
SRC_PUT := $(addsuffix .c, $(SRC_PUT))
SRC_LST := $(addsuffix .c, $(SRC_LST))
SRC_UTILS := $(addsuffix .c, $(SRC_UTILS))
SRC_GNL := $(addsuffix .c, $(SRC_GNL))
SRC_PRINTF := $(addsuffix .c, $(SRC_PRINTF))
SRC_ADD := $(addsuffix .c, $(SRC_ADD))

# Prefixing folder name to each file
SRCS_IS = $(addprefix $(SRC_DIR)/ft_is/, $(SRC_IS))
SRCS_STR = $(addprefix $(SRC_DIR)/ft_str/, $(SRC_STR))
SRCS_MEM = $(addprefix $(SRC_DIR)/ft_mem/, $(SRC_MEM))
SRCS_TO = $(addprefix $(SRC_DIR)/ft_to/, $(SRC_TO))
SRCS_PUT = $(addprefix $(SRC_DIR)/ft_put/, $(SRC_PUT))
SRCS_LST = $(addprefix $(SRC_DIR)/ft_lst/, $(SRC_LST))
SRCS_PRINTF = $(addprefix $(SRC_DIR)/ft_printf/, $(SRC_PRINTF))
SRCS_GNL = $(addprefix $(SRC_DIR)/ft_gnl/, $(SRC_GNL))
SRCS_ADD = $(addprefix $(SRC_DIR)/ft_add/, $(SRC_ADD))

# Merging all source files
SRCS = $(SRCS_IS) $(SRCS_STR) $(SRCS_MEM) $(SRCS_TO) $(SRCS_PUT) $(SRCS_LST) $(SRCS_UTILS) $(SRCS_GNL) $(SRCS_PRINTF) $(SRCS_ADD)
OBJS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re