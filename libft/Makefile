# LIBS
NAME = libft.a
LIBFT = ./libft/libft.a
GNL = ./gnl/libftgnl.a
PRINTF = ./printf/libftprintf.a

# LIBS PATH
NAME_PATH = ./
LIBFT_PATH = ./libft
GNL_PATH = ./gnl
PRINTF_PATH = ./printf

# OTHERS
AR = ar -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(PRINTF)

$(GNL):
	make all -C $(GNL_PATH)
	cp $(GNL) $(NAME_PATH)
	$(RM) $(NAME)
	mv ./libftgnl.a $(NAME)

$(PRINTF):
	make all -C $(PRINTF_PATH)
	cp $(PRINTF) $(NAME_PATH)
	$(RM) $(NAME)
	mv ./libftprintf.a $(NAME)

$(LIBFT):
	make all -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME_PATH)

clean:
	make clean -C $(GNL_PATH)
	make clean -C $(PRINTF_PATH)
	make clean -C $(LIBFT_PATH)


fclean: clean
	make fclean -C $(GNL_PATH)
	make fclean -C $(PRINTF_PATH)
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
