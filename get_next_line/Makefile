CC=cc
CFLAGS=-Wall -Wextra -Werror -I ../include
SRC=get_next_line.c get_next_line_utils.c
OBJ=$(SRC:.c=.o)
HEADERS=../include/get_next_line.h

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
