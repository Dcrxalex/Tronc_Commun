NAME = push_swap
BONUSNAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTDIR = ./ft_printf_bench
PRINT = $(PRINTDIR)/libftprintf.a

GNLDIR = ./bonus/getNextLine
INC_DIR = ./bonus

SRCS = main.c choose_algo.c create_stack.c operations_ab.c \
	operations_combo.c operations.c simple_sort.c \
	./utils/clear_utils.c ./utils/flags_check.c ./utils/ft_split.c \
	./utils/utils.c ./utils/valid_utils.c ./utils/stack_utils.c \
	./complex/complex_calcul.c ./complex/complex_turn.c ./complex/complex_sort.c \
	./complex/complex_target.c
	
SRCSBONUS = ./bonus/checker.c ./bonus/checker_operations.c \
			 $(GNLDIR)/get_next_line_utils.c $(GNLDIR)/get_next_line.c \
			 create_stack.c ./utils/ft_split.c ./utils/clear_utils.c \
			 ./utils/valid_utils.c ./utils/flags_check.c \
			 ./utils/stack_utils.c operations_ab.c \
			 operations_combo.c operations.c

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)

all: $(PRINT) $(NAME)

$(PRINT):
	$(MAKE) -C $(PRINTDIR)

$(NAME): $(OBJS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTDIR) -lftprintf -o $(NAME)

bonus: $(BONUSNAME)

$(BONUSNAME): $(OBJSBONUS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(PRINTDIR) clean
	rm -f $(OBJS)
	rm -f $(OBJSBONUS)

fclean: clean
	$(MAKE) -C $(PRINTDIR) fclean
	rm -f $(NAME)
	rm -f $(BONUSNAME)

re: fclean all

.PHONY: all clean fclean re bonus