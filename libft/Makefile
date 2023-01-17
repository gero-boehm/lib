CC=cc
CFLAGS=-Wall -Wextra -Werror -I ../include
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
HEADERS=../include/libft.h

all: $(OBJ)
	ar -crs ../lib.a $^

%.o: %.c $(HEADERS) Makefile
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all bonus clean fclean re