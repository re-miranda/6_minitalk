CFLAGS = -Wall -Wextra -Werror -g
CC = cc $(CFLAGS)
RM = rm -rf
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

CL_NAME = client
SV_NAME = server
CL_SOURCES = mt_client.c \
		mt_client_utils/mt_client_tools.c
SV_SOURCES = mt_server.c \
		mt_server_utils/mt_server_tools.c 
CL_OBJECTS = $(CL_SOURCES:%.c=%.o)
SV_OBJECTS = $(SV_SOURCES:%.c=%.o)

CL_NAME_BONUS = $(CL_NAME)_bonus
SV_NAME_BONUS = $(SV_NAME)_bonus
CL_SOURCES_BONUS = mt_client_bonus.c \
		mt_client_utils/mt_client_tools_bonus.c
SV_SOURCES_BONUS = mt_server_bonus.c \
		mt_server_utils/mt_server_tools_bonus.c 
CL_OBJECTS_BONUS = $(CL_SOURCES_BONUS:%.c=%.o)
SV_OBJECTS_BONUS = $(SV_SOURCES_BONUS:%.c=%.o)

HEADER = minitalk.h
HEADER_BONUS = minitalk_bonus.h


%.o: %.c
	$(CC) -c $< -o $(<:%.c=%.o) -I$(LIBFT)

all: $(CL_NAME) $(SV_NAME) $(HEADER)

$(CL_NAME): $(LIBFT) $(CL_OBJECTS)
	$(CC) -o $(CL_NAME) $(CL_OBJECTS) -L$(LIBFT_PATH) -lft

$(SV_NAME): $(LIBFT) $(SV_OBJECTS)
	$(CC) -o $(SV_NAME) $(SV_OBJECTS) -L$(LIBFT_PATH) -lft

bonus: $(CL_NAME_BONUS) $(SV_NAME_BONUS) $(HEADER_BONUS)

$(CL_NAME_BONUS): $(LIBFT) $(CL_OBJECTS_BONUS)
	$(CC) -o $(CL_NAME_BONUS) $(CL_OBJECTS_BONUS) -L$(LIBFT_PATH) -lft

$(SV_NAME_BONUS): $(LIBFT) $(SV_OBJECTS_BONUS)
	$(CC) -o $(SV_NAME_BONUS) $(SV_OBJECTS_BONUS) -L$(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(CL_OBJECTS) $(SV_OBJECTS) $(CL_OBJECTS_BONUS) $(SV_OBJECTS_BONUS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(CL_NAME) $(SV_NAME) $(CL_NAME_BONUS) $(SV_NAME_BONUS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re