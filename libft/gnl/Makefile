# LIBS
NAME = libftgnl.a
LIBFT = ../libft.a

# LIBS PATH
NAME_PATH = ./
LIBFT_PATH = ../
HEADER_PATH = ./

# OTHERS
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

# FILES
SRC = get_next_line.c \
	get_next_line_utils.c \
	get_whole_file.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(HEADER_PATH) $< -o $(<:%.c=%.o)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME_PATH)
	mv ./libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
