NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
INC_DIR = includes

LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

MAIN_DIR = $(SRCS_DIR)/main
UTILS_DIR = $(SRCS_DIR)/utils
PARSE_DIR = $(SRCS_DIR)/parse
OPS_DIR = $(SRCS_DIR)/operations
SORT_DIR = $(SRCS_DIR)/sort
BENCH_DIR = $(SRCS_DIR)/bench

SRCS =	$(MAIN_DIR)/main.c \
		$(UTILS_DIR)/stack_utils.c \
		$(UTILS_DIR)/error.c \
		$(UTILS_DIR)/disorder.c \
		$(UTILS_DIR)/sort_utils_1.c \
		$(UTILS_DIR)/sort_utils_2.c \
		$(PARSE_DIR)/parser.c \
		$(PARSE_DIR)/parse_flags.c \
		$(PARSE_DIR)/parse_numbers.c \
		$(OPS_DIR)/swap.c \
		$(OPS_DIR)/push.c \
		$(OPS_DIR)/rotate.c \
		$(OPS_DIR)/reverse_rotate.c \
		$(SORT_DIR)/small.c \
		$(SORT_DIR)/simple.c \
		$(SORT_DIR)/medium.c \
		$(SORT_DIR)/complex.c \
		$(BENCH_DIR)/benchmarks.c

OBJS = $(SRCS:.c=.o)
HEADER = $(INC_DIR)/push_swap.h
INCLUDES = -I$(INC_DIR) -I$(LIB_DIR)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
