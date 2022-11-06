# LIBS
NAME = libftprintf.a
LIBFT = ../libft.a

# LIBS PATH
LIBFT_PATH = ../
HEADER_PATH = ./

# OTHERS
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

# FILES
SRC = ft_printf.c \
	_find_specification.c \
	_flag_precision.c \
	_flag_width.c \
	_types_part1.c \
	_types_part2.c \
	ft_uint_base_str.c \
	ft_uint_str.c \
	ft_sizet_base_str.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(HEADER_PATH) $< -o $(<:%.c=%.o)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) ./
	mv ./libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
