NAME = minitalk

C_NAME = client

S_NAME = server

S_SRCS = server.c \

C_SRCS = client.c \

S_OBJS = $(S_SRCS:.c=.o)

C_OBJS = $(C_SRCS:.c=.o)

LIBFT = libft/libft.a \

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : lm cm sm

lm :
		@make -C libft

cm : $(C_OBJS)
			$(CC) $(CFLAGS) $(C_OBJS) $(LIBFT) -o $(C_NAME)

sm : $(S_OBJS)
			$(CC) $(CFLAGS) $(S_OBJS) $(LIBFT) -o $(S_NAME)

clean :
			$(RM) $(S_OBJS) $(C_OBJS)
			@make clean -C libft

fclean : clean
			$(RM) $(C_NAME) $(S_NAME)
			$(RM) $(LIBFT)

re : fclean all

.PHONY: all lm cm sm clean fclean re

