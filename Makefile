CFLAGS = -Wall -Wextra -Werror -g
CC = cc $(CFLAGS)
RM = rm -rf
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

HEADER = minitalk.h

CL_NAME = client
SV_NAME = server

CL_SOURCES = mt_client.c \
		mt_client_utils/mt_client_tools.c
SV_SOURCES = mt_server.c \
		mt_server_utils/mt_server_tools.c 
CL_OBJECTS = $(CL_SOURCES:%.c=%.o)
SV_OBJECTS = $(SV_SOURCES:%.c=%.o)


%.o: %.c
	$(CC) -c $< -o $(<:%.c=%.o) -I$(LIBFT)

all: $(CL_NAME) $(SV_NAME)

$(CL_NAME): $(LIBFT) $(CL_OBJECTS)
	$(CC) -o $(CL_NAME) $(CL_OBJECTS) -L$(LIBFT_PATH) -lft

$(SV_NAME): $(LIBFT) $(SV_OBJECTS)
	$(CC) -o $(SV_NAME) $(SV_OBJECTS) -L$(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

clean: all
	$(RM) $(CL_OBJECTS) $(SV_OBJECTS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(CL_NAME) $(SV_NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re