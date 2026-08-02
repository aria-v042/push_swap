NAME = push_swap
ROOT = .

LIB_DIR = $(ROOT)/libft
LIB = $(LIB_DIR)/libft.a

SRCS = $(shell find $(ROOT) -maxdepth 1 -name '*.c')
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(ROOT) -I$(LIB_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
