CC=cc
CFLAGS=-Wall -Wextra -Werror -I include -I internal
NAME=lib.a
SRC=$(wildcard libft/*.c) $(wildcard get_next_line/*.c) $(wildcard ft_printf/*.c)
OBJ=$(SRC:.c=.o)
HEADERS=$(wildcard include/*.h) $(wildcard internal/*.h)

ifdef DEBUG
	CFLAGS += -g
endif

all: $(NAME)

%.o: %.c $(HEADERS) Makefile
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJ)
	ar -crs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

compile: $(OBJ) main.o
	$(CC) $(CFLAGS) $^

test: compile
	./a.out

tclean: clean
	rm -f a.out

norm:
	norminette $(SRC) $(HEADERS)

.PHONY:
	all bonus clean fclean re compile test tclean norm