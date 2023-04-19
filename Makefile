CC=cc
CFLAGS=-Wall -Wextra -Werror -I include -I internal
NAME=lib.a
SRC=$(wildcard libft/*.c) $(wildcard get_next_line/*.c) $(wildcard ft_printf/*.c)
OBJ=$(SRC:.c=.o)
HEADERS=$(wildcard include/*.h) $(wildcard internal/*.h)

DRY_RUN:=0
ifeq (n,$(findstring n,$(firstword $(MAKEFLAGS))))
	DRY_RUN := 1
endif

COLOR_BLUE:=\033[0;34m
COLOR_GREEN_LIGHT:=\033[1;32m
COLOR_BLUE_LIGHT:=\033[1;34m
COLOR_PURPLE_LIGHT:=\033[1;35m
COLOR_CYAN_LIGHT:=\033[1;36m
COLOR_RESET:=\033[0m
CLEAR_LINE:=\033[F\033[K


NUM_TASKS_PENDING:=0
NUM_TASKS_COMPLETED:=0

define printc
	$(if $(filter 0,$(DRY_RUN)), @printf $1)
endef

define make_progress
	$(eval NUM_TASKS_COMPLETED := $(shell expr $(NUM_TASKS_COMPLETED) + 1))
	$(eval progress := $(shell expr $(NUM_TASKS_COMPLETED) \* 100 / $(NUM_TASKS_PENDING) - 1))
	$(eval blank := $(shell expr 99 - $(progress)))
	$(call printc,"$(CLEAR_LINE) $(COLOR_BLUE_LIGHT)$(shell printf %3d $(progress))%% $(COLOR_BLUE)[$(shell printf %$(progress)s | tr ' ' '=')>$(shell printf %$(blank)s)]$(COLOR_RESET)\n")
endef

define cleanup
	$(call printc,"$(CLEAR_LINE)$(CLEAR_LINE)$(COLOR_CYAN_LIGHT)Lib compiled.$(COLOR_RESET)\n")
endef

ifdef DEBUG
	CFLAGS += -g
endif

all: init $(NAME)

%.o: %.c $(HEADERS) Makefile
	@$(CC) -c $(CFLAGS) -o $@ $<
	$(if $(filter 0,$(DRY_RUN)), $(call make_progress))

init:
	$(if $(filter 0,$(DRY_RUN)), $(eval NUM_TASKS_PENDING := $(shell make -n | wc -l)))
	$(if $(filter 0,$(DRY_RUN)), $(if $(filter 1,$(NUM_TASKS_PENDING)), @printf "$(COLOR_GREEN_LIGHT)Lib already compiled.$(COLOR_RESET)\n", @printf "$(COLOR_PURPLE_LIGHT)Compiling lib..$(COLOR_RESET)\n\n"))

$(NAME): $(OBJ)
	@ar -crs $@ $^
	$(if $(filter 0,$(DRY_RUN)), $(call cleanup))

clean:
	@rm -f $(OBJ)
	@printf "$(COLOR_GREEN_LIGHT)Cleaned up object files.$(COLOR_RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(COLOR_GREEN_LIGHT)Cleaned up archive.$(COLOR_RESET)\n"

re: fclean all

compile: $(OBJ) main.o
	@$(CC) $(CFLAGS) $^
	$(if $(filter 0,$(DRY_RUN)), $(call cleanup))

test: compile
	./a.out

tclean: clean
	@rm -f a.out
	@printf "$(COLOR_GREEN_LIGHT)Cleaned up executable.$(COLOR_RESET)\n"

norm:
	norminette $(SRC) $(HEADERS)

.PHONY:
	all bonus clean fclean re compile test tclean norm init