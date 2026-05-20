NAME    = libftprintf.a
CC      = cc 
CFLAGS  = -Wall -Wextra -Werror

TOOLS   = ./tools/ft_itoa.c \
		  ./tools/ft_putchar_fd.c \
		  ./tools/ft_putnbr_base.c \
		  ./tools/ft_putstr_fd.c \
		  ./tools/ft_strlen.c \
		  ./tools/ft_tools_printf.c \
		  ./tools/ft_unsitoa.c
PRINTF  = ft_printf.c

SRC     = $(TOOLS) $(PRINTF)

OBJ       = $(TOOLS:.c=.o) $(PRINTF:.c=.o)
HEADERS  = ./tools/tools.h \
		  ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: all

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re bonus
